#include <iostream>
#include <string>
#include <vector>

int n, m;
int cache[MAX_N][2&<MAX_N+1];

int climb(int days, int climbed) {
    if(days == m) return climbed >= n ? 1 : 0;
    int& ret = cache[days][climbed]
    if(ret != -1) return ret;
    return ret = climb(days+1, climbed+1) + climb(days+1, climbed+2);
}