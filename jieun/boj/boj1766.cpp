//
// Created by songji on 2021/02/02.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 32000 + 1;
int inDegree[MAX];
vector<int> nums[MAX];
priority_queue<int, vector<int>, greater<int> > pq; // 작은 수부터 pop

int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        inDegree[b]++; // inDegree[b] = b보다 먼저 풀어야 하는 문제의 개수
        nums[a].push_back(b);
    }
    for (int i=1; i<=n; i++) {
        if (inDegree[i] == 0) { // 먼저 풀어야 할 문제가 있는 나중 문제는 pq에 넣지 않음
            pq.push(i);
        }
    }
    while (!pq.empty()) {
        int curr = pq.top(); // 문제 번호가 작은 것(쉬운 것)부터 출력
        pq.pop();

        cout << curr << " ";
        for (int i=0; i<nums[curr].size(); i++) {
            int next = nums[curr][i]; // curr보다 나중에 풀어야 하는 문제
            // 출력 초과 (테케는 통과)
//            if (inDegree[next] > 0) { // 먼저 풀어야 하는 문제가 있다면
//                pq.push(next); // pq에 넣어주고
//                inDegree[next]--; // inDegree에서는 배줌
//            }
            if (--inDegree[next] == 0) {
                pq.push(next);
            }
        }
    }
}
