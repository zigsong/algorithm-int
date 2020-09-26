#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <numeric>
#include <iostream>

using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

const char linked[SWITCHES][CLOCKS + 1] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."};

// 모든 시계가 같은 방향인지 확인
bool areAligned(const vector<int> &clocks);

// clocks: 현재 시계들이 가리키는 시간
// swtch : 시계를 누르는 횟수
void push(vector<int> &clocks, int swtch)
{
    for (int clock = 0; clock < CLOCKS; ++clock)
        // 스위치와 시계가 연결되어 있으면 90도 회전
        if (linked[swtch][clock] == 'x')
        {
            clocks[clock] += 3;
            if (clocks[clock] == 15)
                clocks[clock] = 3;
        }
}

// clocks: 현재 시계들이 가리키는 시간
// swtch : 이번에 누를 시위치의 번호! push의 swtch와 다름!!
// 남은 스위치 눌러서 12시로 맞출 수 있는 최소 횟수 반환
// 불가능하면 INF이상의 큰 수 반환
int solve(vector<int> &clocks, int swtch)
{
    // 기저 사례 : 마지막 스위치(10번)를 눌렀을 때 정렬되어 있으면 0, 아니면 INF 반환
    if (swtch == SWITCHES)
        return areAligned(clocks) ? 0 : INF;
    // 마지막 스위치가 아닐 경우
    int ret = INF;
    // 하나의 스위치를 1~4번 누르는 경우에 대해 최소 ret 계산
    for (int cnt = 0; cnt < 4; ++cnt)
    {
        //매 단계의 ret 값은 재귀 호출을 통해 반환된 최소값에 현재 누른 cnt값의 합! 단계마다 쌓아나감
        ret = min(ret, cnt + solve(clocks, swtch + 1));
        push(clocks, swtch);
    }
    return ret;
}
