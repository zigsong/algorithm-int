#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

int recursion(int n, vector<int>& picked, int toPick) {
    // 기저 사례 : 더 뽑을 게 없으면 출력
    if(toPick == 0) {
        cout <<  << endl;
    }
    for(int i = 0; i < toPick; ++i) {
        picked.push_back()
    }
    return 0;
}

int printarray(){
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int scanArray() {
    int size;
    int i = 0;
    scanf("%d", &size);
    int arr[size];
    while (i<size) {
        scanf(" %d", &arr[i]);
        i++;
    }
}

int main(){
    int vector

    int n = 0;
    int toPick = 6;
    
    recursion(n, arr[size], toPick);



    return 0;
}
