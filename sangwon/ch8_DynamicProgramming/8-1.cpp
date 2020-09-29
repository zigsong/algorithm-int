#include <iostream>
#include <string>
#include <vector>

int bino(int n, int r) {
    if (r == 0 || n == r) return 1;
    return bino(n-1, r-1) + bino(n-1, r);
}