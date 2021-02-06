//
// Created by songji on 2021/01/14.
//

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

typedef pair<int, long long> pll;

// * 세그먼트 트리 + dp

int n, d;
deque<pll> dq;
long long val, curr, res = -1e9;

int main() {
    cin >> n >> d;
    for (int i=1; i<=n; i++) {
        cin >> val;
        // u와 v의 차이가 d 이상이면 후보에서 제거 (dq의 길이는 항상 d 이하로 유지 가능)
        while (!dq.empty() && dq.front().first + d < i) {
            dq.pop_front();
        }
        curr = max(val, val + dq.front().second);
        res = max(res, curr);
        // 현재 값보다 작은 점수가 있다면 제거
        while (!dq.empty() && dq.back().second <= curr) {
            dq.pop_back();
        }
        dq.push_back(pll(i, curr));
    }
    cout << res;
    return 0;
}
