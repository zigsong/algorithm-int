// 29.6 15-퍼즐을 해결하는 너비 우선 탐색 알고리즘

#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

// 게임판의 상태를 표현한다.
class State {
    // 인접한 상태들의 목록을 반환한다.
    vector<State> getAdjacent() const;

    // map 에 state 를 넣기 위한 비교 연산자
    bool operator < (const State& rhs) const;
    // 종료 상태와 비교하기 위한 연산자
    bool operator == (const State& rhs) const;
};

typedef map<State, int> StateMap;
// start 에서 finish까지 가는 최단 경로의 길이를 반환한다.
int bfs(State start, State finish) {
    // 예외: start == finish 인 경우 (기저사례?)
    if(start == finish) return 0;
    // 각 정점까지의 최단 경로의 길이를 저장한다.
    StateMap c;
    // 앞으로 방문할 정점들을 저장한다.
    queue<State> q;
    q.push(start);
    c[start] = 0;
    // 너비 우선 탐색
    while(!q.empty()) {
        State here = q.front();
        q.pop();
        int cost = c[here];
        // 인접한 정점들의 번호를 얻어낸다.
        vector<State> adjacent = here.getAdjacent();
        for(int i = 0; i < adjacent.size(); ++i) {
            // 이게 의미하는 바?
            if(c.count(adjacent[i]) == 0) {
                // 답을 찾았나? 끝에 도달하면 1 더해서 return
                if(adjacent[i] == finish) return cost + 1;
                // 그렇지 않으면 cost + 1 을 저장
                c[adjacent[i]] = cost + 1;
                q.push(adjacent[i]);
            }
        }
    }
    // 답을 찾지 못한 경우
    return -1;
}