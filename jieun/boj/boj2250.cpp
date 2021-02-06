//
// Created by songji on 2021/01/19.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 10001;
const int INF = 987654321;

int n, idx = 1; // idx = node의 위치
int node[MAX];
int low[MAX];
int high[MAX];
pair<int, int> tree[MAX];

// inorder
void dfs(int nodeNum, int cnt) {
    // left subtree
    if (tree[nodeNum].first > 0) {
        dfs(tree[nodeNum].first, cnt+1);
    }

    // visit (cnt level의 왼/오 끝)
    low[cnt] = min(low[cnt], idx);
    high[cnt] = max(high[cnt], idx);

    idx++;

    // right subtree
    if (tree[nodeNum].second > 0) {
        dfs(tree[nodeNum].second, cnt+1);
    }
}

int main() {
    for (int i = 0; i < MAX; i++) {
        low[i] = INF; // high는 어차피 0으로 초기화되어 있음
    }

    cin >> n;
    for (int i=0; i<n; i++) {
        int curr, left, right;
        cin >> curr >> left >> right;

        node[curr]++;

        if (left != -1) node[left]++;
        tree[curr].first = left;
        if (right != -1) node[right]++;
        tree[curr].second = right;
    }

    int root;
    // 1번 노드가 root(=1)이 아니라, 한 번만 마킹된 노드(node[i]==1)가 root
    for (int i=1; i<=n; i++) {
        if (node[i] == 1) root = i;
    }

    dfs(root, 1);

    // 최대 길이 구하기
    int res = high[1] - low[1] + 1;
    int level = 1;
    for (int i=2; i<=n; i++) {
        int temp = high[i] - low[i] + 1;
        if (temp > res) {
            res = temp;
            level = i;
        }
    }

    cout << level << " " << res << "\n";
    return 0;
}