//
// Created by songji on 2020/12/29.
//
#include <iostream>

using namespace std;

const int MAX_N = 2188;
int N;
int paper[MAX_N][MAX_N];
int cnt[3]; // -1, 0, 1

bool check(int x, int y, int n) {
    int flag = paper[x][y];
    for (int i=x; i<x+n; i++) {
        for (int j=y; j<y+n; j++) {
            if (paper[i][j] != flag) return false;
        }
    }
    return true;
}

void solve(int x, int y, int n) {
    if (check(x, y, n)) {
        cnt[paper[x][y]+1]++;
        return;
    }

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            solve(x+i*n/3, y+j*n/3, n/3);
        }
    }
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> paper[i][j];
        }
    }

    solve(0, 0, N);

    cout << cnt[0] << "\n";
    cout << cnt[1] << "\n";
    cout << cnt[2] << "\n";
}