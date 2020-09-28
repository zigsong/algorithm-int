#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

int main(){
    // vector<int> v;
    // string input;
    // getline(cin, input);
    // cout << input[0] << endl;
    
    int size;
    int i = 0;
    scanf("%d", &size);
    int arr[size];
    while (i<size) {
        scanf(" %d", &arr[i]);
        i++;
    }


    for (i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
