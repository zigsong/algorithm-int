int bruteForce(const vector<int>& h) {
    int ret = 0;
    int N = h.size();

    for (int left = 0; left < N; ++left) {
        int minHeight = h[left] ;
        for(int right = left; right < N; ++right) {
            minHeight = min(minHeight, h[right]);
            ret = max(ret, (right - left + 1) * minHeight);
        }
    }
    return ret;
}