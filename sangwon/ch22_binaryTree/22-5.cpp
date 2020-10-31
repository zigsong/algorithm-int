// 트립에서 노드의 삭제와 합치기 연산의 구현

// a, b 가 두 개의 트립이고, max(a) < max(b) 일 때 이 둘을 합친다
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

// root 를 루트로 하는 트립에서 key를 지우고 결과 트립의 루트를 반환한다.
Node* erase(Node* root, KeyType key) {
    if(root == NULL) return root;
    // root 를 지우고 양 서브트리를 합친 뒤 반환한다.
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