#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <cstdlib>


using namespace std;

int paper[2187][2187];
int countPaper[3] = {0, 0, 0};


bool isUniform(int row, int col, int size) {
    for(int i = row; i < row + size; i++) {
        for(int j = col; j < col + size; j++) {
            // 왼쪽 위의 점과 현재 점이 다르면
            if (paper[row][col] != paper[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void devideAndConquer(int row, int col, int size) {
    if (isUniform(row, col, size)) {
        countPaper[paper[row][col]]++;
    }
    
    else {
        int newSize = size / 3;
        for(int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                devideAndConquer(row + i * newSize, col + j * newSize, newSize);
            }
        }

    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            // 0, 1, 2로 저장해서 count하기 편하게
            paper[i][j] = input + 1;
        }
    }
    

    devideAndConquer(0, 0, n);

    for (int i = 0; i < 3; i++) {
        cout << countPaper[i] << endl;
    }


}