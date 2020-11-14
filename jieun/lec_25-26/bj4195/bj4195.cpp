#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int parent[200002];
int friends[200002];
char f1[21], f2[21];

int find(int x) {
  if (x == parent[x]) return x;
  return parent[x] = find(parent[x]);
}

int merge(int x, int y) {
  x = find(x); y = find(y);

  if (x != y) {
    parent[x] = y;
    friends[y] += friends[x];
    friends[x] = 1;
  }
 
  return friends[y];
}

int main() {
  int t, n;
  scanf("%d", &t);
  for (int i=0; i<t; i++) {
    int idx = 1;

    map<string, int> friendSet;
    scanf("%d", &n);
    
    for (int j=1; j<=(2*n); j++) {
      parent[j] = j;
      friends[j] = 1;
    }

    
    for (int j=0; j<n; j++) {
      scanf("%s %s", &f1, &f2);
      // 그냥 인덱싱..!!
      if (friendSet.count(f1) == 0) friendSet[f1] = 1;
      if (friendSet.count(f2) == 0) friendSet[f2] = 1;

      printf("%d\n", merge(friendSet[f1], friendSet[f2]));
    }
  }
  
  return 0;
}