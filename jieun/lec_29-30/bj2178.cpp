//
// Created by songji on 2020/11/17.
//
#include <cstdio>
#include <queue>

using namespace std;

int maze[101][101];
int dir[4][2] = {{1,0}, {-1,0}, {0, 1}, {0, -1}};
int n, m;
queue<pair<int, int> > q;

void bfs() {
    q.push(make_pair(0, 0));
    pair<int, int> curr;
    int nx, ny;

    while(!q.empty()) {
        curr = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            nx = curr.second + dir[i][0];
            ny = curr.first + dir[i][1];
            // 이동 가능한 곳 (maze[x][y] = 1)
            if (0 <= nx && nx < m && 0 <= ny && ny < n && maze[nx][ny] == 1) {
                q.push(make_pair(ny, nx));
                maze[ny][nx] = maze[curr.first][curr.second] + 1;
            }
        }
    }

    return;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            // 정수 1자리씩 입력받기
            scanf("%1d", &maze[i][j]);
        }
    }

    bfs();
    printf("%d", maze[n-1][m-1]);

}
