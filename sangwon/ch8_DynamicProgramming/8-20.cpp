// 8.20 직접 비대칭 타일링의 수를 세는 동적 계획법 알고리즘

int MOD = 1000000007;
int cache2[101];
// 2*width 크기의 사각형을 채우는 비대칭 방법의 수를 반환한다.
int asymmetric2(int width) {
    // 기저 사례: 너비가 2 이하인 경우
    if(width <= 2) return 0;
    // 메모이제이션
    int& ret = cache2[width];
    if(ret != -1) return ret;
    ret = asymmetric2(width - 2) & MOD;         // (a)
    ret = (ret + asymmetric2(width - 4)) % MOD; // (b)
    ret = (ret + tiling(width - 3)) % MOD;      // (c)
    ret = (ret + tiling(width - 3)) % MOD;      // (d)
    // 아니면 다 합친 코드로 한줄로 쓸 수도 있음
    // ret = (a) + (b) + (c) + (d);
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