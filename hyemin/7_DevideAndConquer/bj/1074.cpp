#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <cstdlib>


using namespace std;

int order = 0;

void countOrder (int row, int col, int size) {
    // cout << "row: " << row << " col: " << col << " size: " << size << " order: " << order << endl;
    int nextSize = size / 2;
    // 기저 사례 
    if ( size == 1 ) {
        return;
    }
    // 1사분면에 위치할 경우
    else if ( nextSize > row && nextSize > col ) {
        countOrder(row, col, nextSize);
    }
    // 2사분면에 위치할 경우
    else if ( nextSize > row && nextSize <= col ) {
        order += (int) pow(1.0 * nextSize, 2.0);
        countOrder(row, col - nextSize, nextSize);
    }
    // 3사분면에 위치할 경우
    else if ( nextSize <= row && nextSize > col ) {
        order += (int) 2 * pow(1.0 * nextSize, 2.0);
        countOrder(row - nextSize, col, nextSize);
    } 
    // 4사분면에 위치할 경우
    else {
        order += (int) 3 * pow(1.0 * nextSize, 2.0);
        countOrder(row - nextSize, col - nextSize, nextSize);
    }
}

int main() {
    int N, r, c;
    cin >> N >> r >> c ;

    countOrder(r, c, pow(2.0, 1.0 * N));

    cout << order << endl;
}