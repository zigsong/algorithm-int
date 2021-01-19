//
// Created by songji on 2021/01/19.
//

#include <iostream>

using namespace std;

const int MAX = 100001;
int inorder[MAX];
int postorder[MAX];
int idx[MAX];

void printPreorder(int start, int end, int postStart, int postEnd) {
    if (start > end || postStart > postEnd) {
        return;
    }
    int root = postorder[postEnd];
    int rootIdx = idx[root];
    int leftSize = rootIdx - start;
    int rightSize = end - rootIdx;

    cout << root << " ";

    printPreorder(start, rootIdx-1, postStart, postStart+leftSize-1); // 왼쪽
    printPreorder(rootIdx+1, end, postStart+leftSize, postEnd-1); // 오른쪽
}

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }
    for (int i=0; i<n; i++) {
        cin >> postorder[i];
    }

    printPreorder(0, n-1, 0, n-1);
}