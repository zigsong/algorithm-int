//
// Created by songji on 2020/12/22.
//
#include <iostream>

using namespace std;

int main() {
    int n, m;
    int cards[100];
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> cards[i];
    }

    int sum = 0;
    for (int i=0; i<n-2; i++) {
        for (int j=i+1; j<n-1; j++) {
            for (int k=j+1; k<n; k++) {
                int temp = cards[i] + cards[j] + cards[k];
                if (temp <= m && temp > sum) {
                    sum = temp;
                }
            }
        }
    }

    cout << sum;
}