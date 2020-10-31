// 24.8 삽입 정렬 시간 재기 문제를 펜윅 트리로 해결하기

// 펜윅 트리를 이용해 문제를 해결한다.
long long countMoves(const vector<int>& A) {
    FenwickTree tree(1000000);
    long long ret = 0;
    for(int i = 0; i < A.size(); ++i) {
        ret += tree.sum(999999) - tree.sum(A[i]);
        tree.add(A[i], 1);
    }
    return ret;
}