//
// Created by songji on 2020/12/15.
//
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAX_V = 100;
const int INF = 987654321;
int V;
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];

int networkFlow(int source, int sink) {
    memset(flow, 0, sizeof(flow));
    int totalFlow = 0;
    while (true) {
        vector<int> parent(MAX_V, -1);
        queue<int> q;
        parent[source] = source;
        q.push(source);
        while (!q.empty() && parent[sink] == 1) {
            int here = q.front();
            q.pop();
            for (int there=0; there<V; ++there) {
                if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        // 증가 경로가 없으면 종료
        if (parent[sink] == -1) break;
        // 증가 경로를 통해 유량을 얼마나 보낼지 결정
        int amount = INF;
        for (int p=sink; p!=source; p=parent[p]) {
            amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
        }
        for (int p=sink; p!=source; p=parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;
}

// 32-3
int n, m;
int wins[20], match[290][2];

// 0번 선수가 총 totalWins승으로 우승할 수 있는지 여부 확인
bool canWinWith(int totalWins) {
    // 이미 totalWins승 이상 한 선수가 있으면 안 된다
    if (*max_element(wins+1, wins+n) >= totalWins) return false;
    // 0번은 소스, 1번은 싱크
    V = 2 + m + n;
    memset(capacity, 0, sizeof(capacity));
    for (int i=0; i<m; ++i) {
        // 소스에서 각 경기로 가는 간선
        capacity[0][2+i] = 1;
        // 각 경기에서 두 선수로 가는 간선
        for (int j=0; j<2; ++j) {
            capacity[2+i][2+m+match[i][j]] = 1;
        }
    }

    for (int i=0; i<n; ++i) {
        int maxWin = (i == 0 ? totalWins : totalWins - 1);
        capacity[2+m+i][1] = maxWin - wins[i];
    }
    return networkFlow(0, 1) == m;
}