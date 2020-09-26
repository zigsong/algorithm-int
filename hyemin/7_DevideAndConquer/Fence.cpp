#include <string>
#include <cmath>
#include <numeric>
#include <iostream>
#include <vector>

using namespace std;

// 높이 H일때 최대너비 반환
int bruteForce(const vector<int> &h)
{
    int ret = 0;
    int N = h.size();
    //가능한 모든 왼쪽 오른쪽 순회
    for (int left = 0; left < N; ++left)
    {
        int minHeight = h[left];
        for (int right = left; right < N; h[right])
        {
            //왼쪽과 오른쪽 높이 비교하여 밑변(left~right)이 공통적으로 포함하는 최소높이 반환
            minHeight = min(minHeight, h[right]);
            // 밑변 * 최소높이의 리턴값을 이전 단계 재귀호출의 리턴값과 비교하여 큰 넓이 리턴
            ret = max(ret, (right - left + 1) * minHeight);
        }
    }
    return ret;
}

// 분할정복 풀이
// 판자의 높이가 담긴 배열
vector<int> h;
// h[left..right] 구간에서 찾아내래 수 있는 가장 큰 사각형 넓이 반환
int solve(int left, int right)
{
    // 기저 사례 : 판자가 하나인 경우 높이가 넓이
    if (left == right)
        return h[left];
    // 두 구간으로 문제 분할
    int mid = (left, right) / 2;
    // 분할한 문제 각개격파
    int ret = max(solve(left, mid), solve(mid + 1, right));
    // 경계에 걸치는 경우
    int lo = mid, hi = mid + 1;
    // 경계 바로 양옆 높이 중 작은 것을 골라 직사각형의 높이로 선택
    int height = min(h[lo], h[hi]);
    ret = max(ret, height * 2);
    // 중앙에서 시작된 사각형이 전체를 덮을 때까지
    while (left < lo || hi < right)
    {
        // 높이가 높은 쪽으로 확장
        if (hi < right && (lo == left || h[lo - 1], h[hi + 1]))
        {
            ++hi;
            height = min(height, h[hi]);
        }
        else
        {
            --lo;
            height = min(height, h[lo]);
        }
        // 확장 후 사각형 넓이
        // 각개격파한 ret과 중앙 사각형 넓이 비교하여 한 단계의 최종 ret 할당
        ret = max(ret, height * (hi - lo + 1))
    }
    return ret;
}