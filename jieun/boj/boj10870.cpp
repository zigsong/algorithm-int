//
// Created by songji on 2020/12/23.
//
#include <iostream>

using namespace std;

int fibo(int num) {
    if (num == 0 || num == 1) return num;
    else {
        return fibo(num-1) + fibo(num-2);
    }
}

int main() {
    int n, res;
    cin >> n;
    res = fibo(n);
    cout << res;
}