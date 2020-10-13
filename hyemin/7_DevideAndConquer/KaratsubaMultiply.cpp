#include <string>
#include <cmath>
#include <numeric>
#include <iostream>
#include <vector>

using namespace std;

// a += b*(10^k) 구현
void addTo(vector<int> &a, const vector<int> &b, int k);
// a -+ b 구현
void subFrom(vector<int> &a, const vector<int> &b);

// 두 긴 정수의 곱을 반환
vector<int> karatsuba(const vector<int> &a, const vector<int> &b)
{
    int an = a.size(), bn = b.size();
    // 기저 사례 : a가 b보다 짧을 경우 교환
    if (an < bn)
        return karatsuba(b, a);
    // 기저 사례 : a나 b가 비어있는 경우
    if (an == 0 || bn == 0)
        return vector<int>();
    if (an <= 50)
        return multifly(a, b);
    int half = an / 2;
    // a와 b를 밑에서 half 자리와 나머지로 분리
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin(), min<int>(b.size(), half), b.end());
    // 계수 계산
    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);

    addTo(a0, a1, 0);
    addTo(b0, b1, 0);

    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);
    return ret;
}
