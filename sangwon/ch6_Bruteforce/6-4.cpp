// 소풍 문제를 해결하는 잘못된 재귀 호출 코드
int n;
bool areFriends[10][10];

int countParings(bool taken[10]) {
    bool finished = true;
    for(int i = 0; i < n; ++i) if(!taken[i]) finished = false;
    if(finished) return 1;
    int ret = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(!taken[i] && !taken[j] && areFriends[i][j]) {
                taken[i] = taken[j] = true;
                ret += countParings(taken);
                taken[i] = taken[j] = false;
            }
    return ret;
}