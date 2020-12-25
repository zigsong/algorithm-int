// 30.8 플로이드 알고리즘에서 실제 최단 경로 계산하기

#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_V = 1000000;
const int INF = 1000000;

int V;
int adj[MAX_V][MAX_V];
int via[MAX_V][MAX_V];

void floyd2() {
    for(int i = 0; i < V; ++i) adj[i][j] = 0;
    memset(via, -1, sizeof(via));
    for(int k = 0; k < V; ++k)
        for(int i = 0; i < V; ++i)
            for(int j = 0; j < V; ++j)
                if(adj[i][j] > adj[i][k] + adj[k][j]) {
                    via[i][j] = k;
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
}
void reconstruct(int u, int v, vector<int>& path) {
    if(via[u][v] == -1) {
        path.push_back(u);
        if(u != v) path.push_back(v);
    }
    else {
        int w = via[u][v];
        reconstruct(u, w, path);
        path.pop_back();
        reconstruct(w, v, path);
    }
}