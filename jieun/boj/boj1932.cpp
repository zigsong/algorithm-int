//
// Created by songji on 2021/01/07.
//

#include <iostream>

using namespace std;

const int MAX = 501;

int main() {
    int n;
    cin >> n;
    int dp[MAX][MAX];
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            cin >> dp[i][j];
        }
    }

    for (int i=1; i<n; i++) {
        for (int j=0; j<=i; j++) {
            if (j == 0) { // 좌측 끝
                dp[i][j] += dp[i-1][j];
            } else if (j == i) { // 우측 끝
                dp[i][j] += dp[i-1][j-1];
            } else { // 중간
                dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }

    int max = 0;
    int* lastRow = dp[n-1];
    for (int i=0; i<n; i++) {
        if (lastRow[i] > max) max = lastRow[i];
    }
    cout << max;
}