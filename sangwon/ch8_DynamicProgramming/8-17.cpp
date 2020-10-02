#include <iostream>
#include <string>
#include <vector>

int countCache[100][100];

int count(int y, int x) {
    // 기저사례: 맨 아랫줄에 도달한 경우
    if(y == n-1) return 1;
    // 메모이제이션
    int& ret = countCache[y][x];
    if(ret != -1) return ret;
    ret = 0;
    if(path2(y+1, x+1) >= path2(y+1, x)) ret += count(y+1, x+1);
    if(path2(y+1, x+1) <= path2(y+1, x)) ret += count(y+1, x);
    return ret;
}