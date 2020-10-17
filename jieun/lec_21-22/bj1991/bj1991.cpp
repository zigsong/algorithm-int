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

void preorder(Node* node) {
  cout << node->data << endl;
  if (node->left) preorder(node->left);
  if (node->right) preorder(node->right);
};

void inorder(Node* node) {
  if (node->left) inorder(node->left);
  cout << node->data << endl;
  if (node->right) inorder(node->right);
};

void postorder(Node* node) {
  if (node->left) postorder(node->left);
  if (node->right) postorder(node->right);
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

  preorder(rootNode);
  inorder(rootNode);
  postorder(rootNode);
}