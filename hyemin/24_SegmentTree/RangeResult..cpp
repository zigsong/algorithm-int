#include <set>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 부분 구간의 계산 결과
struct RangeResult {
    // 이 구간의 크기
    int size;
    // 가장 자주 등장하는 숫자의 등장 횟수
    int mostFrequent;
    // 왼쪽 끝 숫자와 왼쪽 끝 숫자의 등장 횟수
    int leftNumber, leftFreq;
    // 왼쪽 끝 숫자와 왼쪽 끝 숫자의 등장 횟수
    int rightNumber, rightFreq;
};

// 부분 구간의 계산 결과
RangeResult merge(const RangeResult& a, const RangeResult& b) {

    RangeResult ret;
    // 구간의 크기는 양쪽 구간의 합
    ret.size = a.size + b.size;
    // 총 구간의 왼쪽 숫자는 a구간의 제일 왼쪽 숫자
    ret.leftNumber = a.leftNumber;
    ret.leftFreq = a.leftFreq;
    // 왼쪽 구간이 모두 같은 숫자일 때만 따로 처리
    if(a.size == a.leftFreq && a.leftNumber == b.leftNumber)
        ret.leftFreq += b.leftFreq;
    // 총 구간의 오른쪽 숫자는 b구간의 제일 오른쪽 숫자
    ret.rightNumber = b.rightNumber;
    ret.rightFreq = b.rightFreq;
    // 마찬가지로 b구간이 모두 같은 숫자일 때만 따로 처리
    if(b.size == b.rightFreq && a.rightNumber == b.rightNumber)
        ret.rightFreq += a.rightFreq;
    // 기본적으로 가장 많이 출현하는 수의 민도수는 둘 중 큰 쪽이고
    ret.mostFrequent = max(a.mostFrequent, b.mostFrequent);
    // 이 두 수를 합쳤을 때 mostFrequent보다 커지는지 확인
    if(a.rightNumber == b.leftNumber)
        ret.mostFrequent = max(ret.mostFrequent, a.rightFreq + b.leftFreq);
    return ret;
}