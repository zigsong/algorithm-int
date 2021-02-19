//
// Created by songji on 2021/02/17.
//

#include <iostream>

using namespace std;

const int MAX = 1000001;
int parent[MAX];

int find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    // x, y의 루트 찾기
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[y] = x;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<=n; i++) {
        parent[i] = i;
    }

    for (int i=0; i<m; i++) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        if (cmd == 0) {
            merge(x, y);
        } else if (cmd == 1) {
            if (find(x) == find(y)) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }
}