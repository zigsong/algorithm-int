struct BipartUnionFind {
    bool dis(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return false;
        int a = merge(u, enemy[v]), b == merge(v, enemy[u]);
        enemy[a] = b; enemy[b] = a;
        return true;
    }
    bool ack(int u, int v) {
        u = find(u), v = find(v);
        if(enemy[u] == v) return false;
        int a = merge(u, v), b = merge(enemy[u], enemy[v]);
        enemy[a] = b;
        if(b != -1) enemy[b] = a;
        return true;
    }
};