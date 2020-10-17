#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
  char data;
  Node* left;
  Node* right;
};

Node *nodes;

void preOrder(Node* node) {
  cout << node->data << endl;
  if (node->left) preOrder(node->left);
  if (node->right) preOrder(node->right);
};

void inOrder(Node* node) {
  if (node->left) preOrder(node->left);
  cout << node->data << endl;
  if (node->right) preOrder(node->right);
};

void postOrder(Node* node) {
  if (node->left) postOrder(node->left);
  if (node->right) postOrder(node->right);
  cout << node->data << endl;
};

int n;

int main() {
  cin >> n;
  Node* rootNode;

  for (int i=0; i<n; i++) {
    char root, left, right;
    cin >> root >> left >> right;

    Node* node = new Node();
    Node* leftNode = new Node();
    Node* rightNode = new Node();

    node->data = root;
    if (i == 0) rootNode = node;
    node->left = leftNode;
    node->right = rightNode;

    if (left != '.') leftNode->data = left;
    if (right != '.') rightNode->data = right;
  }

  preOrder(rootNode);
  // inOrder(rootNode);
  // postOrder(rootNode);
}