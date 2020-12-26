// 25.3 에디터 전쟁 문제를 해결하는 상호 배타적 집합의 구현

#include <vector>
using namespace std;

struct BipartiteUnionFind {
    vector<int> parent, rank, enemy, size;
    BipartiteUnionFind(int n): parent(n), rank(n, 0), enemy(n, -1), size(n, 1) {
        for(int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    int merge(int u, int v) {
        if(u == -1 || v == -1) return max(u, v);
        u = find(u); v = find(v);
        if(u == v) return u;
        if(rank[u] > rank[v]) swap(u, v);
        if(rank[u] == rank[v]) rank[v]++;
        parent[u] = v;
        size[v] += size[u];
        return v;
    }
    bool dis(int u, int v) {}
    bool ack(int u, int v) {}
};