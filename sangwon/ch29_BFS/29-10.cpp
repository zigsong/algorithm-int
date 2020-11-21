// 29.10 하노이의 탑 문제를 해결하는 양방향 탐색의 구현

// x의 부호를 반환한다.
int sgn(int x) { if(!x) return 0; return x > 0 ? 1 : -1; } 
// x 의 절대값 1 증가
int incr(int x) { if(x < 0) return x-1; return x+1; }

// discs 개의 원반이 있고, 각 원반의 시작 위치와 목표 위치가
// begin, end 에 주어질 때 최소 움직임의 수를 계산한다.
int bidir(int discs, int begin, int end) {
    if(begin == end) return 0;
    queue<int> q;
    // 초기화를 0으로 한다 (부호를 기준으로 판별하므로)
    memset(c, 0, sizeof(c));
    // 정방향 탐색은 양수로, 역방향 탐색은 음수로
    q.push(begin); c[begin] = 1;
    q.push(end); c[end] = -1;
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        int top[4] = { -1, -1, -1, -1 };
        for(int i - discs-1; i >= 0; --i) {
            top[get(here, i)] = i;
        }
        for(int i = 0; i < 4; ++i) {
            if(top[i] != -1) {
                for(int j = 0; j < 4; ++j) {
                    if(i != j && (top[j] == -1 || top[j] > top[i])) {
                        int there = set(here, top[i], j);
                        // 아직 방문하지 않은 정점인 경우
                        if(c[there] == 0) {
                            c[there] = incr(c[here]);
                            q.push(there);
                        }
                        // 가운데에서 만난 경우
                        else if(sgn(c[there]) != sgn(c[here])){
                            return abs(c[there]) + abs(c[here]) - 1;
                        }
                    }
                }
            }
        }
    }
    return -1;
}