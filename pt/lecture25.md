# **Lecture 25: 상호 배타적 집합**

by | 혜민

pub date | 2020.11.07.Sat

### **상호 배타적 집합**
: 공통 원소가 없는 부분 집합!들로 나눠진 원소들에 대한 정보를 저장하고 조작하는 자료 구조  
-> `유니온-파인드 자료 구조`

#### 유니온 파인드 자료 구조에 필요한 세 가지 연산
1. 초기화 : n개의 원소가 각각의 집합에 포함되도록 초기화
2. 합치기(union) : 두 원소 a, b가 주어질 떄 이들이 속한 두 집합을 하나로 합침
3. 찾기(find) : 어떤 원소 a가 주어질 때 이 원소가 속한 집합 반환

#### 배열로 상호 배타적 집합 표현
1차원 배열을 이용하여 표현할 수 있다!
```c++
belongsTo[i] 
// i번 원소가 속하는 집합의 번호
```
해당 배열을 각기 다른 숫자 1..n으로 초기화하면 요소별로 각자 다른 집합에 속함을 구현한 것  
-> 찾기 연산을 상수 시간(O(1))에 구현  
-> 합치기 연산의 경우 모든 원소를 순회하며 한쪽 집합에 속한 원소들을 다른 쪽 집합으로 옮겨야 하므로 O(N)의 시간 복잡도



합치기 연산을 빠르게 하기 위해!!!
#### 트리를 이용한 상호 배타적 집합의 표현
[코드 25.1](../hyemin/25_DisjointSet/Disjoint.cpp)
```c++
// 트리를 이용해 상호 배제적 집합을 구현한다.
struct NaiveDisjointSet {
	// 일반 트리와는 반대로 부모를 가리키는 포인터를 가지고 있음
	vector<int> parent;

	// : (콜론)을 쓰는 이유는 초기화 리스트를 사용했기 때문
	// 초기화 리스트 : 생성자가 호출될 때 객체의 생성과 초기화가 한 번에 이루어짐
	// 생성자 함수 내에서 초기화 : 객체가 생성되어, default생성자로 초기화된 상태에서 다시 한 번 할당
	NaiveDisjointSet(int n) : parent(n) {
		// 일단 모든 노드들에 대해서 자신을 루트로 초기화
		for(int i = 0; i < n; i++)
			parent[i] = i;
	}

	// u 가 속한 트리의 루트의 번호를 반환한다
	int find(int u) const {
		if(u == parent[u]) return u;
		return find(parent[u]);
	}

	// u 가 속한 트리와 v 가 속한 트리를 합친다
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		// u 와 v 가 이미 같은 트리에 속하더라도 상관 없다
		parent[u] = v;
	}
};
```
-> find()는 트리에 높이에 비례하는 시간 복잡도  
-> merge() 또한 find()가 지배하여 같은 시간 복잡도

#### 상호 배타적 집합의 최적화
합치기 연산의 핵심은 모든 원소를 변경하지 않고 루트의 parent만 다른 루트로 지정해주는 것!  
-> 트리가 한쪽으로 기울어질 수 있다는 문제는 여전히 존재  
-> 트리를 합칠 때 항상 높이가 더 낮은 트리를 높은 트리 밑에 집어넣는 `랭크에 의한 합치기(union-by-rank)` 최적화  
[코드 25.2](../hyemin/25_DisjointSet/Disjoint.cpp)
```c++
// 트리를 이용해 상호 배타적 집합을 구현한다.
struct OptimizedDisjointSet {
	vector<int> parent, rank;

	OptimizedDisjointSet(int n) : parent(n), rank(n, 1) {
		for(int i = 0; i < n; i++)
			parent[i] = i;
	}

	// u 가 속한 트리의 루트의 번호를 반환한다
	int find(int u) {
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	// u 가 속한 트리와 v 가 속한 트리를 합친다
	void merge(int u, int v) {
		u = find(u); v = find(v);
		// 이미 둘이 같은 트리에 속한 경우
		if(u == v) return;
		// 어차피 이 함수가 반환하는 것은 v이고, v 밑으로 u를 붙이는 것이 default
       		// u가 더 큰 경우에는 v와 바꿔줌 
		if(rank[u] > rank[v]) swap(u, v);
		// 이제 항상 rank[v] 가 더 크므로 u 를 v 의 자식으로 넣는다
		if(rank[u] == rank[v]) rank[v]++;
		parent[u] = v;
	}
};
```
-> 이 코드에 나타난 또다른 최적화는 `경로 압축(path compression)` 최적화  
-> `return parent[u] = find(parent[u]);`로 찾아는 루트를 바로 바꾸는 것!  
*Q. 그런데 parent[u]를 바꿔버리면 트리의 모양이 깨지지 않나? 한 쪽으로 쏠리지만 않으면 괜찮은지... (책 771쪽 그림 25.2 참고)*

---

#### 상호 배타적 집합이 사용될 수 있는 예제

- 그래프의 연결성 확인 : 최소 스패닝 알고리즘으로 해결 (나중에 다룰 것!!)
- 가장 큰 집합 추적하기 : 트리의 높이를 담는 `rank[]`처럼 노드의 개수를 담는 `size[]`를 추가한 뒤 집합이 합쳐질 때마다 갱신!  
**-> 상호 배타적 집합에 다른 정보를 추가해서 새로운 연산을 지원하는 예시**

---

#### 에디터 전쟁
[코드 25.3](../hyemin/25_DisjointSet/EditorWars.cpp)
```c++
// 에디터 전쟁 문제를 해결하는 상호 배타적 집합의 구현
struct BipartiteUnionFind {
    // parent[i] = i의 부모 노드, 루트라면 i
    // rank[i] = i가 루트인 경우, i를 루트로 하는 트리의 랭크(높이)
    // enemy[i] = i가 루트인 경우, 해당 집합과 적대 관계인 집합의 루트의 번호 (없으면 -1)
    // size[i] = i가 루트인 경우, 해당 집합의 크기
    vector<int> parent, rank, enemy, size;
    BipartiteUnionFind(int n) : parent(n), rank(n,0), enemy(n,-1), size(n,1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

    int merge(int u, int v) {
        // u나 v가 공집합인 경우 나머지 하나 반환
        if(u == -1 || v == -1) return max(u,v);
        u = find(u); v = find(v);
        // 이미 둘이 같은 트리에 속한 경우
        if(u == v) return;
        // 어차피 이 함수가 반환하는 것은 v이고, v 밑으로 u를 붙이는 것이 default
        // u가 더 큰 경우에는 v와 바꿔줌 
        if(rank[u] > rank[v]) swap(u, v);
	// 만약 높이가 같으면 하나가 다른 하나의 자식으로 들어갈 때 높이가 1만 높아지므로 처리
        if(rank[u] == rank[v]) rank[v]++;
	// 이제 항상 rank[v] 가 더 크므로 u 를 v 의 자식으로 넣는다
        parent[u] = v;
        size[v] += size[u];
        return v;
    }
```

[코드 25.4](../hyemin/25_DisjointSet/EditorWars.cpp)
```c++
// 에디터 전쟁 문제를 해결하는 ack()과 dis()의 구현

// u와 v가 서로 적대하는 집합에 속한다
    bool dis(int u, int v) {
        // 우선 루트를 찾는다
        u = find(u); v=find(v);
        // 같은 집합에 속해 있으면 모순!
        if (u == v) return false;
        // 적의 적은 나의 동지
        int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
        enemy[a] = b; enemy[b] = a;
        return true;
    }

    // u와 v가 같은 집합에 속한다
    bool ack(int u, int v) {
        // 우선 루트를 찾는다
        u = find(u); v = find(v);
        // 두 집합이 서로 적대 관계라면 모순!
        if(enemy[u] == v) return false;
        // 동지의 적은 나의 적
        int a = merge(u,v), b = merge(enemy[u], enemy[v]);
        enemy[a] = b;
        // 두 집합 다 적대하는 집합이 없으면 b는 -1일 수도 있으니 처리해줌
        if(b != -1) enemy[b] = a;
        return true;
    }
```

[코드 25.5](../hyemin/25_DisjointSet/EditorWars.cpp)
```c++
// 상호 배타적 집합이 주어질 때 에디터 전쟁 문제의 답을 구하는 함수의 구현

    // BipartiteUnionFind 인스턴스가 주어질 때,
    // 한 파티에 올 가능성이 있는 최대 인원을 구한다.
    int maxParty(const BipartiteUnionFind buf) {
        int ret = 0;
        for(int node = 0; node < n; ++node)
            if(buf.parent[node] == node) {
                int enemy = buf.enemy[node];
                // 같은 모임 쌍을 두 번 세지 않기 위해, enemy < node인 경우만 센다
                // enemy == -1인 경우도 정확히 한 번씩 세게 된다
                if(enemy > node) continue;
                int mySize = buf.size[node];
                int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
                // 두 집합 중 큰 집하블 더한다
                ret += max(mySize, enemySize);
            }
        return ret;
    }
```
