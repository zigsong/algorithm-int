//
// Created by songji on 2021/02/04.
//

// 시간 초과 (테케 통과)
#include <iostream>
#include <vector>

using namespace std;

vector<int> movies;

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        movies.clear();
        int n, m;
        cin >> n >> m;
        for (int i=n; i>=1; i--) {
            movies.push_back(i);
        }
        for (int i=0; i<m; i++) {
            int curr; // 3, 1, 1
            cin >> curr;
            for (int j=0; j<n; j++) {
                if (movies[j] == curr) {
                    vector<int>::iterator it = movies.begin() + j;
                    movies.erase(it);
                    cout << n - j - 1 << " ";
                    movies.push_back(curr);
                    break;
                }
            }
        }
    }
}