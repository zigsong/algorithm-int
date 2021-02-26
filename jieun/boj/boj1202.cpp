//
// Created by songji on 2021/02/26.
//
// 그리디 알고리즘: 가장 비싼 보석부터 선택?
// 보석 가격 기준 max heap

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 300000;

// n: 보석점의 보석 개수
// k: 가방 개수
// mi: 보석 무게
// vi: 보석 가격
// ci: 각 가방에 담을 수 있는 최대 무게
int n, k;
pair<int, int> jewelry[MAX]; // 무게, 가격
int bags[MAX]; // 가방 무게
priority_queue<int> pq; // 보석 가격 기준 최대 힙

int main() {
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        int m, v;
        cin >> jewelry[i].first >> jewelry[i].second;
    }
    for (int i=0; i<k; i++) {
        int c;
        cin >> bags[i];
    }

    sort(jewelry, jewelry + n); // 보석 무게 기준 오름차순
    sort(bags, bags + k); // 가방 최대 무게 기준 오름차순

    long long ans = 0;
    int idx = 0;
    // 무게 제한이 낮은 가방부터 최대한 비싼 보석 넣기
    for (int i=0; i<k; i++) {
        while (idx < n && jewelry[i].first <= bags[i]) {
            pq.push(jewelry[idx++].second);
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << "\n";
}