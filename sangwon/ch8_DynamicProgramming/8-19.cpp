#include <iostream>
#include <string>
#include <vector>

int asymmetric(int width) {
    if(width % 2 == 1)
        return(tiling(width) - tiling(width/2) + MOD) & MOD;
    int ret = tiling(width);
    ret = (ret - tiling(width/2) + MOD) % MOD;
    ret = (ret - tiling(width/2 - 1) + MOD) % MOD;
    return ret;
}