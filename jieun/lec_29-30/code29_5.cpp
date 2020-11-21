//
// Created by songji on 2020/11/17.
//

#include <vector>
#include <queue>
#include <map>

using namespace std;

class State {
    public:
        vector<State> getAdjacent() const;
        bool operator < (const State& rhs) const;
        bool operator == (const State& rhs) const;
};

typedef map<State, int> StateMap;

// finish는 완벽하게 정렬된 최종 상태
int bfs(State start, State finish) {
    if (start == finish) return 0;
    StateMap c;
    queue<State> q;
    q.push(start);
    c[start] = 0;
    while(!q.empty()) {
        State here = q.front();
        q.pop();
        int cost = c[here];
        vector<State> adjacent = here.getAdjacent();
        for (int i=0; i<adjacent.size(); ++i) {
            if (c.count(adjacent[i]) == 0) {
                if (adjacent[i] == finish) return cost + 1;
                c[adjacent[i]] = cost + 1;
                q.push(adjacent[i]);
            }
        }
    }
    return -1;
}

// 29-7
class State;
int sgn(int x) { if (!x) return 0; return x > 0 ? 1 : -1; }
// 최단 거리 저장 시 정방향은 양수로, 역방향은 음수로 저장
int incr(int x) { if (x < 0) return x - 1; return x + 1; }
int bidirectional(State start, State finish) {
    // 각 정점까지의 최단 경로의 길이
    map<State, int> c;
    // 앞으로 방문할 정점들을 저장
    queue<State> q;
    if (start == finish) return 0;
    // 탐색의 방향이 정방향인지 역방향인지를 음수/양수 여부로 구분하기 대문에 최단 거리를 0으로 둘 수 없음
    // 두 탐색의 시작 정점들의 최단 거리도 0이 아니라 각각 1과 -1
    // 정방향, 역방향 번갈아가면서 for loop을 돌면서 인접 state를 체크
    q.push(start); c[start] = 1;
    q.push(finish); c[finish] = -1;
    while(!q.empty()) {
        State here = q.front();
        q.pop();
        vector<State> adjacent = here.getAdjacent();ㅈ
        for (int i=0; i<adjacent.size(); ++i) {
            map<State, int>::iterator it = c.find(adjacent[i]);
            if (it == c.end()) {
                c[adjacent[i]] = incr(c[here]);
                q.push(adjacent[i]);
            }
            // 인접한 상태를 검사했는데, 서로 부호가 다르다면 가운데서 만난 상태
            // 가운데서 만난 경우, 두 정점까지의 최단 거리를 합한 뒤 처음에 더했던 1을 각각 빼주고, (-1-1)
            // 그 후에 두 정점 사이의 간선을 하나 더하면(+1) 최단 경로를 얻을 수 있다
            else if (sgn(it->second) != sgn(c[here])) {
                return abs(it->second) + abs(c[here]) - 1;
            }
        }
    }
    return -1;
}

// 29-9
class State;
int best;
void dfs(State here, const State& finish, int steps) {
    if (steps >= best) return;
    if (here == finish) { best = steps; return; }
    vector<State> adjacent = here.getAdjacent();
    for (int i=0; i<adjacent.size(); ++i) {
        dfs(adjacent[i], finish, steps+1);
    }
}

int ids(State start, State finish, int growthStep) {
    // 두 번째 없는 거 처음 봄
    for (int limit=4; ; limit += growthStep) {
        best = limit + 1;
        dfs(start, finish, 0);
        if (best <= limit) return best;
//        if (steps + here.estimate() >= best) return;
    }
    return -1;
}