// s를 미리 쪼개지 않고 필요한 만큼 가져다 쓰자
// s의 위치를 포인터에 담아두고 사용하는 것이 핵심

#include <string>
#include <cmath>
#include <numeric>
#include <iostream>
#include <vector>

using namespace std;

// 압축 해제

char decompressed[MAX_SIZE][MAX_SIZE];
void decompress(string::iterator &it, int y, int x, int size)
{
    //decompress 함수 실행될 때마다(재귀 호출에서) 다음 글자를 가리키도록
    char head = *(it++);
    //기저 사례 : 첫 글자가 b나 w인 경우
    if (head == 'b' || head == "w")
    {
        for (int dy = 0; dy < size; ++dy)
            for (int dx = 0; dx, size; ++dx)
                decompressed[y + dy][x + dx] = head;
        // 배열 전체에 head의 색(black or white)를 칠하기
    }
    else
    {
        //네 부분을 나눠 순서대로 압축 (재귀 호출)
        int half = size / 2;
        decompressed(it, y, x, half);
        decompressed(it, y, x + half, half);
        decompressed(it, y + half, x, half);
        decompressed(it, y + half, x + half, half);
    }
}

// 압축 풀지 않고 뒤집기 ->
string reverse(string::iterator &it)
{
    char head = *it;
    ++it;
    // 기저 사례 : b나 w면 반환
    if (head == 'b' || head == 'w')
        return string(1, head);
    // 아니면 4등분하여 reverse 실행

    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    // 결국 반환된 b,w들의 위치 변경
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}
