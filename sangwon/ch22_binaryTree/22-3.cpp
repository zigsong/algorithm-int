// 트립의 노드를 표현하는 객체의 구현

// 균형잡인 이진 검색 트리를 구현하기 위해
// 보다 구현이 간단한 트립(treap) -> 랜덤화된 이진 검색 트리 (우선순위를 난수로 부여)

typeef int KeyType;
// 트립의 한 노드를 저장한다.
struct Node {
    // 노드에 저장된 원소
    KeyType key;
    // 이 노드를 루트로 하는 서브트리의 크기(size)
    int priority, size;
    // 두 자식 노드의 포인터
    Node *left, *right;
    // 생성자에서 난수 우선순위를 생성하고, size와 left, right를 초기화한다.
    Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {
    }
    void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
    void setRight(Node* newRight) { left = newRight; calcSize(); }
    // size 멤버를 갱신한다.
    void calcSize() {
        size = 1;
        if(left) size += left->size;
        if(right) size += right->size;
    }
};