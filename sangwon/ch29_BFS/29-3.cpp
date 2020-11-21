// 29.3 Sorting Game 문제를 해결하는 너비 우선 탐색 알고리즘

// perm 을 정렬하기 위해 필요한 최소 뒤집기 연산의 수를 계산한다.
int bfs(const vector<int>& perm) {
    int n = perm.size();
    // 목표 정점을 미리 계산한다
    vector<int> sorted = perm;
    sort(sorted.begin(), sorted.end());
    // 방문 목록(큐)과 시작점부터 각 정점까지의 거리
    queue<vector<int> > q;
    map<vector<int>, int> distance;
    // 시작점을 큐에 넣는다.
    distance[perm] = 0;
    q.push(perm);
    while(!q.empty()) {
        // 이번엔 벡터가 들어간다는 점이 다르다.
        vector<int> here = q.front();
        q.pop();

        // 목표 정점을 발견했으면 곧장 종료한다.
        if(here == sorted) return distance[here];
        int cost = distance[here];
        // 가능한 모든 부분 구간을 뒤집어 본다.
        for(int i = 0; i < n; ++i) {
            // 왜 i + 2 지?
            for(int j = i + 2; j <= n; ++j){
                reverse(here.begin() + i, here.begin() + j);
                if(distance.count(here) == 0) {
                    distance[here] = cost + 1;
                    q.push(here);
                }
                reverse(here.begin() + i, here.begin() + j);
            }
        }
    }
    return -1;
}