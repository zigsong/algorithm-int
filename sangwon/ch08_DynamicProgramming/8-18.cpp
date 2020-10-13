// 8.18 우물을 기어오르는 달팽이 문제를 해결하는 동적 계획법 알고리즘

int n, m;
// cache 는 주어진 변수에 대한 모든 경우의 수를 고려할 수 있는 사이즈로 초기화 [m][2m+1]
int cache[MAX_N][2*MAX_N+1];
// 달팽이가 days일 동안 climbed 미터를 기어올라 왔다고 할 때, 
// m 일 전까지 n 미터를 기어올라갈 수 있는 경우의 수
int climb(int days, int climbed) {
    // 기저 사례: m 일이 모두 지났을 때, climbed 가 n 미터를 넘었는지 확인
    if(days == m) return climbed >= n ? 1 : 0;
    // m 일이 모두 지나기 전에도 climbeㅇ >= n 이면 1 반환해도 되지 않나? 아래는 해당 코드
    
    // if(climbed >= n) return 1; 만족하는 경우의 수가 바뀐다!
    
    // 메모이제이션
    int& ret = cache[days][climbed]
    if(ret != -1) return ret;
    // 한칸 올라가거나, 두칸 올라가거나
    // 마지막 순간에 climbed >= n 를 달성하면 1을 반환하므로 경우의 수가 1 더해진다.
    return ret = climb(days+1, climbed+1) + climb(days+1, climbed+2);
}