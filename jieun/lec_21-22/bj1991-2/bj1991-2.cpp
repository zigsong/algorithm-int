#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
  char data;
  Node *left;
  Node *right;
};

Node *nodes;

void preorder_traverse(Node *R){
  cout << R->data << " ";
  if(R->left)
    preorder_traverse(R->left);
  if(R->right)
    preorder_traverse(R->right);
}
void inorder_traverse(Node *R){
  if(R->left)
    inorder_traverse(R->left);
  
  cout << R->data << " ";
  
  if(R->right)
    inorder_traverse(R->right);
}

void postorder_traverse (Node *R){
  if(R->left)
    postorder_traverse(R->left);
  if(R->right)
    postorder_traverse(R->right);
    
  cout << R->data << " ";
}

int main(){
    int n, nmb;
    char chr, nr, nl;

    cin >> n;
    nodes = (Node*)malloc(sizeof(Node)*n);

    for (int i = 0; i<n; i++) {
        cin >> chr >> nl >> nr;
        nmb = chr - 'A';
        nodes[nmb].data = chr;

        if(nl == '.') nodes[nmb].left = NULL;
        else nodes[nmb].left = &nodes[nl-'A'];
        if(nr == '.') nodes[nmb].right = NULL;
        else nodes[nmb].right = &nodes[nr-'A'];
    }
    
    preorder_traverse(&nodes[0]);
    printf("\n");
    inorder_traverse(&nodes[0]);
    printf("\n");
    postorder_traverse(&nodes[0]);
  
    free(nodes);
}