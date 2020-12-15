//
// Created by songji on 2020/12/15.
//
#include <vector>
#include <algorithm>

using namespace std;

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

const int MAX_V = 100;
int V;
// 그래프의 인접 리스트: (연결된 정점 번호, 간선 가중치) 쌍
vector<pair<int, int> > adj[MAX_V];

int kruskal(vector<pair<int, int> >& selected) {
    int ret = 0;
    // 우리가 만들 트리 (간선들의 집합)
    selected.clear();
    // (가중치, (정점1, 정점2))
    vector<pair<int, pair<int, int> > > edges;
    for (int u=0; u<V; ++u) {
        for (int i=0; i<adj[u].size(); ++i) {
            int v = adj[u][i].first, cost = adj[u][i].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }
    }
    // 가중치 순으로 정렬
    sort(edges.begin(), edges.end());
    // 처음엔 모든 정점이 서로 분리되어 있음
    DisjointSet sets(V);
    for (int i=0; i<edges.size(); ++i) {
        int cost = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;
        // 이미 u와 v가 연결되어 있을 경우 (=u와 v가 같은 부모를 가질 경우, u-v를 연결하면 사이클이 형성되므로) 무시
        if (sets.find(u) == sets.find(v)) continue;
        sets.merge(u, v);
        selected.push_back(make_pair(u, v));
        ret += cost;
    }
    return ret;
}

