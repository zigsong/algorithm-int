#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct BipartiteUnionFind {
    // parent[i]=i의 부모 노드, 루트라면 i
    // rank[i]=i가 루트인 경우, i를 루트로 하는 트리의 랭크
    // enemy[i]=i가 루트인 경우, 해당 집합과 적대 관계인 집합의 루트의 번호 (없으면 -1)
    // size[i]=i가 루트인 경우, 해당 집합의 크기
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
        // 이제 항상 rank[v] 가 더 크므로 u 를 v 의 자식으로 넣는다
        if(rank[u] == rank[v]) rank[v]++;
        parent[u] = v;
        size[v] += size[u];
        return v;
    }

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

};