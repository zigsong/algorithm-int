// 29.1 그래프의 너비 우선 탐색

// 그래프의 인접 리스트 표현
vector<vector<int>> adj;

vector<int> bfs(int start) {
    // 각 정점의 방문 여부, false 로 초기화
    vector<bool> discovered(adj.size(), false);
    // 방문할 정점 목록을 유지하는 큐
    queue<int> q;
    // 정점의 방문 순서
    vector<int> order;
    discovered[start] = true;
    q.push(start);
    // q 가 비어있으면 종료
    while(!q.empty()) {
        // here 에 저장하고 q에서는 삭제
        int here = q.front();
        q.pop();
        // here 를 방문한다. 방문 순서 order 에 집어 넣는다. 
        // order 를 조작하는 부분은 여기가 유일!
        order.push_back(here);
        // 모든 인접한 정점을 검사한다. adj 가 vector<vector<int>>인데, 그러면 size가 전체 정점의 갯수 아닌가?
        // 인접 리스트로 표현해야 하는 게 아닌가
        for(int i = 0; i < adj[here].size(); ++i) {
            // here -> i
            int there = adj[here][i];
            // 처음 보는 정점이면 방문 목록에 집어넣는다. not discovered
            if(!discovered[there]) {
                q.push(there);
                discovered[there] = true;
            }
        }
    }
    // 모두 끝나면 순서 반환
    return order;
}