int maxParty(const BipartUnionFind& buf) {
    int ret;
    for(int node = 0; node < n; ++node)
        if(buf.parent[node] == node) {
            int enemy = buf.enemy[node];
            if(enemy > node) continue;
            inf mySize = buf.size[node];
            int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
            ret += max(mySize, enemySize);
    }
    return ret;
}