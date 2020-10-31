// 19.4 외계 신호 문제를 해결하는 최적화된 알고리즘 

int optimized(const vector<int>& signals, int k) {
    int ret = 0, tail = 0, rangeSum = signals[0];
    for(int head = 0; head < signals.size(); ++head) {
        // rangeSum 이 k 이상인 최초의 구간을 만날 때까지 tail 을 옮긴다.
        while(rangeSum < k && tail + 1 < signals.size())
            rangeSum += signals[++tail];
        
        if(rangeSum == k) ret++;

        // signals[head]는 이제 구간에서 빠진다.
    }
    return ret;
}