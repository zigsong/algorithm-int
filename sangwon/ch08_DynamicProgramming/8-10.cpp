// 8.10 최대 증가 부분 수열 문제를 해결하는 완전 탐색 알고리즘

int lis(const vector<int>& A) {
    // 기저 사례: A가 비어 있을 때
    if(A.empty()) return 0; 
    int ret = 0;
    for(int i = 0; i < A.size(); ++i) {
        vector<int> B;
        for(int j = i+1; j < A.size(); ++j)
            if(A[i] < A[j])
                B.push_back(A[j]);
        // lis 에 B 가 다시 들어간다. 
        // for 문을 더 이상 돌릴 수 없을 때(B가 끝에 도달), ret = 0 을 반환
        // 거꾸로 오면서 1씩 더해진다
        ret = max(ret, 1 + lis(B)); 
    }
    return ret;
}