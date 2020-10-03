#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;
const int INF = 987654321;
string N;
// N[a..b] 구간의 난이도를 반환
int classify(int a, int b)
{
    // 숫자 조각을 가져옴
    string M = N.substr(a, b - a + 1);
    // 난이도 1 : 첫 글자만으로 이루어진 문자열과 같을 때
    if (M == string(M.size(), M[0]))
        return 1;
    // 등차수열 검사
    bool progressive = true;
    for (int i = 0; i < M.size() - 1; ++i)
        if (M[i + 1] - M[i] != M[1] - M[0])
            progressive = false;
    // 난이도 2 : 등차수열이고 공차가 +-1
    if (progressive && abs(M[1] - M[0]) == 1)
        return 2;
    // 두 수가 번갈아 등장하는지 검사
    bool alternating = true;
    for (int i = 0; i < M.size(); ++i)
        if (M[i] != M[i % 2])
            alternating = false;
    // 난이도 4 : 두 수가 번갈아 등장
    if (alternating)
        return 4;
    // 난이도 5 : 공차가 +-1 아닌 등차수열
    if (progressive)
        return 5;
    // 난이도 10 : 외의 모든 경우
    return 10;
}

int cache[10002];
// 수열 N[begin..]을 외우는 방법 중 난이도의 최소 합 출력
int memorize(int begin)
{
    // 기저 사례 : 수열의 끝에 도달했을 경우
    if (begin == N.size())
        return 0;
    // 메모이제이션
    int &ret = cache[begin];
    if (ret != -1)
        return ret;
    ret = INF;
    for (int L = 3; L <= 5; ++L)
        if (begin + L <= N.size())
            // 첫 구간의 난이도 + 이후 구간의 재귀 호출
            ret = min(ret, memorize(begin + L) + classify(begin, begin + L - 1));
    return ret;
}