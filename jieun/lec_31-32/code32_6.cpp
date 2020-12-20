//
// Created by songji on 2020/12/17.
//

#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

const int dx[4] = { 1, -1, 0, 0};
const int dy[4] = { 0, 0, 1, -1};
const int MAX_N = 100, MAX_M = 100;
// (y, x)가 직사각형 범위 안의 칸인지 확인
bool inRange(int y, int x);
int n, m;
int H, W;
bool adj[MAX_N][MAX_M];

vector<string> board;

int bipartiteMatch();

bool fillDomino() {
    vector<vector<int> > id(H, vector<int>(W, -1));
    n = m = 0;
    for (int y=0; y<H; ++y) {
        for (int x=0; x<W; ++x) {
            if (board[y][x] != '#') {
                if ((y+x) % 2 == 0) { // 짝수 칸이면
                    id[y][x] = n++; // 흰색으로 덮
                } else { // 홀수 칸이면
                    id[y][x] = m++; // 검은색으로 덮
                }
            }
        }
    }

    memset(adj, 0, sizeof(adj));
    for (int y1=0; y1<H; ++y1) {
        for (int x1=0; x1<W; ++x1) {
            if ((y1+x1)%2 == 0 && board[y1][x1] != '#') { // 짝수 칸, 흰색 덮
                for (int k=0; k<4; ++k) { // 현재 칸 상하좌우로 검사
                    int y2= y1 + dy[k], x2 = x1 + dx[k];
                    if (inRange(y2, x2) && board[y2][x2] != '#') { // 상하좌우 중 현재 칸이 보드 내에 있고, 검은 덮이라면(현재 짝수-흰 칸이므로)
                        adj[id[y1][x1]][id[y2][x2]] = 1; // 인접하는 것으로 체크
                    }
                }
            }
            // 이렇게 흰 칸들(짝수 칸)에 대해서만 상하좌우 인접 검사하고 나면 검은 칸(홀수 칸)들은 알아서 매칭되나 봄
        }
    }
    return bipartiteMatch() * 2 == (n+m);
}