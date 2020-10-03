#include <iostream>

using namespace std;

bool match(const string& w, const string& s) {
  int pos = 0;
  while(pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos])) {
    ++pos;
  }

  if (pos == w.size()) {
    return pos == s.size();
  }

  if(w[pos] == '*') {
    for (int skip=0; pos+skip<=s.size(); ++skip) {
      // 1글자 일치하는지, 2글자 일치하는지, 3글자 일치하는지... 하나하나 검사 (이때 *은 0글자가 되어도, 즉 생략되어도 일치로 여김)
      if (match(w.substr(pos+1), s.substr(pos+skip))) {
        return true;
      }
    }
  }
  return false;
}