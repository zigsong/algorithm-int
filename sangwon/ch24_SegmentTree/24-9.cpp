// 24.9 삽입 정렬 시간 재기 문제를 트립으로 해결하기

// 만들었던 트리를 지운다.
void deleteTree(Niode* node) {
    if(node == NULL) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// 트립을 이용해 문제를 해결한다.
long long countMoves2(const vector<int>& A) {
    Node* root = NULL;
    long long ret = 0;
    for(int i = 0; i < A.size(); ++i) {
        ret += i - coountLessThan(root, A[i]+1);
        root = insert(root, new Node(A[i]))
    }
    deleteTree(root);
    return ret;
}