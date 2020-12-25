// 31.1 크루스칼의 최소 스패닝 트리 알고리즘

#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;

struct DisjointSet;
const int MAX_V = 100;
int V;
vector<pair<int, int> > adj[MAX_V];

int kruskal(vector<pair<int, int> >& selected) {
    int ret = 0;
    selected.clear();
    vector<pair<int, pair<int, int> > > edges;
    for(int u = 0; u < V;+ ++u)
        for(int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first, cost = adj[u][i].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }
    sort(edges.begin(), edges.end());
    DisjointSet sets(V);
    for(int i = 0; i < edges.size)_; ++i {
        int cost = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;
        if(sets.find(u) == sets.find(v)) continue;
        sets.merge(u, v);
        selected.push_back(make_pair(u, v));
        ret += cost;
    }
    return ret;
}