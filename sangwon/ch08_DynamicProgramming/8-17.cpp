// 8.17 삼각형 위의 최대 경로의 수를 찾는 동적 계획법 알고리즘

int countCache[100][100];
// (y,x)에서 시작해서 맨 아래줄까지 내려가는 경로 중 최대 경로의 개수를 반환한다.
int count(int y, int x) {
    // 기저사례: 맨 아랫줄에 도달한 경우
    if(y == n-1) return 1;
    // 메모이제이션
    int& ret = countCache[y][x];
    if(ret != -1) return ret;
    // cache 에 없으면 0 으로 초기화
    ret = 0;
    if(path2(y+1, x+1) >= path2(y+1, x)) ret += count(y+1, x+1);
    if(path2(y+1, x+1) <= path2(y+1, x)) ret += count(y+1, x);
    return ret;
}

// 아래는 path2 코드

int n, triangle[100][100];
int cache2[100][100];

int path2(int y, int x) {
    // 기저 사례
    if(y == n-1) return triangle[y][x];
    // 메모이제이션
    // 참조 변수로 선언해주었으므로 ret 값이 바뀌면 cache[y][x] 도 바뀐다
    int& ret = cache2[y][x];
    if(ret != -1) return ret;
    
    // ret 값에 해당 위치의 값을 더해준다. y 와 x 는 단순히 좌표에 대한 정보만 가지고 있다
    // ret 값에 합의 정보가 저장되어 있다. 
    return ret = max(path2(y+1, x), path2(y+1, x+1)) + triangle[y][x];
} 