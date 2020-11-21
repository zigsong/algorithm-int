// 24.3 RMQ 문제를 푸는 구간 트리에서 갱신 연산의 구현

struct RMQ {
    // array[index]=newValue 로 바뀌었을 때, node를 루트로 하는
    // 구간 트리를 갱신하고 노드가 표현하는 구간의 최소치를 반환한다.
    int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
        // index가 노드가 표현하는 구간과 상관없는 경우엔 무시한다.
        if(index < nodeLeft || nodeRight < index)
            return rangeMin[node];
        // 트리의 리프까지 내려온 경우
        if(nodeLeft == nodeRight) return rangeMin[node] = newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        return nrangeMin[node] = min(
            update(index, newValue, node*2, nodeLeft, mid),
            update(index, newValue, node*2+1, mid+1, nodeRight));
    }
    // update() 를 외부에서 호출하기 위한 인터페이스
    int update(int index, int newValue) {
        return update(index, newValue, 1, 0, n-1);
    }
};