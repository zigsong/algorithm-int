// 29.2 최단 경로를 계산하는 너비 우선 탐색

// start 에서 시작해 그래프를 너비 우선 탐색하고 시작점부터 각 정점까지의
// 최단 거리와 너비 우선 탐색 스패닝 트리를 계산하낟.
// distance[i] = start 부터 i 까지의 최단 거리
// parent[i] = 너비 우선 탐색 스패닝 트리에서 i 의 부모의 번호. 루트인 경우 자신의 번호
void bfs2(int start, vector<int>& distance, vector<int>& parent) {
    // -1 로 초기화한 parent 와 distance 벡터
    distance = vector<int>(adj.size(), -1);
    parent = vector<int>(adj.size(), -1);
    // 방문할 정점 목록을 유지하는 큐
    queue<int> q;
    distance[start] = 0;
    parent[start] = start;
    q.push(start);
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        // here 의 모든 인접한 정점을 검사한다
        for(int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i];
            // 처음 보는 정점이면 방문 목록에 집어 넣는다
            if(distance[there] == -1) {
                q.push(there);
                // start 부터 층별로 1 씩 더해진다
                distance[there] = distance[here] + 1;
                // I'm your father
                parent[there] = here;
            }
        }
    }
}

// v 부터 시작점 까지의 최단 경로를 계산
vector<int> shortestPath(int v, const vector<int>& parent) {
    // path(1, v) 가 의미하는 바?
    vector<int> path(1, v);
    // parent 가 자기 자신이면 종료
    while(parent[v] != v) {
        v = parent[v];
        path.push_back(v);
    }
    // 뒤에서부터 셌으니까 뒤집어준다
    reverse(path.begin(), path.end());
    return path;
}