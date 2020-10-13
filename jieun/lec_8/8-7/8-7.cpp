#include <iostream>

using namespace std;

int cache[101][101];
string W, S;

bool matchMemoized(int w, int s) {
  int& ret = cache[w][s];
  if (ret != -1) return ret;
  while(s<S.size() && w<W.size() && (W[w] == '?' || W[w] == S[s])) {
    ++w;
    ++s;
  }
  if (w == W.size()) return ret = (s == S.size());
  if (W[w] == '*') {
    // for (int skip=0; skip+s<=S.size(); ++skip) {
    //   if (matchMemoized(w+1, s+skip)) return ret = 1;
    // }
    if (matchMemoized(w+1, s) || (s<S.size() && matchMemoized(w, s+1))) return ret = 1;
  }
  return ret = 0;
}