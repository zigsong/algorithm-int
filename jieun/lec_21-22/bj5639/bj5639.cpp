#include <iostream>

using namespace std;

const int MAX = 10001;

struct Node {
  int left, right;
};

Node tree[10002];

void postOrder(int r) {
  if (r == 0) return;
  if (tree[r].left != 0) postOrder(tree[r].left);
  if (tree[r].right != 0) postOrder(tree[r].right);
  cout << r << "\n";
}

int main() {
  int root;
  // preorder이므로 첫 번쨰는 무조건 root
  cin >> root;
  int data; 

  while (cin >> data) {
    int curr = root;
    while (true) {
      if (data < curr) {
        if (tree[curr].left != 0) {
          curr = tree[curr].left;
        } else {
          tree[curr].left = data;
          break; 
        }
      } else {
        if (tree[curr].right != 0) {
          curr = tree[curr].right;
        } else {
          tree[curr].right = data;
          break;
        }
      }
    }
  }

  postOrder(root);
  return 0;
}