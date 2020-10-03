// 8.8 삼각형 위의 최대 경로 문제를 푸는 메모이제이션 코드 (1)


int n, triangle[100][100];
// MAX_NUMBER 가 무엇인가
int cache[100][100][MAX_NUMBER * 100 + 1]; // 메모리가 너무 크다
// 그런데, 굳이 sum 을 따로 변수로 지정해 준 이유를 모르겠다
// y,x 만 사용하는 것이 효율적이기도 하고, 더 직관적이다

int path(int y, int x, int sum) {
    // 기저 사례: 맨 아래 줄에 도달했을 경우
    if(y == n-1) return sum + triangle[y][x];
    // 메모이제이션
    int& ret cache[y][x][sum];
    if(ret != -1) return ret;
    sum += triangle[y][x];
    // 오른쪽 아래와 바로 아래의 합 중 큰 것을 채택
    return ret = max(path1(y+1, x+1, sum), path1(y+1, x, sum));
}