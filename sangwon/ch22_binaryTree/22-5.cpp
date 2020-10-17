Node* merge(Node* a, Node* b) {
    if(a == NULL) return b;
    if(b == NULL) return a;
    if(a->priority < b->priority) {
        b->setLeft(merge(a, b->left));
        return b;
    }
    a->setRight(,erge(a->right, b));
    return a;
}

Node* erase(Node* root, KeyType key) {
    if(root == NULL) return root;
    if(root->key == key) {
        Node* ret = merge(root->left, key);
        delete root;
        return ret;
    }
    if(key < root->key)
        root->setLeft(erase(root->left, key))
    else
        root->setRight(erase(root->right, key))
    return root;
}