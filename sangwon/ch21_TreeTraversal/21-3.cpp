// 순회를 이용해 트리의 높이를 계산하기

// root 를 루트로 하는 트리의 높이를 구한다.
// 높이는 간선의 수! 노드의 수가 아니다!
int height(TreeNode* root) {
    int h = 0;
    for(int i = 0; i < root->children.size(); ++i) 
        h = max(h, i + height(root->children[i]));
    return h;
}