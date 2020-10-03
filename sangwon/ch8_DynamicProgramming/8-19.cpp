// 8.19 비대칭 타일링 문제를 해결하는 동적 계획법 알고리즘 
// 전체에서 대칭인 경우의 수를 뺀다
int MOD = 1000000007;

// 2*width 크기의 사각형을 채우는 비대칭 방법의 수를 반환한다.
int asymmetric(int width) {
    
    // width 가 홀수인 경우
    if(width % 2 == 1)
        // 여기 오타 아닌가?
        // return(tiling(width) - tiling(width/2) + MOD) & MOD;
        return(tiling(width) - tiling((width-1)/2) + MOD) & MOD;
    
    // width 가 짝수인 경우
    int ret = tiling(width);
    // MOD 를 더해주는 이유: 음수가 되는 것을 방지하기 위해
    ret = (ret - tiling(width/2) + MOD) % MOD;
    ret = (ret - tiling(width/2 - 1) + MOD) % MOD;
    // tiling(width) - tiling(width/2) - tiling(width/2 - 1) 과 같은 결과
    return ret;
}

// 아래는 tiling 코드

int cache[101];
// 2*width 크기의 사각형을 채우는 방법의 수를 MOD로 나눈 나머지를 반환한다.
int tiling(int width) {
    // 기저 사례: width 가 1 or 0 일 때
    if(width <= 1) return 1;
    // 메모이제이션
    int& ret = cache[width];
    
    // cache에 저장된 값이 있을 경우 반환
    if(ret != -1) return ret; 
    
    // 없을 경우 점화식, 결과값을 cache 에 저장 (참조 변수로 선언했으므로)
    return ret = (tiling(width-2) + tiling(width-1)) % MOD; 
}