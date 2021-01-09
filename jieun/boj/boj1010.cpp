//
// Created by songji on 2021/01/07.
//

#include <iostream>

using namespace std;

int main() {
    int t;
    int dp[31][31] = {0, };

    for (int i=1; i<31; i++) {
        // 서쪽 다리 1개라면 다리는 동쪽 사이트 수만큼 존재
        dp[1][i] = i;
    }

    // 문제 조건에서 N<=M이므로
    for (int i=2; i<31; i++) {
        for (int j=i; j<31; j++) {
            for (int k=j-1; k>=i-1; k--) {
                dp[i][j] += dp[i-1][k];
            }
        }
    }

    cin >> t;
    for (int i=0; i<t; i++) {
        int n, m;
        cin >> n >> m;
        cout << dp[n][m] << "\n";
    }
}