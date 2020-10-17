#include <iostream>
#include <random>

using namespace std;

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

// 22-4
// pair
// header: <utility>
// pair<[type1], [type2]> p
// p.first, p.second
typedef pair<Node*, Node*> NodePair;

NodePair split(Node* root, KeyType key) {
  if (root == NULL) return NodePair(NULL, NULL);

  if (root->key < key) {
    NodePair rs = split(root->right, key);
    root->setRight(rs.first);
    return NodePair(root, rs.second);
  }

  NodePair ls = split(root->left, key);
  root->setLeft(ls.second);
  return NodePair(ls.first, root);
}

Node* insert(Node* root, Node* node) {
  if (root == NULL) return node;
  if (root->priority < node->priority) {
    NodePair splitted = split(root, node->key);
    node->setLeft(splitted.first);
    node->setRight(splitted.second);
    return node;
  }
  else if (node->key < root->key) {
    root->setLeft(insert(root->left, node));
  } else {
    root->setRight(insert(root->right, node));
  }
  return root;
} 

// 22-5
Node* merge(Node* a, Node* b) {
  if (a == NULL) return b;
  if (b == NULL) return a;
  if (a->priority < b->priority) {
    b->setLeft(merge(a, b->left));
    return b;
  }
  a->setLeft(merge(a->right, b));
  return a;
}

Node* erase(Node* root, KeyType key) {
  if (root == NULL) return root;
  if (root->key == key) {
    Node* ret = merge(root->left, root->right);
    delete root;
    return ret;
  }
  if (key < root->key) {
    root->setLeft(erase(root->left, key));
  } else {
    root->setRight(erase(root->right, key));
  }
  return root;
}

// 22-6
Node* kth(Node* root, int k) {
  int leftSize = 0;
  if (root->left != NULL) leftSize = root->left->size;
  if (k <= leftSize) return kth(root->left, k);
  if (k == leftSize+1) return root;
  return kth(root->right, k-leftSize-1);
}

// 22-7 
int countLessthan(Node* root, KeyType key) {
  if (root == NULL) return 0;
  if (root->key >= key) {
    return countLessthan(root->left, key);
  } 
  int ls = (root->left ? root->left->size : 0);
  return ls + 1 + countLessthan(root->right, key);
}

// 22-8
int n, shifted[50000]; // shifted: 입력 값 (움직인 칸 수)
int A[50000]; // A: 원 배열 (리턴 값)
void solve() {
// 1~N까지의 숫자를 모두 저장하는 트립을 만든다.  
  Node* candidates = NULL;
  for (int i=0; i<n; ++i) {
    candidates = insert(candidates, new Node(i+1));
  }
  for (int i=n-1; i>=0; --i) {
    // 후보 중 이 수보다 큰 수가 larger개 있다. 
    int larger = shifted[i];
    Node* k = kth(candidates, i+1-larger);
    A[i] = k->key;
    candidates = erase(candidates, k->key);
  }
}