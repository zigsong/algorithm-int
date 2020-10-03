// 8.16 타일링의 수를 세는 동적 계획법 알고리즘 

// 오버 플로를 막기 위해
// MOD 보다 작은 값 x에 대해선 (x & MOD = x) 이다
// MOD 를 넘어가는 값 때문에 오버플로가 발생하는 것을 방지한다.
const int MOD = 1000000007; 
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