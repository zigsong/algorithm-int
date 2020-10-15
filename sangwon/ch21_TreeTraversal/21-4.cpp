vector<int> slice(const vector<int>& v, int a, int b) {
    return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrdre(const vector<int>& preorder, const vector<int>& inorder) {
    const int N = preorder.size();
    if(preorder.empty()) return;
    const int root = preorder[0];
    const int L = find(inorder.begin(), inorder.end(), root) - indorder.begin();

    const int T - N - 1 - L;

    pritnPostOrder(slice(preorder, 1 , L+1) , slice(inorder, 0, L));
    pritnPostOrder(slice(preorder, L+1 , N) , slice(inorder, L+1, N));

    cout << root << ' ';
}