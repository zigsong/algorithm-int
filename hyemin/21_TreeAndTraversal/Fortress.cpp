#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode
{
    vector<TreeNode *> children;
};
//지금까지 찾은 가장 긴 잎-잎 경로 저장
// 전역임!! height 함수 실행하면서 서브트리 높이 구하는 과정과 동시에 Longest도 업데이트
int longest;
// root를 루트로 하는 서브트리의 높이 반환
int height(TreeNode *root)
{
    // 각 자식을 루트로 하는 서브트리의 높이 계산
    vector<int> heights;
    for (int i; i < root->children.size(); ++i)
        heights.push_back(height(root->children[i]));
    // 자식이 하나도 없다면 0 반환
    if (heights.empty())
        return 0;
    sort(heights.begin(), heights.end());
    // root를 최상위 노드로 하는 경로 고려
    if (heights.size() >= 2)
        longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
    // 트리의 높이를 서브트리 높이의 최대치에 1을 더해 계싼
    return heights.back() + 1;
}

// 두 노드 사이의 가장 긴 경로 길이 계산
int solve(TreeNode *root)
{
    longest = 0;
    // 트리의 높이와 최대 잎-잎 경로 길이 중 가장 큰 것 선택
    int h = height(root);
    return max(longest, h);
}

// root 성벽을 루트로 하는 트리 생성
TreeNode *getTree(int root)
{
    TreeNode *ret = new TreeNode();
    for (int ch = 0; ch < n; ++ch)
        // ch 성벽이 root 성벽에 직접적으로 포함되어 있다면
        // 트리를 만들고 자손 목록에 추가
        if (isChild(root, ch))
            ret->children.push_back(getTree(ch));
    return ret;
}
