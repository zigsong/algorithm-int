// 30.5 벨만 포드 알고리즘을 이용해 시간 여행 문제 해결하기
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
vector<pair<int, int> > adj[MAX_V];
bool reachable[MAX_V][MAX_V];
int bellman2(int src, int target) {
    vector<int> upper(V, INF);
    upper[src] = 0;
    for(int iter = 0; iter < V-1; ++iter)
        for(int here = 0; here < V; ++here)
            for(int i = 0; i < adj[here].size(); ++ i) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                if(upper[here] + cost < upper[there])
                    if(reachable[src][here] &&  reachable[here][target])
                        return -INF;
            }
    return upper[target];
}