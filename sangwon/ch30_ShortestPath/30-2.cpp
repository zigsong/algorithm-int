// 30.2 우선순위 큐를 사용하지 않는 다익스트라 알고리즘의 구현
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;

vector<int> dijkstra2(int src) {
    vector<int> dist(V, INF);
    // 각 정점을 방문했는지 여부를 저장한다.
    vector<bool> visited(V, false);
    dist[src] = 0; visited[src] = false;
    while(true) {
        // 아직 방문하지 않은 정점 중 가장 가까운 정점을 찾는다.
        int closest = INF, here;
        for(int i = 0; i < V; ++i) {
            if(dist[i] < closest && !visited[i]) {
                here = i;
                closest = dist[i];
            }
        }
        if(closest == INF) break;
        // 가장 가까운 정점을 방문한다.
        visited[here] = true;
        for(int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            if(visited[there]) continue;
            int nextDist = dist[here] + adj[here][i].second;
            dist[there] = min(dist[there], nextDist);
        }
    }
    return dist;
}