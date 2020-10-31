// 트리에서 가장 긴 경로를 찾는 재귀 호출 알고리즘

struct TreeNode {
    vector<TreeNode*> children;
};
// 지금까지 찾은 가장 긴 잎-잎 경로의 길이를 저장한다.
int longest;
// root 를 루트로 하는 서브트리의 높이를 반환한다.
int height(TreeNode* root) {
    // 각 자식을 루트로 하는 서브트리의 높이를 계산한다.
    vector<int> heights;
    for(int i = 0; i < root->children.size(); ++i)
        heights.push_back(height(root->children[i]));
    // 만약 자식이 하나도 없다면 0을 반환한다.
    if(heights.empty()) return 0;
    sort(heights.begin(), heights.end());
    // root 를 최상위 노드로 하는 경로를 고려하자.
    if (heights.size() >= 2)
        longest = max(longest, 2 + heights[heights.size()-2] + heights[heights.size()-1]);
    // 트리의 높이는 서브트리 높이의 최대치에 1을 더해 계산한다.
    return heights.back() + 1;
}
// 두 노드 사이의 가장 긴 경로의 길이를 계산한다.
int solve(TreeNode* root) {
    longest = 0;
    // 트리의 높이와 최대 잎-잎 경로 길이 중 큰 것을 선택한다.
    int h = height(root);
    return max(longest, h);
}