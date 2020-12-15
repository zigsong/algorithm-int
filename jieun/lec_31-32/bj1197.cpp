//
// Created by songji on 2020/12/15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_V = 1000;
int v, e;
vector<pair<int, int> > map[MAX_V];
vector<pair<int, int> > tree;

struct DisjointSet {
    vector<int> parent;
    DisjointSet(int n): parent(n) {
        for (int i=0; i<n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) const {
        if (u == parent[u]) return u;
        return find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;
        parent[u] = v;
    }
};

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w) { }
};

int comp(Edge& a, Edge& b) {
    return a.w < b.w;
}

int main() {
    cin >> v >> e;
    for (int i=0; i<e; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        map[v1].push_back(make_pair(v2, w));
        map[v2].push_back(make_pair(v1, w));
    }

    int ret = 0;
    tree.clear();

    vector<Edge> edges;
    for (int i=0; i<v; i++) {
        for (int j=0; j<map[i].size(); j++) {
            int there = map[i][j].first, cost = map[i][j].second;
            edges.push_back(Edge(i, j, cost));
        }
    }

    sort(edges.begin(), edges.end(), comp);
    DisjointSet sets(v);
    for (int i=0; i<edges.size(); i++) {
        int cost = edges[i].w;
        int u = edges[i].u, v = edges[i].v;
        if (sets.find(u) == sets.find(v)) continue;
        sets.merge(u, v);
        tree.push_back(make_pair(u, v));
        ret += cost;
    }

    cout << ret << "\n";
//    return ret;
}

