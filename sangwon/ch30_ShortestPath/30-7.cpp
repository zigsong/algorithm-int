// 30.7 플로이드 알고리즘의 구현 
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_V = 1000000;
const int INF = 1000000;

;int V;

int adj[MAX_V][MAX_V];

void floyd() {
    for(int i = 0; i < V; ++i) adj[i][i] = 0;
    for(int k = 0; k < V; ++k)
        for(int i = 0; i < V; ++i)
            for(int j = 0; j < V; ++j)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}