//
// Created by songji on 2020/11/19.
//
#include <vector>
#include <queue>
#define MAX_V 999999
#define INF 999999

using namespace std;

int V;
// pair<정점 번호, 가중치>
vector<pair<int, int> > adj[MAX_V];
vector<int> dijkstra(int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        // 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시
        if (dist[here] < cost) continue;
        for (int i=0; i<adj[here].size(); ++i) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            // dist는 무한대값으로 초기화되어 있음
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}
