//
// Created by songji on 2020/11/24.
//
#include <vector>

using namespace std;

#define MAX_V 999999
#define INF 999999

int V;
vector<pair<int, int> > adj[MAX_V];
// reachable[u][v] = u에서 v로 가는 경로의 존재 여부
bool reachable[MAX_V][MAX_V];

int bellman2(int src, int target) {
    vector<int> upper(V, INF);
    upper[src] = 0;
    // V-1번 순회
    for (int iter=0; iter<V-1; ++iter) {
        for (int here=0; here<V; ++here) {
            for (int i=0; i<adj[here].size(); i++) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                // (here, there) 간선을 따라 완화 시도
                upper[there] = min(upper[there], upper[here] + cost);
            }
        }
    }
    // 음수 사이클의 존재 여부 확인 (V까지!)
    for (int here=0; here<V; ++here) {
        for (int i=0; i<adj[here].size(); i++) {
            int there = adj[here][i].first;
            int cost = adj[here][i].second;
            // 완화가 성공한다면 here는 음수 사이클에 들어 있음
            if (upper[here] + cost < upper[there]) {
                if (reachable[src][here] && reachable[here][target]) return -INF;
            }
        }
    }

    return upper[target];
}