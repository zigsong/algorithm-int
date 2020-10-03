// 와일드카드 문제를 해결하는 완전 탐색 알고리즘
#include <string>

// 와일드카드 패턴 w가 문자열 s에 대응되는지 여부 반환
bool match(const string &w, const string &s)
{
    // w[pos]와 s[pos]를 맞춰나감
    int pos = 0;
    while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos]))
        ++pos;
    // 더이상 대응할 수 없으면 while문이 끝난 이유 확인
    // 패턴 끝에 도달해서 끝난 경우 : 문자열도 끝났어야 대응됨
    if (pos == w.size())
        return pos == s.size();
    // *를 만나서 끝난 경우 : *에 몇 글자르르 대응해야 할지 재귀 호출하며 확인
    if (w[pos] == '*')
        for (int skip = 0; pos + skip <= s.size(); ++skip)
            if (match(w.substr(pos + 1), s.substr(pos + skip)))
                return true;
    // 이 외의 경우에는 모두 대응되지 않음
    return false;
}

// 와일드카드 문제를 해결하는 동적 계획법 알고리즘

// 배열 내의 -1은 답이 계산되지 않았음을, 1은 입력들이 대응됨을, 0은 대응되지 않음을 의미
int cache[101][101];
// 패턴과 문자열
string W, S;
//와일드카드 패턴 W[w..]가 문자열 S[s..]에 대응되는지 여부 반환
bool matchMemoized(int w, int s)
{
    // 메모이제이션
    int &ret = cache[w][s];
    if (ret != -1)
        return ret;
    // W[w]와 S[s]를 맞춰나감
    while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s]))
    {
        ++w;
        ++s;
    }
    // 대응할 수 없으면 while문이 끝난 이유 확인
    // 패턴 끝에 도달에서 끝난 경우 : 문자열도 끝났어야 하므로 확인하고 리턴
    if (w == W.size())
        return ret = (s == S.size());
    // *를 만나서 끝난 경우 : *에 몇 글자를 대응해야 할지 재귀 호출하며 확인
    if (W[w] == '*')
        for (int skip = 0; skip + S <= S.size(); ++skip)
            if (matchMemoized(w + 1, s + skip))
                return ret = 1;
    // 외의 경우는 모두 대응되지 않음
    return ret = 0;
}

// 시간 복잡도를 O(n^2)까지 줄이는 분해 방법 -> *를 찾는 반복문 없애기

bool matchMemoized2(int w, int s)
{
    // 메모이제이션
    int &ret = cache[w][s];
    if (ret != -1)
        return ret;
    // W[w]와 S[s]를 맞춰나감
    while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s]))
    {
        // while문의 조건을 통과했다는 것은 두 글자가 대응된다는 뜻
        // w,s를 증가시키며 계속하는 대신 현재 글자를 떼고 다음 접미사끼리 대응되는지 재귀 호출로 확인 가능
        return ret = matchMemoized2(w + 1, s + 1);
    }
    // 현재 위치에서 대응할 수 없으면 while문이 끝난 이유 확인
    // 패턴 끝에 도달에서 끝난 경우 : 문자열도 끝났어야 하므로 확인하고 리턴
    if (w == W.size())
        return ret = (s == S.size());
    // *를 만나서 끝난 경우 : *에 몇 글자를 대응해야 할지 재귀 호출하며 확인
    // for문을 재귀 호출로 바꾸려면 매 단계에서 *에 아무 글자도 대응시키지 않을 것인지, 한 글자를 더 대응시킬 것인지만 결정하면 됨
    if (W[w] == '*')
    {
        // 다음 패턴과 현재 문자열이 대응되어 *에는 아무 글자도 대응시키지 않거나 다음 글자를 대응시키는 경우
        if (matchMemoized2(w + 1, s) || (s < S.size() && matchMemoized2(w, s + 1)))
            return ret = 1;
    }
    // 외의 경우는 모두 대응되지 않음
    return ret = 0;
}
