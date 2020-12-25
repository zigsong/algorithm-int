// 31.2 프림 알고리즘의 구현

#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_V = 100;
const int INF = 987654321;

int V;
vector<pair<int, int> > adj[MAX_V];

int prim(vector<pair<int,int> >& selected) {
    selected.clear();
    vector<bool> added(V, false);
    vector<int> minWeight(V, INF), parent(V, -1);
    int ret = 0;
    minWeight[0] = parent[0] = 0;
    for(int iter = 0; iter < V; ++iter) {
        int u = -1;
        for(int v = 0; v < V; ++v)
            if(!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
                u = v;
        if(parent[u] != u)
            selected.push_back(make_pair(parent[u], u));
        ret += minWeight[u];
        added[u] = true;

        for(int i = 0l i < adj[u].size(); ++i) {
            int v = adj[u][i].first, weight = adj[u][i].second;
            if(!added[v] && minWeight[v] > weight) {
                parent[v] = u;
                minWeight[v] = weight;
            }
        }
    }
    return ret;
}