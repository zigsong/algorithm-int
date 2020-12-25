// 30.9 플로이드 알고리즘을 개선해 음주 운전 문제를 해결하는 알고리즘의 구현
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_V = 1000000;
const int INF = 1000000;

int V, adj[500][500];
int delay[500];
int W[500][500];

void solve() {
    vector<pair<int, int> > order;
    for(int i = 0; i < V; ++ i) 
        order.push_back(make_pair(delay[i], i));
    sort(order.begin(), order.end());
    for(int i = 0; i < V; ++i)
        for(int j = 0; j < V; ++j)
            if(i == j)
                W[i][j] = 0;
            else
                W[i][j] = adj[i][j];
    int ret = INF;
    for(int k = 0; k < V; ++k) {
        int w = order[k].second;
        for(int i = 0; i < V; ++i)
            for(int j = 0; j < V; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][w] + adj[w][j]);
                W[i][j] = min(adj[i][w] + delay[w] + adj[w][j], W[i][j]);
            }
    }  
}