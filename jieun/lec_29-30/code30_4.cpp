//
// Created by songji on 2020/11/24.
//
#include <vector>

using namespace std;

#define MAX_V 999999
#define INF 999999

int V;
vector<pair<int, int> > adj[MAX_V];

vector<int> bellmanFord(int src) {
    // 모든 정점까지의 최단 거리 상한 INF
    vector<int> upper(V, INF);
    upper[src] = 0;
    bool updated;

    for (int iter=0; iter<V; ++iter) {
        updated = false;
        for (int here=0; here<V; ++here) {
            for (int i=0; i<adj[here].size(); i++) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                // (here, there) 간선을 따라 완화 시도
                if (upper[there] > upper[here] + cost) {
                    // 성공
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
            // 모든 간선에 대해 완화가 실패했을 경우 곧장 종료
            if (!updated) break;
        }
    }
    // V번째 순회에서도 완화가 성공했다면 음수 사이클이 있다.
    if (updated) upper.clear();
    return upper;

}
