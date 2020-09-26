// 로직만 쳐보면서 공부!
#include <string>
#include <vector>

using namespace std;

const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

bool hasWord(int y, int x, const string &word)
{
    // 좌표가 범위에 있지 않으면 false 반환. isRange함수가 정의되어 있지 않다 ...
    if (!inRange(y, x))
        return false;
    // 단어 시작이 틀리면 false 반환
    if (board[y][x] != word[0])
        return false;
    // 1글자짜리 단어면 true
    if (word.size() == 1)
        return true;
    // 주위 8방향 모두 탐색하고 true가 반한되면 재귀 호출
    for (int direction = 0; direction < 8; ++direction)
    {
        int nextY = y + dy[direction], nextX = x + dx[direction];
        if (hasWord(nextY, nextX, word.substr(1)))
            return true;
    }
    // 8방향 모두 false면 false
    return false;
}
