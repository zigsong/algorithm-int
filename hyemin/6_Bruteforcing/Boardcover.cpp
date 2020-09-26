#include <string>
#include <vector>

using namespace std;

// 하나의 빈칸을 덮는 네가지 방법을 배열로 구현
const int coverType[4][3][2] = {
    {{0, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}},
};

// 블럭이 게임판 밖을 덮거나 겹치거나 검은 칸을 덮으면 false 반환
bool set(vector<vector<int>> &board, int y, int x, int type, int delta)
{
    bool ok = true;
    for (int i = 0; i < 3; i++)
    {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
        // 게임판 밖으로 나가는 경우
        if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
            ok = false;
        // 겹치거나 검은 칸을 덮는 경우
        else if ((board[ny][nx] += delta) > 1)
            ok = false;
    }
    return ok;
}

int cover(vector<vector<int>> &board)
{
    // 채우지 못한 가장 왼쪽 윗줄 좌표 찾기
    int y = -1, x = -1;
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
            // 덮이지 않았을 경우에 x,y좌표 설정
            if (board[i][j] == 0)
            {
                y = i;
                x = j;
                break;
            }
        if (y != -1)
            break;
    }
    //모든 칸 채웠으면 1 반환(마지막)
    if (y == -1)
        return 1;
    int ret = 0;
    for (int type = 0; type < 4; ++type)
    {
        // 설정된 y,x에서 type 방법으로 덮을 수 있으면 재귀 호출, 재귀 호출을 통해 반환된 ret 합산
        if (set(board, y, x, type, 1))
            ret += cover(board);
        // 덮었던 블록을 치운다
        set(board, y, x, type, -1);
    }
    return ret;
}