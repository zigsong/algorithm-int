#include <iostream>
#include <vector>

using namespace std;

struct RMQ {
  int n;
  // 각 구간의 최소치
  vector<int> rangeMin;
  RMQ(const vector<int>& array) {
    n = array.size();
    rangeMin.resize(n*4);
    init(array, 0, n-1, 1);
  }
  // node 노드가 array[left..right] 배열을 표현할 때
  // node를 루트로 하는 서브트리를 초기화하고, 이 구간의 최소치를 반환
  int init(const vector<int>& array, int left, int right, int node) {
    if (left == right) return rangeMin[node] = array[left];
    int mid = (left + right) / 2;
    int leftMin = init(array, left, mid, node*2);
    int rightMin = init(array, mid+1, right, node*2+1);
    return rangeMin[node] = min(leftMin, rightMin);
  }
};