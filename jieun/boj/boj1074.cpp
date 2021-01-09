//
// Created by songji on 2021/01/02.
//
#include <iostream>
#include <cmath>

using namespace std;

int order = 0;

void solve(int r, int c, int size) {
    if (size == 1) return;
    if (r < size/2 && c < size/2) { // 1사분면
        solve(r, c, size/2);
    } else if (r < size/2 && c >= size/2) { // 2사분면
        order += pow(size/2, 2);
        solve(r, c-size/2, size/2);
    } else if (r >= size/2 && c < size/2) { // 3사분면
        order += 2 * pow(size/2, 2);
        solve(r-size/2, c, size/2);
    } else { // 4사분면
        order += 3 * pow(size/2, 2);
        solve(r-size/2, c-size/2, size/2);
    }
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;
    solve(r, c, pow(2, N));
    cout << order << "\n";
}