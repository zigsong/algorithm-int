// 8.21 폴리오미노의 수 구하기

const int MOD = 10*1000*1000;
int cache[101][101];
// n개의 정사각형으로 이루어졌고, 맨 위 가로줄에 first 개의 정사각형을 포함하는 폴리오미노의 수를 반환
int poly(int n, int first) {
    // 기저 사례: n == first (한층짜리)
    if(n == first) return 1;
    // 메모이제이션
    int& ret = cache[n][first];
    if(ret != -1) return ret;
    // 0으로 초기화
    // for 문이 돌아가지 않는 경우(n-first == 0, 사각형을 모두 소진), ret 값은 그대로 0을 반환한다.
    ret = 0;
    for(int second = 1; second <= n-first; ++second) {
        // 맨 위줄과 그 다음줄을 붙이는 경우의 수
        int add = second + first - 1;
        // 그 다음줄의 사각형들에 대해 재귀적으로 함수를 호출하여, 위 경우의 수에 곱한다.
        add *= poly(n - first, second);
        // 오버플로 방지
        add %= MOD;
        // 계산이 끝나면 리턴 값에 대입, cache 의 값도 이때 업데이트된다.
        ret += add;
        ret %= MOD;
    }
    return ret;
}