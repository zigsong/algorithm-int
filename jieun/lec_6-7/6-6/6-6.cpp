#include <iostream>
#include <vector>

using namespace std;

// 같은 원점에서 4가지 방향으로 L자 블록을 놓을 수 있는 경우의 수 = 4
const int coverType[4][3][2] = {
  { {0, 0}, {1, 0}, {0, 1} },
  { {0, 0}, {0, 1}, {1, 1} },
  { {0, 0}, {1, 0}, {1, 1} },
  { {0, 0}, {1, 0}, {1, -1} }
};

bool set(vector<vector<int>>& board, int y, int x, int type, int delta) {
  bool ok = true;`
  for (int i=0; i<3; ++i) {
    const int ny = y + coverType[type][i][0];
    const int nx = x + coverType[type][i][1];
    if (ny<0 || ny>=board.size() || nx < 0 || nx>=board[0].size()) ok = false;
    else if ((board[ny][nx] += delta) > 1) ok = false; // 이미 덮인 칸(board[y][x]=1)인데 또 덮으려(delta=1)할 때 or 검은 칸에 덮으려고 할 때
  }

  return ok;
}

int cover(vector<vector<int>>& board) {
  int y = -1, x = -1; // 빈 칸들 중 가장 윗줄 윗쪽의 칸 
  for (int i=0; i<board.size(); ++i) {
    for (int j=0; j<board[i].size(); ++j) {
      if (board[i][j] == 0) {
        y = i;
        x = j;
        break; // 빈 칸이 있으면 내부 for loop 탈출
      }
    }
    if (y != -1) break; // 빈 칸이 있고, 그게 가장 윗줄이 아니라면 외부 for loop 탈출 -> 현재 y가 가장 윗줄이 아니므로 현재 y줄을 새로운 윗줄 삼아 재귀호출을 계속하여 ret에 저장
  }

  if (y == -1) return 1; // base case - 위의 이중 for loop에서 빈칸을 찾지 못함. 즉 모든 칸을 채웠을 경우
  int ret = 0;
  for (int type=0; type<4; ++type) {
    if (set(board, y, x, type, 1)) ret += cover(board); // 1. 동작 실행, 2. 재귀 호출
    set(board, y, x, type, -1); // 3. 동작 취소
  }
  return ret;
}

