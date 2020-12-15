//
// Created by songji on 2020/12/15.
//
#include <vector>

using namespace std;

const int MAX_V = 100;
const int INF = 987654321;
int V;
// (연결된 정점 번호, 가중치) 쌍
vector<pair<int, int> > adj[MAX_V];
// 최소 스패닝 트리에 포함된 간선의 목록을 selected에 저장하고, 가중치의 합을 반환
int prim(vector<pair<int, int> >& selected) {
    selected.clear();
    // 해당 정점이 트리에 포함되어 있는지 여부
    vector<bool> added(V, false);
    // 트리에 인접한 간선 중 해당 정점에 닿는 최소 간선의 정보를 저장
    vector<int> minWeight(V, INF), parent(V, -1);
    int ret = 0;

    minWeight[0] = parent[0] = 0;
    for (int iter=0; iter<V; ++iter) {
        // 다음에 트리에 추가할 정점 u 찾기
        int u = -1;
        for (int v=0; v<V; ++v) {
            if (!added[v] && (u == -1 || minWeight[u] > minWeight[v])) {
                u = v;
            }
        }
        // parent[u] = u라면 u-u로 연결(사이클)을 맺는다는 뜻
        if (parent[u] != u) {
            selected.push_back(make_pair(parent[u], u));
        }
        ret += minWeight[u];
        added[u] = true;
        // u를 넣고 난 후, u에 인접한 간선 (u,v)들을 검사
        for (int i=0; i<adj[u].size(); ++i) {
            int v = adj[u][i].first, weight = adj[u][i].second;
            if (!added[v] && minWeight[v] > weight) {
                parent[v] = u;
                minWeight[v] = weight;
            }
        }
    }
    return ret;
}
