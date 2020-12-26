// 30.10 새 간선이 그래프에 추가되었을 때 최단 거리 갱신하기
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_V = 1000000;
const int INF = 1000000;

int V, adj[200][200];

bool update(int a, int b, int c) {
    if(adj[a][b] <= c) return false;
    for(int x = 0; x < V; ++x)
        for(int y = 0; y < V; ++y)
            adj[x][y] = min(adj[x][y], min(adj[x][a] + c + adj[b][y], adj[x][b] + c + adj[a][y]));
    return true;
}