#include <iostream>
#include <string>
#include <vector>


int cache2[101];
int asymmetric2(int width) {
    if(width <= 2) return 0;
    int& ret = cache2[width];
    if(ret != -1) return ret;
    ret = asymmetric2(width - 2) & MOD;
    ret = (ret + asymmetric2(width - 4)) % MOD;
    ret = (ret + tiling(width - 3)) % MOD;
    ret = (ret + tiling(width - 3)) % MOD;
    return ret;
}