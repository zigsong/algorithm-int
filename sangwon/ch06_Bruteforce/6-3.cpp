#include <iostream>
#include <string>
#include <vector>

// 보글 게임판에서 단어를 찾는 재귀 호출 알고리즘
const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0}
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1}

//참조형 변수
// 5x5의 보글 게임 판의 해당 위치에서 주어진 단어가 시작하는지를 반환
bool hasWord(int y, int x, const string& word) {
    if(!inRange(y, x)) return false;
    if(board[y][x] != word[0]) return false;

    if(word.size() == 1) return true;
    
    for(int direction = 0; direction < 8; ++direction) {
        int nextY = y + dy[direction], nextX = x + dx[direction];

        if(hasWord(nextY, nextX, word.substr(1))) 
            return true;
    }
    return false;
}