//
// Created by songji on 2020/12/23.
//
#include <iostream>

using namespace std;

int fact(int num) {
    if (num > 2) {
        num *= fact(num-1);
        return num;
    }
}

// 0! = 1 이라니 ...
int main() {
    int n, res = 1;
    cin >> n;
    if (n != 0) {
        res = fact(n);
    }
    cout << res;
}