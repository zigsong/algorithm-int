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
// 트리를 이용해 상호 배제적 집합을 구현한다.
struct DisjointSet {
  vector<int> parent, rank;

  DisjointSet(int n) : parent(n), rank(n, 1) {
    for(int i = 0; i < n; i++)
      parent[i] = i;
  }

  // u 가 속한 트리의 루트의 번호를 반환한다
  int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
  }

  // u 가 속한 트리와 v 가 속한 트리를 합친다
  void merge(int u, int v) {
    u = find(u); v = find(v);
    // 이미 둘이 같은 트리에 속한 경우
    if(u == v) return;
    if(rank[u] > rank[v]) swap(u, v);
    // 이제 항상 rank[v] 가 더 크므로 u 를 v 의 자식으로 넣는다
    if(rank[u] == rank[v]) rank[v]++;
    parent[u] = v;
  }
};

const int MAX_V = 100;
const int INF = 987654321;

// 정점의 개수
int V;
// 그래프의 인접 리스트. (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int,int> > adj[MAX_V];

// 주어진 그래프에 대해 최소 스패닝 트리에 포함된 간선의 목록을 selected 에
// 저장하고, 가중치의 합을 반환한다.
int kruskal(vector<pair<int,int> >& selected) {
  int ret = 0;
  selected.clear();

  // (가중치, (정점1, 정점2)) 의 목록을 얻는다
  vector<pair<int,pair<int,int> > > edges;
  for(int u = 0; u < V; ++u)
    for(int i = 0; i < adj[u].size(); ++i) {
      int v = adj[u][i].first, cost = adj[u][i].second;
      edges.push_back(make_pair(cost, make_pair(u, v)));
    }
  // 가중치 순으로 정렬
  sort(edges.begin(), edges.end());

  // 처음엔 모든 정점이 서로 분리되어 있다
  DisjointSet sets(V);
  for(int i = 0; i < edges.size(); ++i) {
    // 간선 (u,v) 를 검사한다
    int cost = edges[i].first;
    int u = edges[i].second.first, v = edges[i].second.second;
    // 이미 u와 v가 연결되어 있을 경우 무시한다
    if(sets.find(u) == sets.find(v)) continue;
    // 이 둘을 합친다
    sets.merge(u, v);
    selected.push_back(make_pair(u, v));
    ret += cost;
  }
  return ret;
}

int main() {
  int cases;
  cin >> cases;
  for(int cc = 0; cc < cases; ++cc) {
    int e;
    cin >> V >> e;
    for(int i = 0; i < V; ++i) adj[i].clear();
    for(int i = 0; i < e; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      adj[a].push_back(make_pair(b, c));
      adj[b].push_back(make_pair(a, c));
    }
    vector<pair<int,int> > edges;
    int ret = kruskal(edges);
    for(int i = 0; i < edges.size(); ++i)
      printf("selected (%d,%d)\n", edges[i].first, edges[i].second);

    printf("sum of weights: %d\n", ret);
  }
}

