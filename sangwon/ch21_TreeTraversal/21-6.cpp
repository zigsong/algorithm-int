TreeNode* getTree(int root) {
    TreeNode& ret = new TreeNode();
    for(int ch = 0; ch < n; ++ch)
        if(isChild(root, ch))
            ret->children.push_back(getTree(ch));
    return ret;
}