//
// Created by songji on 2020/11/20.
//
#include <vector>
#include <string>

using namespace std;

// 20-4
vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (N[begin+matched] == N[matched]) {
            ++matched;
            pi[begin+matched-1] = matched;
        }
        else {
            if (matched == 0) ++begin;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}

vector<int> getPrefixSuffix(const string& s) {
    vector<int> ret, pi = getPartialMatch(s);
    int k = s.size();
    while (k > 0) {
        ret.push_back(k);
        k = pi[k-1];
    }
    return ret;
}

// 20-6
// S의 접미사이면서 S'의 접두사도 되는 문자열의 최대 길이를 계산
int maxOverlap(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    vector<int> pi = getPartialMatch(b);
    int begin = 0, matched = 0;
    while (begin < n) {
        if (matched < m && a[begin+matched] == b[matched]) {
            ++matched;
            if (begin + matched == n) return matched;
        }
        else {
            if (matched == 0) ++begin;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return 0;
}

// 20-7
// KMP 알고리즘의 다른 구현
vector<int> kmpSearch2(const string& H, const string& N) {
    int n = H.size(), m = N.size();
    vector<int> ret;
    vector<int> pi = getPartialMatch(N);
    int matched = 0;
    for (int i=0; i<n; ++i) {
        while (matched > 0 && H[i] != N[matched]) {
            matched = pi[matched-1];
        }
        if (H[i] == N[matched]) {
            ++matched;
            if (matched == m) {
                ret.push_back(i-m+1);
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}
