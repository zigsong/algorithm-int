#include <iostream>
#include <vector>

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

// int runningMedian(int n, RNG rng) {
//   Node* root = NULL;
//   int ret = 0; 
//   for (int cnt=1; cnt<=n; ++cnt) {
//     root = insert(root, new Node(rng.next()));
//     int median = kth(root, (cnt+1)/2)->key;
//     ret = (ret + median) % 20090711;
//   }
  
//   return ret;
// }

struct RNG {
  int seed, a, b;
  RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
  int next() {
    int ret = seed;
    seed = ((seed * (long long)a) + b) % 20090711;
    return ret;
  }
};