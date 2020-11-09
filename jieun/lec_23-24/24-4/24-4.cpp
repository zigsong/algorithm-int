#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct RangeResult {
  int size;
  int mostFrequent;
  int leftNumber, leftFreq;
  int rightNumber, rightFreq;
};

RangeResult merge(const RangeResult& a, const RangeResult& b) {
  RangeResult ret;
  ret.size = a.size + b.size;
  ret.leftNumber = a.leftNumber;
  ret.leftFreq = a.leftFreq;
  if (a.size == a.leftFreq && a.leftNumber == b.leftNumber) {
    ret.leftFreq += b.leftFreq;
  }

  ret.rightNumber = b.rightNumber;
  ret.rightFreq = b.rightFreq;
  if (b.size == b.rightFreq && a.rightNumber == b.rightNumber) {
    ret.rightFreq += a.rightFreq;
  }

  ret.mostFrequent = max(a.mostFrequent, b.mostFrequent);
  if (a.rightNumber == b.leftNumber) {
    ret.mostFrequent = max(ret.mostFrequent, a.rightFreq + b.leftFreq);
  }

  return ret;
}