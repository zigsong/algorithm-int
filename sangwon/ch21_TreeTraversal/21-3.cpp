int height(TreeNode* root) {
    int h = 0;
    for(int i = 0; i < root->children.size(); ++i) 
        h = max(h, i + height(root->children[i]));
    return h;
}