//
// Created by songji on 2020/11/17.
//

#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int bfs(const vector<int>& perm) {
    int n = perm.size();
    // 목표 정점을 미리 계산 -> 우리가 구하는 건 "몇 번 뒤집는가"이기 때문에
    vector<int> sorted = perm;
    sort(sorted.begin(), sorted.end());
    // 방문 목록
    queue<vector<int> > q;
    // 시작점부터 각 정점까지의 거리
    map<vector<int>, int> distance;

    distance[perm] = 0;
    q.push(perm);
    while(!q.empty()) {
        vector<int> here = q.front();
        q.pop();
        // 목표 정점을 발견했으면(here가, sort된 마지막 상태라면!) 곧장 종료
        if (here == sorted) return distance[here];
        int cost = distance[here];

        for (int i=0; i<n; ++i) {
            for (int j=i+2; j<=n; ++j) {
                // reverse(first, last) - first부터 last의 바로 전 index까지
                reverse(here.begin()+i, here.begin()+j);
                // here의 거리가 아직 계산되지 않았다면
                if (distance.count(here) == 0) {
                    distance[here] = cost + 1;
                    q.push(here);
                }
                reverse(here.begin()+i, here.begin()+j);
            }
        }
    }
    return -1;
}

// 29-4
// 미리 정렬해 놓은 그래프 toSort를 보고 거꾸로 타고 올라가겠다! -> 양방향 탐색
map<vector<int>, int> toSort;
// [0, ..., n-1]의 모든 순열에 대해 toSort[]를 계산해 저장 -> 접근에 시간이 오래 걸리는 map 대신 사용
// [0, ..., n-1]에서 몇 개씩을 뽑아서 만든 순열들에 대해서 미리 계산
void precalc(int n) {
    vector<int> perm(n);
    for (int i=0; i<n; ++i) perm[i] = i;
    queue<vector<int> > q;
    q.push(perm);
    toSort[perm] = 0;
    while(!q.empty()) {
        vector<int> here = q.front();
        q.pop();
        int cost = toSort[here];
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<=n; ++j) {
                reverse(here.begin()+i, here.begin()+j);
                if (toSort.count(here) == 0) {
                    toSort[here] = cost + 1;
                    q.push(here);
                }
                reverse(here.begin()+i, here.begin()+j);
            }
        }
    }
}

// [3, 4, 1, 2]도 [2, 3, 0, 1]이 되고, [30, 40, 10, 20]도 [2, 3, 0, 1]
// 나보다 작은 원소가 몇 개인지
// 3보다 작은 건 1,2이므로 3 -> 2
// 4보다 작은 값은 1,2,3이므로 4 -> 3
// 1보다 작은 값은 0개 따라서 1 -> 0
// 2보다 작은 값은 1이므로 2 -> 1
int solve(const vector<int>& perm) {
    int n = perm.size();
    vector<int> fixed(n);
    for (int i=0; i<n; ++i) {
        int smaller = 0;
        for (int j=0; j<n; ++j) {
            if (perm[j] < perm[i]) ++smaller;
        }
        fixed[i] = smaller;
    }
    return toSort[fixed];
}