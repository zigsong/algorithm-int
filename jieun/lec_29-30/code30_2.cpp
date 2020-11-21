//
// Created by songji on 2020/11/19.
//

#include <vector>
#define MAX_V 999999
#define INF 999999

using namespace std;

int V;
vector<pair<int, int> > adj[MAX_V];
vector<int> dijkstra2(int src) {
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);
    dist[src] = 0; visited[src] = false;
    while(true) {
        int closest = INF, here;
        for (int i=0; i<V; ++i) {
            if (dist[i] < closest && !visited[i]) {
                here = i;
                closest = dist[i];
            }
        }
        if (closest == INF) break;

        visited[here] = true;
        for (int i=0; i<adj[here].size(); ++i) {
            int there = adj[here][i].first;
            if (visited[there]) continue;
            int nextDist = dist[here] + adj[here][i].second;
            dist[there] = min(dist[there], nextDist);
        }
    }
    return dist;
}