// 트립에서의 노드 추가와 트립 쪼개기 연산의 구현

typedef pair<Node*,Node*> NodePair;
// root 를 루트로 하는 트립을 key미만의 값과 이상의 값을 갖는 두개의 트립을 분리한다.
NodePair split(Node* root, KeyType key) {
    if(root == NULL) return NodePair(NULL, NULL);
    // 루트가 key 미만이면 오른쪽 서브트리를 쪼갠다
    if(root->key < key) {
        NodePair rs = split(root->right, key);
        root->setRight(rs.first);
        return NodePair(root, rs.second);
    }
    // 루트가 key 이상이면 왼쪽 서브트리를 쪼갠다.
    NodePair ls = split(root->left, key);
    root->setLeft(ls.second);
    return NodePair(ls.first, root);
}
// root 를 루트로 하는 트립에 새 노드 node 를 삽입한 뒤 결과 트립의 루트를 반환한다.
Node* insert(Node* root, Node* node) {
    if(root == NULL) return node;
    // node 가 루트를 대체해야 한다. 해당 서브트리를 반으로 잘라 각각 자손으로 한다.
    if(root->priority < node->priority) {
        NodePair splitted = split(root, node->key);
        node->setLeft(splitted.first);
        node->setRight(splitted.second);
        return node;
    }
    else if(node->key < root->key)
        root->setLeft(insert(root->left, node));
    else
        root->setRight(insert(root->right, node));
    return root;
}

// root = insert(root, new Node(value));