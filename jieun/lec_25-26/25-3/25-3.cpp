#include <iostream>
#include <vector>

using namespace std;

struct BipartiteUnionFind {
  vector<int> parent, rank, enemy, size;
  BipartiteUnionFind(int n): parent(n), rank(n, 0), enemy(n, -1), size(n, 1) {
    for (int i=0; i<n; ++i) parent[i] = i;
  }
  int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
  }
  int merge(int u, int v) {
    // u, v가 공집합일 경우
    if (u == -1 || v == -1) return max(u, v);
    u = find(u); v = find(v);
    // 이미 둘이 같은 트리에 속한 경우
    if (u == v) return u;
    if (rank[u] > rank[v]) swap(u, v);
    // 이제 항상 rank[v]가 더 크므로 u를 v의 자식으로
    if (rank[u] == rank[v]) rank[v]++;
    parent[u] = v;
    // 🤔 왜 25-2에서는 if (rank[u] == rank[v]) ++rank[v]; 로 썼을까?
    size[v] += size[u];
    return v;
  }
  bool dis(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    int a = merge(u, enemy[v]), b = merge(v, enemy[v]);
    enemy[a] = b; enemy[b] = a;
    return true;
  }

  bool ack(int u, int v) {
    u = find(u); v = find(v);
    if (enemy[u] == v) return false;
    int a = merge(u, v), b = merge(enemy[u], enemy[v]);
    enemy[a] = b;
    // 두 집합 다 적대하는 집합이 없으면 b는 -1일 수도 있음
    if (b != -1) enemy[b] = a;
    return true;
  }
};

int maxParty(const BipartiteUnionFind& buf, int n) {
  int ret = 0;
  for (int node=0; node<n; ++node){
    if (buf.parent[node] == node) {
      int enemy = buf.enemy[node];
      if (enemy > node) continue;
      int mySize = buf.size[node];
      int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
      ret += max(mySize, enemySize);
    }   
  }
  return ret;
} 