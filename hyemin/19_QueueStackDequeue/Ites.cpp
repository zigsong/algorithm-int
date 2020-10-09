#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// 모든 입력을 저장할 수 있다고 가정
// 가장 단순한 오프라인 알고리즘
int simple(const vector<int> &signals, int k)
{
    int ret = 0;
    for (int head = 0; head < signals.size(); ++head)
    {
        int sum = 0;
        for (int tail = head; tail < signals.size(); ++tail)
        {
            // sum은 [head,tail] 구간의 합
            sum += signals[tail];
            // 부분수열의 합이 k이면 정답 부분수열의 개수 +1
            if (sum == k)
                ret++;
            // k보다 크면 부분수열 만들기 실패
            if (sum >= k)
                break;
        }
    }
}

// 최적화된 알고리즘
int optimized(const vector<int> &signals, int k)
{
    // tail이 for문 밖에 선언되어있어 head가 변해도 그대로! (최적화)
    // rangeSum 또한 head만 빠진 값으로 재사용된다
    int ret = 0, tail = 0, rangeSum = signals[0];
    for (int head = 0; head < signals.size(); ++head)
    {
        // rangeSum이 k 이상인 최초의 구간을 만날 때까지 tail을 옮긴다
        while (rangeSum < k && tail + 1 < signals.size())
            rangeSum += signals[++tail];

        if (rangeSum == k)
            ret++;
        // signals[head]는 구간 탈출
        rangeSum -= signals[head];
    }
    return ret;
}

// 온라인 알고리즘
int countRanges(int k, int n)
{
    RNG rng;          // 신호값을 생성하는 난수 생성기
    queue<int> range; // 현재 구간에 들어있는 숫자들을 저장하는 큐
    int ret = 0, rangeSum = 0;
    for (int i = 0; i < n; i++)
    {
        // 구간에 숫자 추가
        int newSignal = rng.next();
        rangeSum += newSignal;
        range.push(newSignal);

        // 구간의 합이 k를 초과하는 동안 구간에서 숫자를 뺀다
        // 최적화와는 반대로 합이 k 이하인 후보 구간을 유지
        while (rangeSum > k)
        {
            rangeSum -= range.front();
            range.pop();
        }

        if (rangeSum == k)
            ret++;
    }
    return ret;
}