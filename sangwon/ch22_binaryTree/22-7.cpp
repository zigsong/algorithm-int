int countLessThan(Node* root, KeyType key) {
    if(root == NULL) return 0;
    if root->key >= key)
        return countLessThan(root->left, key);
    int ls = (root->left ? root->left->size : 0);
    return ls + 1 + countLessThan(root->right, key);
}