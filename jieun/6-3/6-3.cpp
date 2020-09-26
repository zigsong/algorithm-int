#include <iostream>
#include <vector>

using namespace std;

// dx, dy pairs
const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0}; 
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1};

int board[8][8];

bool inRange(int y, int x) {
  return 0<=y && y<8 && 0<=x && x<8;
}

bool hasWord(int y, int x, const string& word) {
  if(!inRange(y, x)) return false;
  if(board[y][x] != word[0]) return false;
  if(word.size() == 1) return true;
  
  for(int direction=0; direction<8; ++direction) { // 상하좌우, 대각선 4방향 총 8개 방향으로 탐색
    int nextY = y + dy[direction], nextX = x + dx[direction];
    if(hasWord(nextY, nextX, word.substr(1)))
      return true;
  }
}
