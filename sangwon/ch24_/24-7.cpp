// 24.7 펜윅 트리의 완전한 구현

// 펜윅 트리의 구현. 가상의 배열 A[] 의 부분 합을 빠르게 구현할 수 있도록 한다.
// 초기화시에는 A[]의 원소가 전부 0이라고 생각한다.

struct FenwickTree {
    vector<int> tree;
    FenwickTree(int n) : tree(n+1) {}
    // A[0..pos] 의 부분합을 구한다
    int sum(int pos) {
        // 인덱스가 1부터 시작한다고 생각
        ++pos;
        int ret = 0;
        while(pos > 0) {
            ret += tree[pos];
            // 다음 구간을 찾기 위해 최종 비트를 지운다.
            pos &= (-1);
        }
        return ret;
    }
    // A[pos] 에 val 을 더한다.
    void add(int pos, int val) {
        ++pos;
        while(pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};