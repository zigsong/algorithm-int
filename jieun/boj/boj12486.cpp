//
// Created by songji on 2021/01/01.
//
#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &arr, int left, int right) {
    if (left == right) return arr[left];
    int mid = (left + right) / 2;
    int ret = max(solve(arr, left, mid), solve(arr, mid+1, right));
    int lo = mid, hi = mid+1;
    int p = min(arr[lo], arr[hi]);
    ret = max(ret, p*2);
    while (left < lo || hi < right) {
        // 페이가 더 큰 쪽으로 확장
        if (hi < right && (lo == left || arr[lo-1] < arr[hi+1])) {
            ++hi;
            p = min(p, arr[hi]);
        } else {
            --lo;
            p = min(p, arr[lo]);
        }
        ret = max(ret, p*(hi-lo+1));
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    vector<int> pay(n);
    for (int i=0; i<n; i++) {
        cin >> pay[i];
    }
    cout << solve(pay, 0, n-1);
}