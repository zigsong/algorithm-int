//
// Created by songji on 2020/11/12.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//#define MAX 25;
const int MAX = 25;

int n;
int map[MAX][MAX];
int visited[MAX][MAX];
int count = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<int> v;

void dfs(int x, int y) {
    count++;
    visited[x][y] = true;
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (map[nx][ny] == 1 && !visited[nx][ny]) dfs(nx, ny);
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        string row;
        cin >> row;
        for (int j=0; j<n; j++) {
            map[i][j] = row[j]-'0';
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                count = 0;
                dfs(i, j);
                v.push_back(count);
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << endl;

    for (int i=0; i<v.size(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}