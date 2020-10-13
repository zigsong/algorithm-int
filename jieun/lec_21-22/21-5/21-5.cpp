#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// #21-7
int n, y[100], x[100], radius[100];
int sqr(int x) {
  return x*x;
}

int sqrdist(int a, int b) {
  return sqr(y[a]-y[b]) + sqr(x[a]-x[b]);
}

bool encloses(int a, int b) {
  return radius[a] > radius[b] && sqrdist(a, b) < sqr(radius[a] - radius[b]);
}

bool isChild(int parent, int child) {
  if (!encloses(parent, child)) return false;
  // 간접 포함인 경우는 제외 
  for (int i=0; i<n; ++i) {
    if (i != parent && i != child && encloses(parent, i) && encloses(i, child)) {
      return false;
    }
  }
  return true;
}

// #21-5
struct TreeNode {
  vector<TreeNode*> children;
};

// #21-6
TreeNode* getTree(int root) {
  TreeNode* ret = new TreeNode();
  for (int ch=0; ch<n; ++ch) {
    // ch 성벽이 root 성벽에 직접적으로 포함되어 있는 경우
    if (isChild(root, ch)) {
      ret->children.push_back(getTree(ch));
    }
  }
  return ret;
}

// --- 

int longest;

int height(TreeNode* root) {
  // 각 서브트리들의 높이를 담아둘 vector
  vector<int> heights; 
  for (int i=0; i<root->children.size(); ++i) {
    heights.push_back(height(root->children[i]));
  }

  if (heights.empty()) return 0;
  sort(heights.begin(), heights.end());
  
  // 현재 vector heights의 가장 큰 2개의 원소를 선택한 후, 현재 root와 이 2개의 서브트리를 연결해주는 edge 개수(2)를 더함
  if (heights.size() >= 2) {
    longest = max(longest, 2+heights[heights.size()-2] + heights[heights.size()-1]);
  }

  return heights.back() + 1;
}
int solve(TreeNode* root) {
  longest = 0;
  int h = height(root);
  return max(longest, h);
}

// sort()
// header: <algorithm>
// sort(start, end)
// 오름차순으로 정렬

