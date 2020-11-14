int distance(RMQ* rmq, int u, int v) {
    int lu = locInTrip[u], lv = licInTrip[v];
    if(lu < lv) swap(lu, lv);
    int lca = serial2no[rmq->qeuery(lu, lv)];
    return depth[u] + depth[v] - 2 * depth[lca];
}