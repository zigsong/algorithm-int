# Lecture 8: 동적 계획법

by | 상원

pub date | 2020.10.02.Fri

### 동적 계획법(Dynamic Programming)이란

- **한번 계산한 것은 다시 계산하지 않겠다!**
- 계산이 끝난 경우의 수를 cache 에 저장하고, 같은 계산을 해야할 상황이 올 때 cache 에 저장된 값을 이용
- 이를 "**메모이제이션**" 이라 한다
- 참조적 투명성이 보장되면(같은 입력을 넣으면 같은 출력이 나올 때), 메모이제이션을 적용할 수 있다.

- 연산 오버헤드를 줄이는 대신에 메모리 오버헤드 발생?
  - 메모리 최적화 -> 8.9
- 시간 복잡도는 최악의 경우 **O(n^2)**



**논리 짜는 순서**

1. 기저사례 먼저 처리(적절한 기저사례 설정이 매우 중요)
2. cache 를 -1 로 초기화
3. ret 을 참조형 (reference by value?) 으로 선언
4. memset() 으로 초기화, but 제한적인 경우에만 사용 가능 (추가 설명 참고)

---

### 이항계수의 계산

##### 8.1 재귀 호출을 이용한 이항 계수의 계산

[code 8-1](../sangwon/ch8_DynamicProgramming/8-1.cpp)

```c++
int bino(int n, int r) {
    if (r == 0 || n == r) return 1;
    return bino(n-1, r-1) + bino(n-1, r); 
    // 이러면 한번 계산한 bino 를 중복해서 계산할 수 있음
}
```

<img src="lecture8.assets/제목 없는 노트 - 2020. 10. 3. 오후 3.16 - 1페이지.jpg" alt="제목 없는 노트 - 2020. 10. 3. 오후 3.16 - 1페이지" style="zoom: 50%;" />

##### 8.2 메모이제이션을 이용한 이항계수의 계산

[code 8-2](../sangwon/ch8_DynamicProgramming/8-2.cpp)

```C++
// -1 로 초기화된 cache (size 는 n 과 r 의 값에 따라 정한다.)
// 결과 값이 양수만 나오는 경우에만 쓸 수 있다.
int cache[30][30]; 

int bino2(int n, int r) {
    // 기저 사례
    if (r == 0 || n == r) return 1;
    // nCr 을 그 전에 계산 했는지 확인하고, 초기값인 -1 이 아닌 경우 계산 안하고 바로 반환
    if (cache[n][r] != -1) 
        return cache[n][r];
    
    return cache[n][r] = bino2(n-1, r-1) + bino2(n-1, r);
}
```



##### 8.3 메모이제이션의 사용 예

[code 8-3](../sangwon/ch8_DynamicProgramming/8-3.cpp)

```C++
// -1 로 초기화된 cache
int cache[2500][2500];

int someObscureFunction(int a, int b) {
    // 기저 사례에 걸리면 바로 return 하여 추가 연산을 막는다.
    if (...) return ...;

    // cache 에 저장된 답이 있으면 바로 반환한다. 참조형으로 호출하면...
    int& ret = cache[a][b];
    if(ret != -1) return ret;

    // 여기에서 답을 계산한다
    ...
    // 참조형으로 호출하면 ret 에 값을 저장하는 순간 cache[a][b] 에도 값이 저장된다.
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
}
```

---



### 외발뛰기(ID: JUMPGAME)

##### 8.4 외발 뛰기 문제를 해결하는 재귀 호출 알고리즘

[code 8-4](../sangwon/ch8_DynamicProgramming/8-4.cpp)

```C++
// board 는 숫자 판, n은
int n, board[100][100];

bool jump(int y, int x) {
    // 기저사례: 마지막 턴에 도착지로 가는 방법이 없을 때(게임판 밖을 벗어나는 경우)
    if (y >= n || x >= n) return false;
    // 기저사례: 목적지에 도착한 경우
    // 왜 n - 1 ? 0~99 라 그런가?
    if (y == n-1 && x == n-1) return true;

    // 해당 칸에 쓰여있는 만큼 갈 수 있다
    int jumpSize = board[y][x];

    // 재귀 호출을 통해 기저 사례에 도달하기 전까지 이동을 반복한다.
    // 세로, 가로 모두 따지기 때문에, 전체 이동 횟수가 n 이라면 2^n 번 따져봐야한다
    // 이미 가본 칸에 대해선 같은 연산을 반복할 필요가 없다 -> 메모이제이션을 활용하자.
    return jump(y + jumpSize, x) || jump(y, x + jumpSize);
}
```



##### 8.5 외발 뛰기 문제를 해결하는 동적 계획법 알고리즘

[code 8-5](../sangwon/ch8_DynamicProgramming/8-5.cpp)

```C++
int n, board[100][100];

// -1 로 초기화된 cache, board 의 사이즈와 같다.
int cache[100][100];

// ret 을 리턴받기 때문에 bool 함수가 아니라 int 함수
int jump2(int y, int x) {
    // 기저 사례 처리
    if(y >= n || x >= n) return 0;
    if(y == n-1 && x == n-1) return 1;
    
    // 메모이제이션
    // cache 의 해당 위치 값을 참조 변수인 ret 에 대입 
    int& ret = cache[y][x];
    
    // 이미 연산된 값이 있는지 확인한다. ret 에 들어간 값 역시 0 or 1
    // 이러면 굳이 bool 함수로 쓰지 않은 이유가?
    if(ret != -1) return ret;
    // cache 에 연산 결과가 없으면 아래 연산 실시
    int jumpSize = board[y][x];
    // ret 에 재귀 호출의 결과값 대입, 재귀가 다 일어나고 0 or 1 의 값을 반환하면 
    // 그제서야 층층이 올라가며 처음 단에서 return 이 일어남
    return ret = (jump2(y + jumpSize, x)) || jump2(y, x + jumpSize);
    // 이때는 아직 ret 에 무슨 값이 들어갈지 모르므로, return 이 실제로 일어나려면 = 뒤의 연산이 끝나야 하지 않나?
}
```

```c++
int main() {
    return a = function();
    // 이러면 1초 지난 후에야 return 이 일어나지 않나?
}
int function() {
    Sleep(1000);
    return 100;
}
```

---



### 와일드카드(ID: WILDCARD)

##### 8.6 와일드카드 문제를 해결하는 완전탐색 알고리즘

[code 8-6](../sangwon/ch8_DynamicProgramming/8-6.cpp) 	

```C++
// input 
// 케이스의 수
// 패턴 (ex. he?p  he*p) w
// 파일 개수
// 파일명 s

// 와일드카드 패턴 w가 문자열 s에 대응되는지 여부를 반환한다.
bool match(const string& w, const string& s) {
    int pos = 0;
    // 문자열의 끝까지 탐색, 하나라도 거짓이면 안된다. 별 문제 없으면 pos 를 하나씩 올려간다.
    // ? 는 어느 문자가 와도 상관 없으니 그냥 ++pos 해도 된다. * 가 문제!
    while(pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos])) 
        ++pos;
    if(pos == w.size()) 
        return pos == s.size(); 
        // true of false 반환, w는 s와 길이가 같거나 더 짧다
        // w 가 끝났을 때 s 도 끝나면 길이가 같으므로 true 반환(일치한다!)

    // * 가 나왔을 때
    if(w[pos] == '*')
        // pos 는 그대로 두고 skip 을 0 부터 (s길이 - pos)까지 올려간다
        for(int skip = 0; pos+skip <= s.size(); ++skip)
            // 재귀 호출, skip 을 올려가며 
            // he*p
            // heaaap
            if(match(w.substr(pos+1), s.substr(pos+skip)))  
                // match 가 false 를 반환하면 다음 루프로
                return true;
    return false;
}
```



##### 8.7 와일드카드 문제를 해결하는 동적 계획법 알고리즘

왜 메모이제이션을 쓰는지에 대한 이해가 조금 더 필요

[code 8-7](../sangwon/ch8_DynamicProgramming/8-7.cpp)

```C++
// -1 로 초기화된 cache, 문자열의 길이가 최대 100 이므로
int cache[101][101];

// W: 패턴 (ex. he*p) , S: 비교할 문자열 (ex. hellp)
string W, S;

bool matchMemoized(int w, int s) {
    // 메모이제이션 
    int& ret = cache[w][s];
    if(ret != -1) return ret;
    while(s < S.size() && w < W.size() && (W[w] == '?' W[w] == S[s])) {
        ++w;
        ++s;
    }
    // w 가 끝에 도달했을 때, s 도 끝에 도달했다면 true, 아니면 false
    // 이 아래 코드는 앞 문제와 논리적으로 같다
    if(w == W.size()) return ret = (s == S.size());

    if(W[w] == '*')
        for(int skip = 0; skip+s <= S.size(); ++skip)
            if(matchMemoized(w+1, s+skip))
                return ret = 1;  
                // match 가 되면 cache 의 해당 값을 1 로 바꿈, 
                // 패턴이 맞는지 다시 계산할 필요 없다.
    return ret = 0;
}
```

---



### 삼각형 위의 최대 경로(ID: TRIANGLEPATH)

##### 8.8 삼각형 위의 최대 경로 문제를 푸는 메모이제이션 코드 (1)

[code 8-8](../sangwon/ch8_DynamicProgramming/8-8.cpp)

```C++
int n, triangle[100][100];
// MAX_NUMBER 가 무엇인가
int cache[100][100][MAX_NUMBER * 100 + 1]; // 메모리가 너무 크다
// 그런데, 굳이 sum 을 따로 변수로 지정해 준 이유를 모르겠다
// y,x 만 사용하는 것이 효율적이기도 하고, 더 직관적이다

int path(int y, int x, int sum) {
    // 기저 사례: 맨 아래 줄에 도달했을 경우
    if(y == n-1) return sum + triangle[y][x];
    // 메모이제이션
    int& ret cache[y][x][sum];
    if(ret != -1) return ret;
    sum += triangle[y][x];
    // 오른쪽 아래와 바로 아래의 합 중 큰 것을 채택
    return ret = max(path1(y+1, x+1, sum), path1(y+1, x, sum));
}
```



##### 8.9 삼각형 위의 최대 경로 문제를 푸는 동적 계획법 알고리즘 (2)

[code 8-9](../sangwon/ch8_DynamicProgramming/8-9.cpp)

```C++
int n, triangle[100][100];
int cache2[100][100];

int path2(int y, int x) {
    // 기저 사례
    if(y == n-1) return triangle[y][x];
    // 메모이제이션
    // 참조 변수로 선언해주었으므로 ret 값이 바뀌면 cache[y][x] 도 바뀐다
    int& ret = cache2[y][x];
    if(ret != -1) return ret;
    
    // ret 값에 해당 위치의 값을 더해준다. y 와 x 는 단순히 좌표에 대한 정보만 가지고 있다
    // ret 값에 합의 정보가 저장되어 있다. 
    return ret = max(path2(y+1, x), path2(y+1, x+1)) + triangle[y][x]; 
}
```

<img src="lecture8.assets/제목 없는 노트 - 2020. 10. 3. 오후 3.16 - 2페이지.jpg" alt="제목 없는 노트 - 2020. 10. 3. 오후 3.16 - 2페이지" style="zoom:50%;" />

위 사진  cache 틀림 (9 -> 12)

#### 동적 계획법을 사용하기 위해선

- 최적 부분 구조가 성립하는지를 알아야한다.
- 더 작은 문제의 최적해만으로 전체 문제의 최적해를 구할 수 없다면 성립 X
- 직관적이지 않은 경우 귀류법이나 대우로 증명

---



### 최대 증가 부분 수열(ID: LIS)

##### 8.10 최대 증가 부분 수열 문제를 해결하는 완전 탐색 알고리즘

[code 8-10](../sangwon/ch8_DynamicProgramming/8-10.cpp)

```C++
int lis(const vector<int>& A) {
    // 기저 사례: A가 비어 있을 때
    if(A.empty()) return 0; 
    int ret = 0;
    for(int i = 0; i < A.size(); ++i) {
        vector<int> B;
        for(int j = i+1; j < A.size(); ++j)
            if(A[i] < A[j])
                B.push_back(A[j]);
        // lis 에 B 가 다시 들어간다. 
        // for 문을 더 이상 돌릴 수 없을 때(B가 끝에 도달), ret = 0 을 반환
        // 거꾸로 오면서 1씩 더해진다
        ret = max(ret, 1 + lis(B)); 
    }
    return ret;
}
```



##### 8.11 최대 증가 부분 수열 문제를 해결하는 동적 계획법 알고리즘 (1)

[code 8-11](../sangwon/ch8_DynamicProgramming/8-11.cpp)

```C++
int n;
int cache[100], S[100];
// S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다.
int lis2(int start) {
    int& ret = cache[start];
    if(ret != -1) return ret;
    ret = 1;
    for(int next = start + 1; next < n; ++next) 
        if(S[start] < S[next])
            ret = max(ret, lis2(next) + 1);
    return ret;
}

int main(){
    int maxLen = 0;
    for(int begin = 0; begin < n; ++begin)
        maxLen = max(maxLen, lis2(begin));
}
```



##### 8.12 최대 증가 부분 수열 문제를 해결하는 동적 계획법 알고리즘 (2)

[code 8-12](../sangwon/ch8_DynamicProgramming/8-12.cpp)

```C++
int n;
int cache[101], S[100];
// S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다.
int lis3(int start) {
    int& ret = cache[start + 1];
    if(ret != -1) return ret;
    ret = 1;
    for(int next = start+1; next < n; ++next)
        if(start == -1  || S[start] < S[next])
            ret = max(ret, lis3(next) + 1);
    return ret;
}
```

---



### 합친 LIS (ID: JLIS)

##### 8.13 합친 LIS 문제를 해결하는 동적 계획법 알고리즘

[code 8-13](../sangwon/ch8_DynamicProgramming/8-13.cpp)

```C++
// 각각 따로 해서 합치면, (1 2 4) (4 5 6) 일 때 6이 나오지만
// 실제 답은 (1 2 4 5 6) 으로 5가 나와야 한다. 따라서 처음부터 모든 걸 고려하는 알고리즘을 짜야 한다.

// 입력이 32비트 부호 있는 정수의 모든 값을 가질 수 있으므로
// 인위적인 최소치는 64비트여야 한다. (?)
const long long NEGINF = numeric_limits<long long>::min();
int n, m, A[100], B[100];
int cache[101][101];
// min(A[indexA], B[indexB]). max(A[indexA], B[indexB]) 로 시작하는
// 합친 증가 부분 수열의 최대 길이를 반환한다.
// 단 indexA == indexB == -1 혹은 A[indexA] != B[indexB] 라고 가정한다.
int jlis(int indexA, int indexB) {
    // 메모이제이션, cache 도 2차원 배열
    int& ret = cache[indexA+1][indexB+1];
    if(ret != -1) return ret;
    // A[indexA], B[indexB]가 이미 존재하므로 2개는 항상 있다.
    ret = 2;
    long long a = (indexA == -1 ? NEGINF : A[indexA]); // -1이 아니면 A[indexA], -1 이면 NEGINF (가장 작은 값)
    long long b = (indexB == -1 ? NEGINF : B[indexB]); // -1이 아니면 B[indexB], -1 이면 NEGINF
    // 둘 중에 더 큰 값을 maxElement 에 저장한다. 이를 통해 처음에 언급한 문제를 해결할 수 있다.
    // 위에서 하나라도 NEGINF 가 나오면 나머지 하나가 maxElement 가 된다.
    long long maxElement = max(a, b);
    // 다음 원소를 찾는다.
    for(int nextA = indexA + 1; nextA < n; ++nextA)
        if(maxElement < A[nextA])
            ret = max(ret, jlis(nextA, indexB) + 1);
    for(int nextB = indexB + 1; nextB < n; ++nextB)
        if(maxElement < B[nextB])
            ret = max(ret, jlis(indexA, nextB) + 1);
    
    return ret;
}
```

---



### 원주율 외우기(ID: PI)

##### 8.14 원주율 외우기 문제를 해결하는 동적 계획법 알고리즘

[code 8-14](../sangwon/ch8_DynamicProgramming/8-14.cpp)

```C++
// 길이 3 4 5 인 조각으로 나눈다
// 모두 같으면 1, 단조 증가 or 감소 2, 번갈아가며 나타난다 4, 등차수열 5, 이 외의 경우 10

const int INF = 987654321;
string N;
// N[a..b] 구간의 난이도를 반환한다. size 는 이 때 정해진다
// 길이 3 4 5 인 구간들을 만든다. 난이도를 최소로 만드는 조합을 찾는 것은 아래 memorize 함수에서 처리
int classify(int a, int b) {
    // 숫자 조각을 가져온다, [a..b]
    string M = N.substr(a, b-a+1);
    // 첫 글자만으로 이루어진 문자열과 같으면 난이도는 1
    if(M == string(M.size(), M[0])) return 1;
    // 등차수열인지 검사한다.
    bool progressive = true;
    for(int i = 0; i < M.size(); ++i) 
        if(M[i+1] - M[i] != M[1] - M[0])
            progressive = false;
    // 등차수열이고 공차가 1 혹은 -1이면 난이도는 2 (단조 증가 or 단조 감소)
    if(progressive && abs(M[1] - M[0]) == 1)
        return 2;
    // 두 수가 번갈아 등장하는지 확인한다.
    bool alternating = true;
    for(int i =0; i < M.size(); ++i)
        if(M[i] != Mi&2)
            alternating = false;

    if(alternating) return 4; // 두 수가 번갈아 등장하면 난이도는 4
    if(progressive) return 5; // 공차가 1 아닌 등차수열의 난이도는 5
    return 10; // 이 외는 모두 난이도 10
}

int cache[10002];
// 수열 N[begin..] 을 외우는 방법 중 난이도의 최소 합을 출력한다.
int memorize(int begin) {
    // 기저 사례: 수열의 끝에 도달했을 경우
    if(begin == N.size()) return 0;
    // 메모이제이션
    int& ret = cache[begin];
    if(ret != -1) return ret;
    // 난이도의 초기값은 무한대, 최소 난이도를 찾는 문제이므로
    ret = INF;
    
    // 해당 위치에서 시작하는 길이 3 4 5 짜리 수열을 모두 체크한다
    for(int L = 3; L <=5; ++L)
        // 주어진 숫자열의 끝을 넘어가지 않으면,
        if(begin + L <= N.size())
            // 이전 까지의 난이도 합인 memorize 에 현 상태의 난이도 합인 classify 를 더한다.
            // 해당 출발 지점에서의 기존 난이도 합 ret 과 비교하여 더 작은 값을 저장
            ret = min(ret, memorize(begin + L) + classify(begin, begin + L - 1));
    
    return ret;
}
```

---



### Quantization(ID: QUANTIZE)

##### 8.15 Quantization 문제의 구현 (다시 보기)

[code 8-15](../sangwon/ch8_DynamicProgramming/8-15.cpp)

```C++
const int INF = 987654321;

int n;
int A[101], pSum[101], pSqSum[101];

void precalc() {
    sort(A, A+n);
    pSum[0] = A[0];
    pSqSum[0] = A[0] * A[0];
    for(int i = 1; i < N; ++i) {
        pSum[i] = pSum[i-1] + A[i];
        pSqSum[i] = pSqSum[i-1] + A[i] * A[i];
    }
}

int minError(int lo, int hi) {
    int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
    int sqSum = pSqSum[hi] - (lo == 0? 0 : pSqSum[lo-1]);

    int m = int (0.5 + (double)sum / (hi - lo + 1));
    int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
    return ret;
}

int cache[101][11];
int quantize(int from, int parts) {
    if(from == n) return 0;
    if(parts == 0) return INF;
    int& ret = cache[from][parts];
    oiif(ret != -1) return ret;
    ret = INF;
    for(int partSize = 1; from + partSize <= n; ++partSize)
        ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));
    return ret;
}
```

---



### 타일링 방법의 수 세기(ID: TILING2)

##### 8.16 타일링의 수를 세는 동적 계획법 알고리즘 

[code 8-16](../sangwon/ch8_DynamicProgramming/8-16.cpp)

```C++
// 오버 플로를 막기 위해
// MOD 보다 작은 값 x에 대해선 (x & MOD = x) 이다
// MOD 를 넘어가는 값 때문에 오버플로가 발생하는 것을 방지한다.
const int MOD = 1000000007; 
int cache[101];
// 2*width 크기의 사각형을 채우는 방법의 수를 MOD로 나눈 나머지를 반환한다.
int tiling(int width) {
    // 기저 사례: width 가 1 or 0 일 때
    if(width <= 1) return 1;
    // 메모이제이션
    int& ret = cache[width];
    
    // cache에 저장된 값이 있을 경우 반환
    if(ret != -1) return ret; 
    
    // 없을 경우 점화식, 결과값을 cache 에 저장 (참조 변수로 선언했으므로)
    return ret = (tiling(width-2) + tiling(width-1)) % MOD; 
}
```

<img src="lecture8.assets/제목 없는 노트 - 2020. 10. 3. 오후 3.16 - 4페이지.jpg" alt="제목 없는 노트 - 2020. 10. 3. 오후 3.16 - 4페이지" style="zoom:50%;" />

---



### 삼각형 위의 최대 경로 개수 세기(ID: TRIPATHCNT)

##### 8.17 삼각형 위의 최대 경로의 수를 찾는 동적 계획법 알고리즘

[code 8-17](../sangwon/ch8_DynamicProgramming/8-17.cpp)

```C++
int countCache[100][100];
// (y,x)에서 시작해서 맨 아래줄까지 내려가는 경로 중 최대 경로의 개수를 반환한다.
int count(int y, int x) {
    // 기저사례: 맨 아랫줄에 도달한 경우
    if(y == n-1) return 1;
    // 메모이제이션
    int& ret = countCache[y][x];
    if(ret != -1) return ret;
    // cache 에 없으면 0 으로 초기화
    ret = 0;
    if(path2(y+1, x+1) >= path2(y+1, x)) ret += count(y+1, x+1);
    if(path2(y+1, x+1) <= path2(y+1, x)) ret += count(y+1, x);
    return ret;
}

// 아래는 path2 코드

int n, triangle[100][100];
int cache2[100][100];

int path2(int y, int x) {
    // 기저 사례
    if(y == n-1) return triangle[y][x];
    // 메모이제이션
    // 참조 변수로 선언해주었으므로 ret 값이 바뀌면 cache[y][x] 도 바뀐다
    int& ret = cache2[y][x];
    if(ret != -1) return ret;
    
    // ret 값에 해당 위치의 값을 더해준다. y 와 x 는 단순히 좌표에 대한 정보만 가지고 있다
    // ret 값에 합의 정보가 저장되어 있다. 
    return ret = max(path2(y+1, x), path2(y+1, x+1)) + triangle[y][x]; 
}
```

---



### 우물을 기어오르는 달팽이

##### 8.18 우물을 기어오르는 달팽이 문제를 해결하는 동적 계획법 알고리즘

[code 8-18](../sangwon/ch8_DynamicProgramming/8-18.cpp)

```C++
// 8.18 우물을 기어오르는 달팽이 문제를 해결하는 동적 계획법 알고리즘

int n, m;
// cache 는 주어진 변수에 대한 모든 경우의 수를 고려할 수 있는 사이즈로 초기화 [m][2m+1]
int cache[MAX_N][2*MAX_N+1];
// 달팽이가 days일 동안 climbed 미터를 기어올라 왔다고 할 때, 
// m 일 전까지 n 미터를 기어올라갈 수 있는 경우의 수
int climb(int days, int climbed) {
    // 기저 사례: m 일이 모두 지났을 때, climbed 가 n 미터를 넘었는지 확인
    if(days == m) return climbed >= n ? 1 : 0;
    // m 일이 모두 지나기 전에도 climbeㅇ >= n 이면 1 반환해도 되지 않나? 아래는 해당 코드
    
    // if(climbed >= n) return 1; 만족하는 경우의 수가 바뀐다!
    
    // 메모이제이션
    int& ret = cache[days][climbed]
    if(ret != -1) return ret;
    // 한칸 올라가거나, 두칸 올라가거나
    // 마지막 순간에 climbed >= n 를 달성하면 1을 반환하므로 경우의 수가 1 더해진다.
    return ret = climb(days+1, climbed+1) + climb(days+1, climbed+2);
}
```

---



### 비대칭 타일링(ID: ASYMTILING)

##### 8.19 비대칭 타일링 문제를 해결하는 동적 계획법 알고리즘 

[code 8-19](../sangwon/ch8_DynamicProgramming/8-19.cpp)

```C++
// 전체에서 대칭인 경우의 수를 뺀다
int MOD = 1000000007;

// 2*width 크기의 사각형을 채우는 비대칭 방법의 수를 반환한다.
int asymmetric(int width) {
    
    // width 가 홀수인 경우
    if(width % 2 == 1)
        // 여기 오타 아닌가? 아니다! 같은 결과
        // return(tiling(width) - tiling(width/2) + MOD) & MOD;
        return(tiling(width) - tiling((width-1)/2) + MOD) & MOD;
    
    // width 가 짝수인 경우
    int ret = tiling(width);
    // MOD 를 더해주는 이유: 음수가 되는 것을 방지하기 위해
    ret = (ret - tiling(width/2) + MOD) % MOD;
    ret = (ret - tiling(width/2 - 1) + MOD) % MOD;
    // tiling(width) - tiling(width/2) - tiling(width/2 - 1) 과 같은 결과
    return ret;
}

// 아래는 tiling 코드

int cache[101];
// 2*width 크기의 사각형을 채우는 방법의 수를 MOD로 나눈 나머지를 반환한다.
int tiling(int width) {
    // 기저 사례: width 가 1 or 0 일 때
    if(width <= 1) return 1;
    // 메모이제이션
    int& ret = cache[width];
    
    // cache에 저장된 값이 있을 경우 반환
    if(ret != -1) return ret; 
    
    // 없을 경우 점화식, 결과값을 cache 에 저장 (참조 변수로 선언했으므로)
    return ret = (tiling(width-2) + tiling(width-1)) % MOD; 
}
```



##### 8.20 직접 비대칭 타일링의 수를 세는 동적 계획법 알고리즘

[code 8-20](../sangwon/ch8_DynamicProgramming/8-20.cpp)

```C++
int MOD = 1000000007;
int cache2[101];
// 2*width 크기의 사각형을 채우는 비대칭 방법의 수를 반환한다.
int asymmetric2(int width) {
    // 기저 사례: 너비가 2 이하인 경우
    if(width <= 2) return 0;
    // 메모이제이션
    int& ret = cache2[width];
    if(ret != -1) return ret;
    ret = asymmetric2(width - 2) & MOD;         // (a)
    ret = (ret + asymmetric2(width - 4)) % MOD; // (b)
    ret = (ret + tiling(width - 3)) % MOD;      // (c)
    ret = (ret + tiling(width - 3)) % MOD;      // (d)
    // 아니면 다 합친 코드로 한줄로 쓸 수도 있음
    // ret = (a) + (b) + (c) + (d);
    return ret;
}


// 아래는 tiling 코드

int cache[101];
// 2*width 크기의 사각형을 채우는 방법의 수를 MOD로 나눈 나머지를 반환한다.
int tiling(int width) {
    // 기저 사례: width 가 1 or 0 일 때
    if(width <= 1) return 1;
    // 메모이제이션
    int& ret = cache[width];
    
    // cache에 저장된 값이 있을 경우 반환
    if(ret != -1) return ret; 
    
    // 없을 경우 점화식, 결과값을 cache 에 저장 (참조 변수로 선언했으므로)
    return ret = (tiling(width-2) + tiling(width-1)) % MOD; 
}
```

---



### 폴리오미노(ID: POLY)

##### 8.21 폴리오미노의 수 구하기

스캐폴딩으로 테스트하기(bruteforce 로 계산한 것과 동적 계획법으로 계산한 것을 비교할 수 있다)

[code 8-21](../sangwon/ch8_DynamicProgramming/8-21.cpp)

```C++
const int MOD = 10*1000*1000;
int cache[101][101];
// n개의 정사각형으로 이루어졌고, 맨 위 가로줄에 first 개의 정사각형을 포함하는 폴리오미노의 수를 반환
int poly(int n, int first) {
    // 기저 사례: n == first (한층짜리)
    if(n == first) return 1;
    // 메모이제이션
    int& ret = cache[n][first];
    if(ret != -1) return ret;
    // 0으로 초기화
    // for 문이 돌아가지 않는 경우(n-first == 0, 사각형을 모두 소진), ret 값은 그대로 0을 반환한다.
    ret = 0;
    for(int second = 1; second <= n-first; ++second) {
        // 맨 위줄과 그 다음줄을 붙이는 경우의 수
        int add = second + first - 1;
        // 그 다음줄의 사각형들에 대해 재귀적으로 함수를 호출하여, 위 경우의 수에 곱한다.
        add *= poly(n - first, second);
        // 오버플로 방지
        add %= MOD;
        // 계산이 끝나면 리턴 값에 대입, cache 의 값도 이때 업데이트된다.
        ret += add;
        ret %= MOD;
    }
    return ret;
}
```

---



### 두니발 박사의 탈옥(ID: NUMB3RS)

#####  8.22 두니발 박사의 탈옥 문제를 해결하는 완전 탐색 알고리즘

[code 8-22](../sangwon/ch8_DynamicProgramming/8-22.cpp)

```C++
int n, d, p, q;

int connected[51][51], deg[51];
double search(vector<int>& path) {
    if(path.size() == d+1) {
        if(path.back( != q)) return 0.0;
        double ret = 1.0;
        for(int i =0; i + 1 < path.size(); ++i) 
            ret /= def[path[i]];
        return ret;
    }
    double ret = 0;
    
    for(int there = 0; there < n; ++there)
        if(connected[path.back()][there]) {
            path.push_back(there);
            ret += search(path);
            path.pop_back();
        }
    return ret;
}
```



##### 8.23 두니발 박사의 탈옥 문제를 해곃하는 동적 계획법 알고리즘

[code 8-23](../sangwon/ch8_DynamicProgramming/8-23.cpp)

```C++
int n, d, p, q;
double cache[51][101];

int connected[51][51], deg[51];
double search2(int here, int days) {
    if(days == d) return (here == q ? 1.0 : 0.0);
    double& ret = cache[here][days];
    if(ret > -0.5) return ret;
    ret = 0.0;
    for(int there = 0; there < n; ++there)
        if(connected[here][there])
            ret += search2(there, days+1) / deg[here];
    return ret;
}
```



##### 8.24 두니발 박사의 탈옥 문제를 해결하는 동적 계획법 알고리즘

[code 8-24](../sangwon/ch8_DynamicProgramming/8-24.cpp)

```C++
int n, d, p, q;
double cahce[51][101];

int connected[51][51], deg[51];
double search3(int here, int days) {
    if(days == 0) return (here == p ? 1.0 : 0.0);
    double& ret = cache[here][days];
    if(ret > -0.5) return ret;
    ret = 0.0;
    for(int there = 0; there < n; ++there) 
        if(connected[here][there])
            ret += search3(there, days - 1) / deg[there];
    return ret;
}
```

