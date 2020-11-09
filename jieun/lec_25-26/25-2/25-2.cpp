#include <iostream>
#include <vector>

using namespace std;

struct OptimizedDisjointSet {
  vector<int> parent, rank;
  // vector(n, m) = m으로 초기화된 n개의 원소를 가지는 vector
  // 모든 개인 노드는 높이가 1이므로 1로 초기화
  OptimizedDisjointSet(int n): parent(n), rank(n, 1) {
    for (int i=0; i<n; ++i) {
      parent[i] = i;
    }
  }
       
  int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
  }

  void merge(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return;
    // 왜 rank[v] <= rank[u]는 안 해주는? 
    // 계속 swap하고 나면 항상 rank[v]가 더 크므로 u를 v의 자식으로
    if (rank[u] > rank[v]) swap(u, v);
    parent[u] = v;
    if (rank[u] == rank[v]) ++rank[v];
  }
};