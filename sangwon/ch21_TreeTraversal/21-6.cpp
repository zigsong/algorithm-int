// 주어진 번호의 성벽에 포함된 구역들을 표현하는 트리를 생성한다

// root 성벽을 루트로 하는 트리를 생성한다.
TreeNode* getTree(int root) {
    TreeNode& ret = new TreeNode();
    for(int ch = 0; ch < n; ++ch)
    // ch 성벽이 root 성벽에 직접적으로 포함되어 있다면
    // 트리를 만들고 자손 목록에 추가한다.
        if(isChild(root, ch))
            ret->children.push_back(getTree(ch));
    return ret;
}