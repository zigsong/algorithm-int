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
        // 증가 경로가 없으면 종료 (증가 경로가 있었다면 parent[sink]가 위 while-for문을 돌며 어딘가에는 연결되었을 것)
        if (parent[sink] == -1) break;
        // 증가 경로를 통해 유량을 얼마나 보낼지 결정
        int amount = INF;
        // sink에서부터 연결된 parent를 따라 거슬러 올라 감 (source는 미포함)
        // 이때 연결된 간선들 중 최소값의 유량으로만 보낼 수 있으므로(p.994) min 사용
        for (int p=sink; p!=source; p=parent[p]) {
            amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
        }
        for (int p=sink; p!=source; p=parent[p]) {
            // 유량의 대칭성 유지 위해 한 방향의 유량을 늘리면 다른 방향의 유량 줄이기
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;
}

// 32-3
int n, m;
// wins: 각 선수의 승수, match: 각 경기에서 두 선수 중 누구에게 승수 보내줄지
int wins[20], match[200][2];

// 0번 선수가 총 totalWins승으로 우승할 수 있는지 여부 확인
bool canWinWith(int totalWins) {
    // 이미 totalWins승 이상 한 선수가 있으면 안 된다
    if (*max_element(wins+1, wins+n) >= totalWins) return false;
    // 0번은 소스, 1번은 싱크
    V = 2 + m + n;
    memset(capacity, 0, sizeof(capacity));
    for (int i=0; i<m; ++i) {
        // 소스에서 각 경기로 가는 간선 (소스: 0, 싱크: 1이기 때문에 2를 더해줌)
        capacity[0][2+i] = 1;
        // 각 경기에서 두 선수로 가는 간선
        for (int j=0; j<2; ++j) {
            capacity[2+i][2+m+match[i][j]] = 1;
        }
    }
    // 각 선수에서 싱크로, 가능한 최대 승수를 용량으로 하는 간선 추가
    for (int i=0; i<n; ++i) {
        // 0번 선수는 totalWins만큼, 나머지 선수들은 totalWins-1만큼
        int maxWin = (i == 0 ? totalWins : totalWins - 1);
        capacity[2+m+i][1] = maxWin - wins[i];
    }
    return networkFlow(0, 1) == m;
}