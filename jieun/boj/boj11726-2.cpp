//
// Created by songji on 2021/01/07.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    int dp[1000];
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for (int i=3; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    cout << dp[n] % 10007;
}