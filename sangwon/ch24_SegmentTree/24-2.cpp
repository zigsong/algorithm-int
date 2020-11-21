// 24.2 RMQ 문제를 푸는 구간 트리에서 질의 연산의 구현

const int INT_MAX = numeric_limits<int>::max();
struct RMQ {
    // node 가 표현하는 번위 array[nodeLeft..nodeRight] 가 주어질 때
    // 이 범위와 array[left..right] 의 교집합의 최소치를 구한다.
    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        // 두 구간이 겹치지 않으면 아주 큰 값을 반환한다 -> 나중에 무시됨
        if(right < nodeLeft || nodeRight < left) return INT_MAX;
        // node 가 표현하는 범위가 array[left..right] 에 완전히 포함되는 경우
        if(left <= nodeLeft && nodeRight <=  right)
            return rangeMin[node];
        // 양쪽 구간을 나눠서 푼 뒤 결과를 합친다.
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node*2, nodeLeft, mid), query(left, right, node*2+1, mid+1, nodeRight));
    }
    // query() 를 외부에서 호출하기 위한 인터페이스
    int query(int left, int right) {
        return query(left, right, 1, 0, n-1);
    }
};