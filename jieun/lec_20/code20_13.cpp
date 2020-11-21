//
// Created by songji on 2020/11/20.
//
#include <vector>
#include <string>

using namespace std;

int commonPrefix(const string& s, int i, int j) {
    int k = 0;
    while (i < s.size() && j < s.size() && s[i] == s[j]) {
        ++i; ++j; ++k;
    }
    return k;
}

// error occurs
//int longestFrequent(int k, const string& s) {
//    vector<int> a = getSuffixArray(s);
//    int ret = 0;
//    for (int i=0; i+k <= s.size(); ++i) {
//        ret = max(ret, commonPrefix(s, a[i], a[i+k-1]));
//    }
//    return ret;
//}