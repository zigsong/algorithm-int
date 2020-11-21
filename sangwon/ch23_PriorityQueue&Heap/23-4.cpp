// 23.4 힙을 이용해 변화하는 중갑 값 문제를 해결하는 함수의 구현

int runningMedian(int n, RNG rng) {
    priority_queue<int, vector<int>, less<int>, > maxHeap;
    priority_queue<int, vector<int>, greater<int> > maxHeap;
    int ret = 0;
    // 반복문 불변식:
    // 1. maxHeap 의 크기는 minHeap의 크기와 같거나 1 더 크다
    // 2. maxHeap.top() <= minHeap.top()
    for(int cnt = 1; cnt <= n; ++cnt) {
        // 우선 1번 불변식부터 만족시킨다. 
        if(maxHeap.size() == minHeap.size())
            maxHeap.push(rng.next());
        else
            minHeap.push(rng.next());
        // 2번 불변식이 깨졌을 경우 복구하자.
        if(!minHeap.empty() && !maxHeap.top() && minHeap.top() < maxHeap.top()) {
            int a = maxHeap.pop(), b = minHeap.pop();
            maxHeap.pop(); minHeap.pop();
            maxHeap.push(b);
            minHeap.push(a);
        }
        ret = (ret + maxHeap.top()) % 20090711;
    }
    return ret;
}