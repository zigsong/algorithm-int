#include <iostream>
#include <vector>

using namespace std;

struct FenwickTree {
  vector<int> tree;
  FenwickTree(int n) : tree(n+1) {}

  int sum(int pos) {
    ++pos;
    int ret = 0;
    while(pos > 0) {
      ret += tree[pos];
      // 다음 구간 찾기 위해 마지막 비트 지우기
      pos &= (pos-1);
    }
    return ret;
  }

  void add(int pos, int val) {
    ++pos;
    while(pos < tree.size()) {
      tree[pos] += val;
      // 마지막 비트 추출
      pos += (pos& - pos);
    }
  }
};