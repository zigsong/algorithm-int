//
// Created by songji on 2020/11/19.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 20000 + 1;
const int INF = 987654321;
int v, e, start;
vector<pair<int, int> > graph[MAX];

vector<int> dijkstra(int src) {
    vector<int> dist(v, INF);
    dist[src] = 0;

    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost) continue;
        for (int i=0; i<graph[here].size(); i++) {
            int there = graph[here][i].first;
            int nextDist = cost + graph[here][i].second;
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}

int main() {
    cin >> v >> e >> start;
    // 정점 번호 1부터 시작
    v++;
    for (int i=0; i<v; i++) {
        int src, dest, cost;
        cin >> src >> dest >> cost;

        graph[src].push_back(make_pair(dest, cost));
    }

    vector<int> result = dijkstra(start);
    for (int i=1; i<v; i++) {
        if (result[i] == INF) cout << "INF\n";
        else cout << result[i] << "\n";
    }
}