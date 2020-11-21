//
// Created by songji on 2020/11/20.
//

#include <vector>
#include <string>

using namespace std;

vector<int> naiveSearch(const string& H, const string& N) {
    vector<int> ret;
    for (int begin=0; begin + N.size() <= H.size(); ++begin) {
        bool matched = true;
        for (int i=0; i<N.size(); ++i) {
            if (H[begin+i] != N[i]) {
                matched = false;
                break;
            }
        }
        if (matched) ret.push_back(begin);
    }
    return ret;
}