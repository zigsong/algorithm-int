// 19.3 외계 신호 분석 문제를 해결하는 가장 단순한 알고리즘 

int simple(const vector<int>& signals, int k) {
    int ret = 0;
    for(int head = 0; head < signals.size(); ++head) {
        int sum = 0;
        for(int tail = head; tail < signals.size(); ++tail) {
            // sum 은 [head, tail] 구간의 합이다.
            sum += signals[tail];
            if(sum == k) ret++;
            if(sum >= k) break;
        }
    }
    return ret;
}