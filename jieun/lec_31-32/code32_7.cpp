//
// Created by songji on 2020/12/17.
//
#include <vector>
#include <string>
#include <string.h>

using namespace std;

const int dx[2] = { -1, 1 };
const int dy[2] = { 1, 1 };

vector<string> board;
// id[dir][y][x] = dir방향 대각선을 따라 인접한 빈 칸 묶음들 중 (y,x)가 속한 묶음의 번호
int id[2][8][8];
// 이분 그래프의 정보
int n, m;
int adj[64][64];
// 최대 매칭의 크기 반환
int bipartiteMatch();
int placeBishops() {
    memset(id, -1, sizeof(id));
    int count[2] = { 0, 0 };
    for (int dir=0; dir<2; ++dir) {
        for (int y=0; y<board.size(); ++y) {
            for (int x=0; x<board.size(); ++x) {
                if (board[y][x] == '.' && id[dir][y][x] == -1) { // 빈칸이고 아직 안 묶였을 때 (id=-1)
                    int cy = y, cx = x;
                    // 보드 범위 내에 있고, 빈 칸이라면
                    while (0 <= cy && cy < board.size() && 0 <= cx && cx < board.size() && board[cy][cx] == '.') {
                        id[dir][cy][cx] = count[dir];
                        cy += dy[dir];
                        cx += dx[dir];
                    }
                    // 현재 그룹에 속한 원소 개수를 늘려 줌
                    count[dir]++;
                }
            }
        }
    }

    n = count[0]; // 왼쪽 아래 방향의 대각선에 놓인 비숍의 개수
    m = count[1]; // 오른쪽 아래 방향의 대각선에 놓인 비숍의 개수
    memset(adj, 0, sizeof(adj));
    for (int y=0; y<board.size(); ++y) {
        for (int x=0; x<board.size(); ++x) {
            if (board[y][x] == '.') {
                // 연결된 애들끼리 맺어 줌
                adj[id[0][y][x]][id[1][y][x]] = 1;
            }
        }
    }

    return bipartiteMatch();
}