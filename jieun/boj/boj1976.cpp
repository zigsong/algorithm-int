//
// Created by songji on 2021/02/19.
//

#include <iostream>

using namespace std;

const int MAX_N = 201;
const int MAX_M = 1001;

int parent[MAX_N];
int path[MAX_M];

int find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[y] = x;
    }
}


int main() {
    int n, m;
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        parent[i] = i;
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int connected;
            cin >> connected;
            if (connected) {
                merge(i, j);
            }
        }
    }

    for (int i=1; i<=m; i++) {
        cin >> path[i];
    }

    for (int i=1; i<m; i++) {
        if (find(path[i]) != find(path[i + 1])) {
            cout << "NO" << "\n";
            return 0;
        }
    }

    cout << "YES" << "\n";
    return 0;
}