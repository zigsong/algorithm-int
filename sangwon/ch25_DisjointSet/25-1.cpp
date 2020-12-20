// 25.1 트리를 이용한 (단순한) 상호 배타적 집합 자료 구조의 구현

#include <vector>
using namespace std;

struct NaiveDisjointSet {
    vector<int> parent;
    NaiveDisjointSet(int n): parent(n) {
        for(int i = 0; i < n; ++i)
            parent[i] = i;
    }
    int find(int u)   const {
        if(u == parent[u]) return u;
        return find(parent[u]);
    }
    void merge(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return;
        parent[u] = v;
    }
};