//
// Created by songji on 2020/12/31.
//
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

void init(vector<int> &arr, vector<int> &tree, int node, int start, int end) {
    // leaf node
    if (start == end) {
        tree[node] = start;
    } else {
        int mid = (start + end) / 2;
        init(arr, tree, node*2, start, mid);
        init(arr, tree, node*2+1, mid+1, end);

        // 각 구간에서 가장 높이가 낮은 것을 노드에 넣어준다.
        if (arr[tree[node*2]] <= arr[tree[node*2+1]]) {
            tree[node] = tree[node*2];
        } else {
            tree[node] = tree[node*2+1];
        }
    }
}

// 구간에서 가장 최소인 높이의 막대 구하기
int query(vector<int> &arr, vector<int> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return -1;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    int m1 = query(arr, tree, node*2, start, mid, left, right);
    int m2 = query(arr, tree, node*2+1, mid+1, end, left, right);

    if (m1 == -1) return m2;
    else if (m2 == -1) return m1;
    // 두 자식 구간 중 작은 값 리턴
    else {
        if (arr[m1] <= arr[m2]) return m1;
        else return m2;
    }
}

ll getMax(vector<int> &arr, vector<int> &tree, int start, int end) {
    int n = arr.size();
    int m = query(arr, tree, 1, 0, n-1, start, end);

    ll area = (ll)(end - start + 1)*(ll)arr[m];
    // 왼쪽으로 확장
    if (start <= m-1) {
        ll tmp = getMax(arr, tree, start, m-1);
        if (area < tmp) area = tmp;
    }
    // 오른쪽으로 확장
    if (m+1 <= end) {
        ll tmp = getMax(arr, tree, m+1, end);
        if (area < tmp) area = tmp;
    }

    return area;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<int> arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }

        // seg tree의 크기
        int h = (int)(ceil(log2(n)));
        int tree_size = pow(2, h) * 2;

//        cout << tree_size << "\n";

        vector<int> tree(tree_size);

        init(arr, tree, 1, 0, n-1);

        cout << getMax(arr, tree, 0, n-1) << "\n";
    }
}