// 18.1 연결 리스트에서 노드를 삭제하고 다시 추가하기

void deleteNode(ListNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void recoverNode(ListNode* node) {
    node->prev->next = node;
    node->next->prev = node;
}