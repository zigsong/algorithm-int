#include<cstdio>
#include<cassert>
#include<cstring>
#include<map>
#include<set>
#include<time.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<utility>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 그래프의 인접 행렬 표현
int V, adj[500][500];
// 각 정점에서 음주 운전 단속을 할 때 걸리는 시간
int delay[500];
int W[500][500];
// 입력을 받을 때 1부터 시작하는 정점 번호를 0부터 시작하도록 변경했다고 가정
void solve() {
    // 모든 정점들을 예상 시간 별로 정렬
    vector<pair<int, int>> order;
    for(int i=0; i<V; ++i)
        order.push_back(make_pair(delay[i],i));
    sort(order.begin(), order.end());
    // 정점을 하나도 거치지 않고 얻을 수 있는 최단 경로
    for(int i = 0; i < V; ++i)
        for(int j=0;j<V;++j)
            if(i == j) W[i][j]=0;
            else W[i][j] = adj[i][j];
    int ret = INFINITY;
    for(int k = 0; k < V; ++k) {
        // k번째로 예상 시간이 적게 걸리는 정점 w까지를 지나서 얻을 수 있는 최단 거리
        // .second면 delay[i]가 아니라 i 아닌가? 정점 번호? 
        // w는 정점 번호가 맞음 이후 adj의 index로 사용하기 위해
        int w = order[k].second;
        for(int i = 0; i < V; ++i)
            for(int j = 0; j < V; ++j) {
                // 경유점이 있는 거리가 더 짧으면 최단 거리 갱신
                adj[i][j] = min(adj[i][j], adj[i][w] + adj[w][j]);
                // 최단 거리 갱신되면 최소 예상 시간도 갱신
                W[i][j] = min(adj[i][w]+delay[w]+adj[w][j], W[i][j]);
            }
    }
} // solve()로 정렬 이후 테스트 케이스는 W[s][t]를 출려하기만 하면 됨