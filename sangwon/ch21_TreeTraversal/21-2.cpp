void printLabels(TreeNode* root) {
    cout << root->label << endl;
    for(int i = 0; i < root->children.size(); ++i)
        printLabels(root->children[i]);
}

