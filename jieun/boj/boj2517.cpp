//
// Created by songji on 2021/02/05.
//
// https://jaimemin.tistory.com/1476
// https://kibbomi.tistory.com/159

// i번째 선수에 대하여, 그 사람보다 앞에 있는 사람들 즉 (0, i) 구간의 사람들 중
// 자신보다 능력이 높은 사람의 수 + 1 = 본인의 최선의 등수

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 500001; // input이 너무 큼. for loop을 사용하면 시간복잡도 N^2

vector<pair<int, int> > runners; // pair<rank, capacity>
vector<int> tree;

bool comp_capacity(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second; // 살력이 좋은 순으로 정렬
}

bool comp_rank(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first; // 등수가 낮은 순으로 정렬
}

// 자신보다 앞서 뛴 선수들 중 자기보다 실력이 안 좋은 선수들의 수를 확인한 뒤 등수를 출력
int query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) { // 범위 밖
        return 0; // 아무것도 더하지 않음
    }
    if (left <= start && end <= right) {
        return tree[node]; // 리프 노드
    }
    // 좌우 자식 트리로 나눠서 탐색
    return query(node*2, start, (start+end)/2, left, right) + query(node*2+1, (start+end)/2+1, end, left, right);
}

// 현재 선수의 실력 업데이트
int update(int node, int start, int end, int idx) {
    if (idx < start || idx > end) return tree[node]; // 범위 밖이면 값 업데이트 없이 그냥 리턴
    if (start == end) { // 범위에 포함되는 리프 노드라면
        tree[node] += 1; // 1 더하고 해당 노드 리턴
        return tree[node];
    }
    return tree[node] = update(node*2, start, (start+end)/2, idx) + update(node*2+1, (start+end)/2+1, end, idx); // 왼쪽, 오른쪽 구간 업데이트
}

int main() {
    int n;
    cin >> n;
    runners.resize(n);

    for (int i=0; i<n; i++) {
        runners[i].first = i; // rank
        cin >> runners[i].second;
    }
    sort(runners.begin(), runners.end(), comp_capacity); // 실력이 큰 순으로 정렬

    // 좌표 압축 - 상대적인 능력에 따라 배치
    for (int i=0; i<n; i++) {
        runners[i].second = i; // 능력이 가장 높은 사람의 순서가 제일 뒤로 밀려남
    }
    sort(runners.begin(), runners.end(), comp_rank); // 등수가 작은 순으로 정렬

    int h = (int)ceil(log2(n)); // segment tree 높이 계산
    int tree_size = 1 << (h+1); // *4
    tree = vector<int>(tree_size);

    for (int i=0; i<n; i++) {
        int front = 0;
        front = query(1, 0, n-1, 0, runners[i].second); // 내 앞에 몇 명 있는지?
        cout << front+1 << "\n"; // 0부터 인덱싱했으므로 1 더해서 출력
        update(1, 0, n-1, runners[i].second); // 트리 업데이트
    }
}