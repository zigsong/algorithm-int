#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_INT = numeric_limits<int>::max();
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
    // 각 노드의 왼쪽 자식과 오른쪽 자식으로 분리되는 과정에서, 
    // 노드가 계속 분할되어 결국 start와 end가 같아지는 부분이 생김
    // arr[start~end]가 결국 arr[start]와 같다는 의미이고, 결국 노드의 범위가 1인 리프 노드를 의미
    // https://www.crocus.co.kr/648
    if (left == right) return rangeMin[node] = array[left];
    int mid = (left + right) / 2;
    int leftMin = init(array, left, mid, node*2);
    int rightMin = init(array, mid+1, right, node*2+1);
    return rangeMin[node] = min(leftMin, rightMin);
  }

  // ... 생략
  int query(int left, int right, int node, int nodeLeft, int nodeRight) {
    if (right < nodeLeft || nodeRight < left) return MAX_INT;
    if (left <= nodeLeft && nodeRight <= right) return rangeMin[node];
    int mid = (nodeLeft+nodeRight)/2;
    return min(query(left, right, node*2, nodeLeft, mid), query(left, right, node*2+1, mid+1, nodeRight));
  }

  int query(int left, int right) {
    return query(left, right, 1, 0, n-1);
  }

  // 24-3
  int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
    if (index < nodeLeft || index > nodeRight) return rangeMin[node];
    // 트리의 리프까지 내려온 경우 -> 🤔 뭐가? -> init 함수 참조
    if (nodeLeft == nodeRight) return rangeMin[node] = newValue;
    int mid = (nodeLeft + nodeRight) / 2;
    return rangeMin[node] = min(
      update(index, newValue, node*2, nodeLeft, mid),
      update(index, newValue, node*2+1, mid+1, nodeRight)
    );
  };

  int update(int index, int newValue) {
    return update(index, newValue, 1, 0, n-1);
  }
};