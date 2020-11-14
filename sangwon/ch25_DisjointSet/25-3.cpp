struct BipartiteUnionFind {
    vector<int> parent, rank, enemy, size;
    BipartiteUnionFind(int n): parent(n), rank(n, 0), enemy(n, -1), size(n, 1) {
        for(int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u])
    }
    inf merge(int u, int v) {
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
}