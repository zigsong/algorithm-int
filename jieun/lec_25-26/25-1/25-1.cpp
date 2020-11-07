#include <iostream>
#include <vector>

using namespace std;

struct NaiveDisjointSet {
  vector<int> parent;
  NaiveDisjointSet(int n): parent(n) {
    // 각 노드의 부모의 번호를 저장하는 1차원 배열
    for(int i=0; i<n; ++i) {
      parent[i] = i;
    }
  }

  int find(int u) {
    if (u == parent[u]) return u;
    return find(parent[u]);
  }

  void merge(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return;
    parent[u] = v;
  }
};
