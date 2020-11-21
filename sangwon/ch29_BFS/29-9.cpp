// 29.9 하노이의 탑 문제를 해결하는 너비 우선 탐색 코드

const int MAX_DISCS = 12;
// 비트마스크를 사용해서 32비트 정수를 배열처럼 사용??
int get(int state, int index) {
    return (state >> (index * 2)) & 3;
}
int set(int state, int index, int value) {
    return (state & ~(3 << (index * 2))) | (value << (index * 2));
}
int c[1<<(MAX_DISCS*2)];
// discs 개의 원반이 있고, 각 원반의 시작 위치와 목표 위치가
// begin, end 에 주어질 때 최소 움직임의 수를 계산한다.
int bfs(int discs, int begin, int end) {
    if(begin == end) return 0;
    queue<int> q;
    memset(c, -1, sizeof(c));
    q.push(begin);
    c[begin] = 0;
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        // 각 기둥에서 제일 위에 있는 원반의 번호를 계산한다.
        int top[4] = { -1, -1, -1, -1 };
        for(int i = discs-1; i >= 0; --i) {
            top[get(here, i)] = i;
        }
        // i번 기둥의 맨 위에 있는 원반을 j번 기둥으로 옮긴다.
        for(int i = 0; i < 4; ++i) {
            // i 번 기둥에 원반이 없으면 안된다.
            if(top[i] != -1){
                for(int j = 0; j < 4; ++j){
                    // j 번 기둥은 비어 있거나, 맨 위의 원반이 더 커야 한다.
                    if(i != j && (top[j] == -1 || top[j] > top[i])) {
                        int there = set(here, top[i], j);
                        if(c[there] != -1) continue;
                        c[there] = c[here] + 1;
                        if(there == end) return c[there];
                        q.push(there);
                    }
                }
            }
        }
    }
    return -1;
}