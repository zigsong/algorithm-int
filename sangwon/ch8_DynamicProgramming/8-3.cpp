#include <iostream>
#include <string>
#include <vector>

int cache[2500][2500];

int someObscureFunction(int a, int b) {
    if (...) return ...;
    int& ret = cache[a][b];
    if(ret != -1) return ret;

    ...
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
}