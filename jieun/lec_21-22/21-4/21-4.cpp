#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// vector v에서 index a~index b만큼 자르기
vector<int> slice(const vector<int>& v, int a, int b) {
  return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
  const int N = preorder.size();
  if (preorder.empty()) return;
  const int root = preorder[0];

  // 왼쪽 서브트리의 크기
  const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
  // 오른쪽 서브트리의 크기 (전체 크기 - 루트 - 왼쪽 서브트리의 크기)
  const int R = N - 1 - L;

  // preorder, inorder 각각에서 root는 빼고 왼/오로 나눈 vector를 재귀 함수의 인자로 넣어줌
  printPostOrder(slice(preorder, 1, L+1), slice(inorder, 0, L));
  // printPostOrder({16, 9, 12}, {9, 12, 16}) 
  printPostOrder(slice(preorder, L+1, N), slice(inorder, L+1, N));
  // printPostOrder({54, 36, 72}, {36, 54, 72})

  // -> 16을 루트로 하는 함수 재귀 호출
  // -> 54를 루트로 하는 함수 재귀 호출
  // ... 

  // root를 가장 마지막에 출력
  cout << root <<  ' ';
}

// find() -> Iterator를 반환 (begin 즉 1부터 시작)
// header: <algorithm>
// InputIterator find(InputIterator first, InputIterator last, const T& val);
