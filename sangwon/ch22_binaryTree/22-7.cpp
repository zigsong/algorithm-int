// 트립에서 X보다 작은 원소의 수를 찾는 알고리즘의 구현

// key 보다 작은 키값의 수를 반환한다.
int countLessThan(Node* root, KeyType key) {
    if(root == NULL) return 0;
    if root->key >= key)
        return countLessThan(root->left, key);
    int ls = (root->left ? root->left->size : 0);
    return ls + 1 + countLessThan(root->right, key);
}