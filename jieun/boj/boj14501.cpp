//
// Created by songji on 2021/01/07.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    // T[i] = 일 기간, P[i] = 일 페이, dp[i] = i일까지 얻을 수 있는 페이
    int T[16], P[16], dp[16];
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> T[i] >> P[i];
        // 초기화: dp[i] = i일에 일한 페이
        dp[i] = P[i];
    }

    int result = 0;

    for (int i=2; i<=n; i++) {
        for (int j=1; j<i; j++) {
            // 기준일부터 수행 기간을 더한 값이 현재 날짜를 넘어가지 않는다면
            if (i-j >= T[j]) {
                dp[i] = max(dp[i], P[i]+dp[j]);
            }
        }
    }

    for (int i=1; i<=n; i++) {
        // i일에 시작한 일을 퇴사 전(<=n+1)까지 끝낼 수 있는 경우들에 대해서만 result를 갱신
        if (i+T[i] <= n+1) {
            result = max(result, dp[i]);
        }
    }

    cout << result;
}