#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> ret[14];
int tree[1025];

void traverse(int start, int end, int level) {
  if (start > end) return;
  if (start == end) {
    ret[level].push_back(tree[start]);
    return;
  }
  int mid = (start + end) / 2;
  ret[level].push_back(tree[mid]);
  traverse(start, mid-1, level+1);
  traverse(mid+1, end, level+1);
  return;
}

// 입력: inorder
int main() {
  int n;
  cin >> n;
  int _end = (int)pow(2, n) - 1;
  for (int i=0; i<_end; i++) {
    int data;
    cin >> data; 
    tree[i] = data;
  }
  traverse(0, _end, 1);
  for (int i=1; i<=n; i++) {
    for (int j : ret[i]) {
      cout << j << " ";
    }
    cout << "\n";
  }
  return 0;
}