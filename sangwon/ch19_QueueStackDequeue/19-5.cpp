// 19.5 외계 신호 분석 문제를 해결하는 온라인 알고리즘

int countRange(int k, int n) {
    RNG rng;
    queue<int> range;
    int ret = 0, rangeSum = 0;
    for(int i = 0; i < n; i++) {
        // 구간에 숫자를 추가한다.
        int newSignal = rng.next();
        rangeSum += newSignal;
        range.push(newSignal);

        // 구간의 합이 k를 초과하는 동안 구간에서 숫자를 뺀다.
        while(rangeSum > k) {
            rangeSum -= range.front();
            range.pop();
        }
        if(rangeSum == k) ret++;
    }
    return ret;
}