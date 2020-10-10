// 8.9 삼각형 위의 최대 경로 문제를 푸는 동적 계획법 알고리즘 (2)


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