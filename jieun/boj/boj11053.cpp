//
// Created by songji on 2021/01/07.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    int arr[1001];
    int dp[1001];
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    // 길이는 최소 1
    int cnt = 1;
    for (int i=0; i<n; i++) {
        // 모든 index에 대해서 자기 자신 하나는 포함하므로 1로 초기화
        dp[i] = 1;
        for (int j=0; j<i; j++) {
            // 현재 arr[i] 왼쪽에 있는 숫자(arr[j])가 자기 자신(arr[i])보다 작다면 dp를 갱신
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        cnt = max(cnt, dp[i]);
    }
    cout << cnt;
}