// 트리를 순회하며 모든 노드에 포함된 값을 출력하기

// 주어진 트리의 각 노드에 저장된 값을 모두 출력
// children 을 root 로 받아서 다시 순회
// 출력 순서는 그러면 첫번째 root, 그 아래 첫번째, 그 아래 첫번째, 두번째, 세번째 ... 이런식?
void printLabels(TreeNode* root) {
    // 루트에 저장된 값을 출력
    cout << root->label << endl;
    // 각 자손들을 루트로 하는 서브트리에 포함된 값들을 재귀적으로 출력한다.
    for(int i = 0; i < root->children.size(); ++i)
        printLabels(root->children[i]);
}

