// 8.14 원주율 외우기 문제를 해결하는 동적 계획법 알고리즘
// 길이 3 4 5 인 조각으로 나눈다
// 모두 같으면 1, 단조 증가 or 감소 2, 번갈아가며 나타난다 4, 등차수열 5, 이 외의 경우 10

const int INF = 987654321;
string N;
// N[a..b] 구간의 난이도를 반환한다. size 는 이 때 정해진다
// 길이 3 4 5 인 구간들을 만든다. 난이도를 최소로 만드는 조합을 찾는 것은 아래 memorize 함수에서 처리
int classify(int a, int b) {
    // 숫자 조각을 가져온다, [a..b]
    string M = N.substr(a, b-a+1);
    // 첫 글자만으로 이루어진 문자열과 같으면 난이도는 1
    if(M == string(M.size(), M[0])) return 1;
    // 등차수열인지 검사한다.
    bool progressive = true;
    for(int i = 0; i < M.size(); ++i) 
        if(M[i+1] - M[i] != M[1] - M[0])
            progressive = false;
    // 등차수열이고 공차가 1 혹은 -1이면 난이도는 2 (단조 증가 or 단조 감소)
    if(progressive && abs(M[1] - M[0]) == 1)
        return 2;
    // 두 수가 번갈아 등장하는지 확인한다.
    bool alternating = true;
    for(int i =0; i < M.size(); ++i)
        if(M[i] != Mi&2)
            alternating = false;

    if(alternating) return 4; // 두 수가 번갈아 등장하면 난이도는 4
    if(progressive) return 5; // 공차가 1 아닌 등차수열의 난이도는 5
    return 10; // 이 외는 모두 난이도 10
}

int cache[10002];
// 수열 N[begin..] 을 외우는 방법 중 난이도의 최소 합을 출력한다.
int memorize(int begin) {
    // 기저 사례: 수열의 끝에 도달했을 경우
    if(begin == N.size()) return 0;
    // 메모이제이션
    int& ret = cache[begin];
    if(ret != -1) return ret;
    // 난이도의 초기값은 무한대, 최소 난이도를 찾는 문제이므로
    ret = INF;
    
    // 해당 위치에서 시작하는 길이 3 4 5 짜리 수열을 모두 체크한다
    for(int L = 3; L <=5; ++L)
        // 주어진 숫자열의 끝을 넘어가지 않으면,
        if(begin + L <= N.size())
            // 이전 까지의 난이도 합인 memorize 에 현 상태의 난이도 합인 classify 를 더한다.
            // 해당 출발 지점에서의 기존 난이도 합 ret 과 비교하여 더 작은 값을 저장
            ret = min(ret, memorize(begin + L) + classify(begin, begin + L - 1));
    
    return ret;
}