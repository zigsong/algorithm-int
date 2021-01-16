//
// Created by songji on 2021/01/14.
//

#include <iostream>
#include <stack>

using namespace std;

// * 항상 각 줄에는 프렛의 오름차순으로 정렬되어 있음

int main() {
    int n, p;
    cin >> n >> p;
    stack<int> s[7]; // 줄 1~6 (이중 배열 느낌)
    int res = 0;

    for (int i=0; i<n; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;

        if (s[p.first].empty()) {
            res++;
            s[p.first].push(p.second);
        }
        // 현재 input이 가장 높은 음이라면
        else if (p.second > s[p.first].top()) {
            s[p.first].push(p.second);
            res++;
        }
        else if (p.second == s[p.first].top()) continue;
        else {
            while (!s[p.first].empty() && p.second < s[p.first].top()) {
                s[p.first].pop();
                res++;
            }
            // 이미 있다면
            if (!s[p.first].empty() && s[p.first].top() == p.second) continue;
            else {
                s[p.first].push(p.second);
                res++;
            }
        }
    }

    cout << res;
    return 0;
}