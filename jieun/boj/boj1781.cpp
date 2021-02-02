//
// Created by songji on 2021/02/02.
//

// 그리디 알고라즘, 우선순위 큐 이용
// 1. 데드라인 기준으로 내림차순 정렬
// 2. 데드라인 기준으로 우선순위 큐(힙)에 담기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int> > v;
priority_queue<int> pq;
int ret;

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int d, r;
        cin >> d >> r;
        v.push_back(make_pair(d, r));
        v[i].first--; // 인덱싱 편하게 하기 위해서 (0~n-1로 접근하기 위해서)
    }
    // 데드라인 순으로 오름차순 정렬 (밑의 for문에서 뒤에서부터 접근할 예정)
    sort(v.begin(), v.end());
    int j = n-1; // 한 번씩만 체크하여 큐에 담기 위해서

    for (int i=n-1; i>=0; i--) {
        // 같은 데드라인의 문제들 (v[j].first == i)
        for (; j>=0 && v[j].first==i; j--) {
            pq.push(v[j].second); // 라면 담기 
        }
        if (!pq.empty()) {
            ret += pq.top();
            pq.pop();
        }
    }

    cout << ret;
}
