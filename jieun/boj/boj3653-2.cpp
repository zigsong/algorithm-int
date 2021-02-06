//
// Created by songji on 2021/02/04.
//
// https://www.acmicpc.net/blog/view/9
// 시간 초과?

#include <iostream>
#include <vector>

using namespace std;

vector<int> tree, arr;

// arr[idx] = diff로 바뀔 때 node를 루트로 하는 구간 트리를 갱신하고 노드가 표현하는 구간의 최소치를 반환
void update(int node, int start, int end, int idx, int diff) {
    if (idx < start || idx > end) return; // 범위 밖
    tree[node] += diff;
    if (start^end) { // bit xor 연산자 - 둘 중에 하나만 1일 때만 1 -> 리프 노드인지 검사
        update(node*2, start, (start+end)/2, idx, diff); // 왼쪽 구간 업데이트
        update(node*2+1, (start+end)/2+1, end, idx, diff); // 오른쪽 구간 업데이트
    }
}

// node가 담당하는 구간이 start~end이고, 구해야하는 합의 범위는 left~right
int sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) { // 범위 밖
        return 0; // 아무것도 더하지 않음
    }
    if (left <= start && end <= right) {
        return tree[node]; // 리프 노드
    }
    // 좌우 자식 트리로 나눠서 탐색
    return sum(node*2, start, (start+end)/2, left, right) + sum(node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        arr = vector<int>(n+m+1);
        tree = vector<int>(4*(n+m+1)); // 트리의 크기를 넉넉하게

        for (int i=m+1; i<=n+m; i++) { // 배열의 뒤쪽만 일단 채워줌
            update(1, 1, n+m, i, 1); // 1을 루트로 하는 트리의 i번째 노드에 1을 저장(dvd 유)
            arr[i-m] = i; // arr에도 dvd를 저장 (i-m은 항상 1 - dvd의 존재 여부만 저장)
        }
        int idx = m; // 초기의 m의 위치는 m번째 인덱스

        for (int i=0; i<m; i++) { // 아직 비어 있는 임시 칸들
            int v;
            cin >> v;
            cout << sum(1, 1, n+m, 1, arr[v]-1) << " "; // 현재 칸 왼쪽(위쪽)으로 몇 개의 dvd가 있는지
            update(1, 1, n+m, arr[v], -1); // arr[v]에서 dvd를 빼줌
            arr[v] = idx--; // arr에서 v의 위치는 점점 앞으로(=위로)
            update(1, 1, n+m, arr[v], 1); // 바뀐 노드를 tree에도 업데이트
        }
        cout << "\n";
    }
}