//
// Created by songji on 2020/12/22.
//
#include <iostream>
#include <string>

using namespace std;

int n;
int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        int sum = i;
        for (int j=0; j<to_string(i).length(); j++) {
            sum += to_string(i)[j] - '0';
        }
        if (sum == n) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}