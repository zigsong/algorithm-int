const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0}
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1}

//참조형 변수

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