// 연결 리스트에서 노드를 삭제하고 다시 추가하기

// node 이전/이후 노드의 포인터를 바꿔서 node를 리스트에서 삭제(접근할 수 없게)한다
void deleteNode(ListNode *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

// node 이전/이후의 노드의 포인터를 바꿔서 자기 자신을 다시 리스트에 삽입(접근할 수 없게)한다
void recoverNode(ListNode *node)
{
    node->prev->next = node;
    node->next->prev = node;
}