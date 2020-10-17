// 트리의 노드를 표현하는 객체의 구현
struct TreeNode {
    string label; // 저장할 자료
    TreeNode& parent; // 부모 노드를 가리키는 포인터
    vector<TreeNode*> children; // 자손 노드들을 가리키는 포인터의 배열
};

