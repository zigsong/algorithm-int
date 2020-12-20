// 28.3 깊이 우선 탐색을 이용한 위상 정렬

vector<int> seen, order;
void dfs(int here) {
    seen[here] = 1;
    for(int there = 0; there < adj.size(); ++there)
        if(adj[here][there] && !seen[there])
            dfs(there);
    order.push_back(here);
}
// adj에 주어진 그래프를 위상정렬한 결과를 반환한다.
// 그래프가 DAG가 아니라면 빈 벡터를 반홚나다.
vector<int> topologicalSort() {
    int m = adj.size();
    seen = vector<int>(m, 0);
    order.clear();
    for(i = 0; i < m; ++i) if(!seen[i]) dfs(i);
    reverse(order.begin(), order.end());
    // 만약 그래프가 dAG 가 아니라면 정렬 결과에 역방향 간선이 있다.
    for(int i = 0; i < m; ++i)
        for(int j = i+1; j < m; ++j)
            if(adj[order[j]][order[i]])
                return vector<int>();
    // 없는 경우라면 깊이 우선 탐색에서 얻은 순서를 반환한다.
    return order;
}