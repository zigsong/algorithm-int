# 24. 구간 트리

### 구간 트리

특정 구간에 대한 계산의 결과를 노드에 각각 저장

저장된 자료들을 적절히 **전처리**해 특정 구간에 대한 질의들을 **빠르게 대답**할 수 있도록

ex) 구간 원소들의 합, 곱, 최댓값, 최솟값

아래는 구간 합을 저장한 구간 트리의 예시

![Crocus](https://t1.daumcdn.net/cfile/tistory/27115D3758BF26C532)

### 구간 트리의 초기화

구간 최소 쿼리(RMQ) 문제는 가장 대표적인 예

초기화 과정에는 각 노드의 수와 같은 시간이 걸림 O(n)

```c++
// 24.1 배열의 구간 최소 쿼리(RMQ) 문제를 해결하는 구간 트리의 초기화

// 배열의 구간 최소 쿼리를 해결하기 위한 구간 트리의 구현
struct RMQ {
    // 배열의 길이
    int n;
    // 각 구간의 최소치
    vector<int> rangeMin;
    RMQ(const vector<int>& array) {
        n = array.size();
        // 모든 경우에 우리가 필요로 하는 배열의 크기보다 크다
        rangeMin.resize(n * 4);
        init(array, 0, n-1, 1);
    }
    // node 노드가 array[left .. right] 배열을 표현할 때,
    // node 를 루트로 하는 서브트리를 초기화하고, 이 구간의 최소치를 반환한다.
    
    // 현재 구간을 두 개로 나눠 재귀 호출한 뒤, 두 구간의 최소치 중 더 작은 값을 선택, 해당 구간의 최소치를 구한다.
    int init(const vector<int>& array, int left, int right, int node) {
        if(left == right)
            return rangeMin[node] = array[left];
        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid, node * 2);
        int rightMin = init(array, mid + 1, right, node * 2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }
};
```

```c++
// 24.2 RMQ 문제를 푸는 구간 트리에서 질의 연산의 구현, 시간 복잡도는 O(lgN)

const int INT_MAX = numeric_limits<int>::max();
struct RMQ {
    // node 가 표현하는 번위 array[nodeLeft..nodeRight] 가 주어질 때
    // 이 범위와 array[left..right] 의 교집합의 최소치를 구한다.
    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        // 두 구간이 겹치지 않으면 아주 큰 값을 반환한다 -> 나중에 무시됨
        if(right < nodeLeft || nodeRight < left) return INT_MAX;
        // node 가 표현하는 범위가 array[left..right] 에 완전히 포함되는 경우
        if(left <= nodeLeft && nodeRight <= right)
		// if(nodeLeft <= left && right <= nodeRight)
            return rangeMin[node];
        // 양쪽 구간을 나눠서 푼 뒤 결과를 합친다.
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node*2, nodeLeft, mid), 
                   query(left, right, node*2+1, mid+1, nodeRight));
    }
    // query() 를 외부에서 호출하기 위한 인터페이스
    int query(int left, int right) {
        return query(left, right, 1, 0, n-1);
    }
};
```



```c++
// 24.3 RMQ 문제를 푸는 구간 트리에서 갱신 연산의 구현

struct RMQ {
    // ... 생략 ...
    // array[index]=newValue 로 바뀌었을 때, node를 루트로 하는
    // 구간 트리를 갱신하고 노드가 표현하는 구간의 최소치를 반환한다.
    int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
        // index가 노드가 표현하는 구간과 상관없는 경우엔 무시한다.
        if(index < nodeLeft || nodeRight < index)
            return rangeMin[node];
        // 트리의 리프까지 내려온 경우
        if(nodeLeft == nodeRight) return rangeMin[node] = newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeMin[node] = min(  // rangeMin[1-9]
            update(index, newValue, node*2, nodeLeft, mid), // rangeMin[1-4]
            update(index, newValue, node*2+1, mid+1, nodeRight)); // rangeMin[5-9]
    }
    // update() 를 외부에서 호출하기 위한 인터페이스
    int update(int index, int newValue) {
        return update(index, newValue, 1, 0, n-1);
    }
};
```

2 2 2

2 2 3

6 

1 1 1 2 2

2 2 3 3 3

```c++
// 24.4 숫자의 최대 출현 회수 문제의 두 개의 답을 합치기

// 부분 구간의 계산 결과
struct RangeResult {
    // 이 구간의 크기
    int size;
    // 가장 자주 등장하는 숫자의 출현 횟수
    int mostFrequent;
    // 왼쪽 끝 숫자와 왼쪽 끝 숫자의 출현 횟수
    int leftNumber, leftFreq;
    // 오른쪽 끝 숫자와 오른쪽 끝 숫자의 출현 횟수
    int rightNumber, rightFreq;
};

// 왼쪽 부분 구간의 계산 결과 a, 오른쪽 부분 구간의 계산결과 b를 합친다.
RangeResult merge(const RangeResult& a, const RangeResult& b) {
    RangeResult ret;
    // 구간의 크기는 쉽게 계산 가능
    ret.size = a.size + b.size;
    
    // 왼쪽 숫자는 a.leftNumber로 정해져있다.
    // 왼쪽 부분 구간이 전부 a.leftNumber인 경우만 별도로 처리
    // 예: [1,1,1,1] 과 [1,2,2,2] 를 합칠 때
    ret.leftNumber = a.leftNumber;
    ret.leftFreq = a.leftFreq;
    if(a.size == a.leftFreq && a.leftNumber == b.leftNumber)
        ret.leftFreq += b.leftFreq;
    
    // 오른쪽 끝 숫자도 비슷하게 계산
    ret.rightNumber = b.rightNumber;
    ret.rightFreq = b.rightFreq;
    if(b.size == b.rightFreq && a.rightNumber == b.rightNumber)
        ret.rightFreq += a.rightFreq;
    
    // 가장 많이 출현하는 수의 빈도수는 둘 중 큰 쪽으로
    // 두 수를 합쳤을 때 mostFrequent 보다 커지는지 확인한다.
    ret.mostFrequent = max(a.mostFrequent, b.mostFrequent);
    if(a.rightNumber == b.leftNumber)
        ret.mostFrequent = max(ret.mostFrequent, a.rightFreq + b.leftFreq);
    return ret;
}
```



24.3 등산로 문제도 위를 이용해서 풀자



-- 난이도 상 스킵 --



### 펜윅 트리

![펜윅 트리(Fenwick Tree, Binary Indexed Tree, BIT)](https://greeksharifa.github.io/public/img/Algorithm_and_Data_Structure/2018-07-09-algorithm-fenwick-tree/03_FenwickTree2.jpg)



```c++
// 24.7 펜윅 트리의 완전한 구현

// 펜윅 트리의 구현. 가상의 배열 A[] 의 부분 합을 빠르게 구현할 수 있도록 한다.
// 초기화시에는 A[]의 원소가 전부 0이라고 생각한다.

struct FenwickTree {
    vector<int> tree;
    FenwickTree(int n) : tree(n+1) {}
    // A[0..pos] 의 부분합을 구한다
    int sum(int pos) {
        // 인덱스가 1부터 시작한다고 생각
        ++pos;
        int ret = 0;
        while(pos > 0) {
            ret += tree[pos];
            // 다음 구간을 찾기 위해 최종 비트를 지운다.
            pos &= (-1);
        }
        return ret;
    }
    // A[pos] 에 val 을 더한다.
    void add(int pos, int val) {
        ++pos;
        while(pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};
```

```c++
// 24.8 삽입 정렬 시간 재기 문제를 펜윅 트리로 해결하기

// 펜윅 트리를 이용해 문제를 해결한다.
long long countMoves(const vector<int>& A) {
    FenwickTree tree(1000000);
    long long ret = 0;
    for(int i = 0; i < A.size(); ++i) {
        ret += tree.sum(999999) - tree.sum(A[i]);
        tree.add(A[i], 1);
    }
    return ret;
}
```

```c++
// 24.9 삽입 정렬 시간 재기 문제를 트립으로 해결하기

// 만들었던 트리를 지운다.
void deleteTree(Niode* node) {
    if(node == NULL) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// 트립을 이용해 문제를 해결한다.
long long countMoves2(const vector<int>& A) {
    Node* root = NULL;
    long long ret = 0;
    for(int i = 0; i < A.size(); ++i) {
        ret += i - coountLessThan(root, A[i]+1);
        root = insert(root, new Node(A[i]))
    }
    deleteTree(root);
    return ret;
}
```

```c++
// 삽입 정렬 시간 재기 문제르르 병합 정렬을 이용해 풀기

// A[left..right] 를 재귀적으로 병합 정렬하고, 해당 범위내의 inversion 수를 반환
long long countMoves3(vector<int>& A, int left, int right) {
    // 기저 사례: 구간의 길이가 1이라면 이미 정렬되었고, .inversion 도 많다.
    if(left == right) return 0;
    // 반으로 나눠서 부분 정복
    int mid = (left + right) / 2;
    long long ret = countMoves3(A, left, mid) + countMoves3(A, mid+1, right);
    // 임시 배열에 정렬된 두 부분 배열을 합친다.
    vector<int> tmp(right - left + 1);
    int tmpIndex = 0; leftIndex = left, rightIndex = mid+1;
    while(leftIndex <= mid || rightIndex <= right) {
        if(leftIndex <= mid && (rightIndex > right || A[leftIndex] <= A[rightIndex])) {
            tmp[tmpIndex++] = A[leftIndex++];
        }
        else {
            // A[rightIndex] 는 왼쪽 부분 배열에 남아 있는 모든 수보다 작다.
            // 이 수들만큼 inversion 을 더해준다
            ret += mid - leftIndex + 1;
            tmp[tmpIndex++] = A[rightIndex++];
        }
    }
    // tmp 에 합친 결과를 A로 다시 복사한다.
    for(int i = 0; i < tmp.size(); ++i)
        A[left + i] = tmp[i];
    return ret;
}
```







