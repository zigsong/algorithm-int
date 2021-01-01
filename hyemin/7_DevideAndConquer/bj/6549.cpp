#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <cstdlib>

using namespace std;

vector<long long> histogram(0,0);

// int로 하면 메모리 초과
long long measureArea(long start, long end) {
    // 기저 사례
    if (start == end) {
        return histogram[start];
    }
    long mid = (start + end) / 2;
    // 반으로 나눠서 각개격파
    long long area = max(measureArea(start, mid), measureArea(mid + 1, end));
    // 가운데에 걸친 경우
    long left = mid;
    long right = mid + 1;
    long long currentHeight = min(histogram[left], histogram[right]);
    // 확장 전 가운데 걸린 두 칸짜리 사각형을 후보에!
    area = max(area, currentHeight * 2);
    while(start < left || right < end) {
        // 오른쪽으로 확장하는 경우 : 왼쪽 끝까지 이미 확장했거나 오른쪽이 왼쪽보다 클 때
        if(right < end && (start == left || histogram[left-1] < histogram[right+1])) {
            ++right;
            currentHeight = min(currentHeight, histogram[right]);
        }
        // 왼쪽으로 확장하는 경우 : 오른쪽 끝까지 이미 확장했거나 왼쪽이 오른쪽보다 클 때 
        else {
            --left;
            currentHeight = min(currentHeight, histogram[left]);
        }
        // 양쪽에서 구한 넓이, 확장되면서 변하는 넓이들 중에서 가장 큰 값으로 업데이트
        area = max(area, currentHeight * (right - left + 1));
    }

    return area;
}

int main() {
    long n;
    while (1) {
    cin >> n;
    if (n == 0) break;
    for (long i = 0; i < n; i++) {
        long long input;
        cin >> input;
        histogram.push_back(input);
    }
    cout << endl;    
    cout << measureArea(0, n - 1);
    histogram.clear();
    }
    // long n;
    // do {
    // cin >> n;
    // for (long i = 0; i < n; i++) {
    //     long long input;
    //     cin >> input;
    //     histogram.push_back(input);
    // }
    // cout << endl;    
    // cout << measureArea(0, n - 1);
    // histogram.clear();
    // }
    // while (n != 0);
}

// 배운 점
// 괄호 주의
// int, long, long long 등 자료형 주의
// vector 길이 가지고 초기회ㅏ하면 나중에 push_back할 때 그 뒤부터 들어가므로 길이 지정 초기화는 길이를 제한하는 방식으로 적합하지 않음
// while문과 메모리의 관계