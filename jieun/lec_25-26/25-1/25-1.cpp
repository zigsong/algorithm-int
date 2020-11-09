#include <iostream>
#include <vector>

using namespace std;

struct NaiveDisjointSet {
  vector<int> parent;
  // : (콜론)은 초기화 리스틀 사용한다는 의미
  NaiveDisjointSet(int n): parent(n) {
    // 각 노드의 부모의 번호를 저장하는 1차원 배열
    for(int i=0; i<n; ++i) {
      parent[i] = i;
    }
  }

  // return값이 const
  // ref1: https://kldp.org/node/71134
  // ref2: https://felixblog.tistory.com/70
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
