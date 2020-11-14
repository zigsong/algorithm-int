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

long long countMoves(const vector<int>& A) {
  FenwickTree tree(1000000);
  long long ret = 0;
  for (int i=0; i<A.size(); ++i) {
    ret += tree.sum(999999) - tree.sum(A[i]);
    tree.add(A[i], 1);
  }
  return ret;
}

typedef int KeyType;

struct Node {
  KeyType key;
  int priority, size;

  Node *left, *right;

  // 무슨 문법일까요?
  Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {

  }

  void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
  void setRight(Node* newRight) { right = newRight; calcSize(); }

  void calcSize() {
    size = 1;
    if(left) size += left->size;
    if(right) size += right->size;
  }
};

// 24-9
// void deleteTree(Node* node) {
//   if (node == NULL) return;
//   deleteTree(node->left);
//   deleteTree(node->right);
//   delete node;
// }

// long long countMoves2(const vector<int>& A) {
//   Node* root = NULL;
//   long long ret = 0;
//   for (int i=0; i<A.size(); ++i) {
//     ret += i - countLessThan(root, A[i]+1);
//     root = insert(root, new Node(A[i]));
//   }
//   deleteTree(root);
//   return root;
// }

long long countMoves3(vector<int>& A, int left, int right) {
  if (left == right) return 0;
  
  // 반으로 나눠서 부분 정복
  int mid = (left + right) / 2;
  long long ret = countMoves3(A, left, mid) + countMoves3(A, mid+1, right);
  
  // 임시 배열에 정렬된 두 부분 배열을 합침
  vector<int> tmp(right-left+1);
  int tmpIndex = 0, leftIndex = left, rightIndex = mid+1;
  while(leftIndex <= mid || rightIndex <= right) {
    if (leftIndex <= mid && (rightIndex > right || A[leftIndex] <= A[rightIndex])) {
      tmp[tmpIndex++] = A[leftIndex++];
    } 
    else {
      ret += mid - leftIndex + 1;
      tmp[tmpIndex++] = A[rightIndex++];
    }
  }
  for (int i=0; i<tmp.size(); ++i) {
    A[left+i] = tmp[i];
  }
  return ret;
 }