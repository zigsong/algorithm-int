#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <cstdlib>

using namespace std;


vector<long> dailyProfit(0,0);

// int로 하면 메모리 초과
long maximumProfit(long start, long end) {
    // 기저 사례
    if (start == end) {
        return dailyProfit[start];
    }
    long mid = (start + end) / 2;
    // 반으로 나눠서 각개격파
    long area = max(maximumProfit(start, mid), maximumProfit(mid + 1, end));
    // 가운데에 걸친 경우
    long left = mid;
    long right = mid + 1;
    long currentHeight = min(dailyProfit[left], dailyProfit[right]);
    // 확장 전 가운데 걸린 두 칸짜리 사각형을 후보에!
    area = max(area, currentHeight * 2);
    while(start < left || right < end) {
        // 오른쪽으로 확장하는 경우 : 왼쪽 끝까지 이미 확장했거나 오른쪽이 왼쪽보다 클 때
        if(right < end && (start == left || dailyProfit[left-1] < dailyProfit[right+1])) {
            ++right;
            currentHeight = min(currentHeight, dailyProfit[right]);
        }
        // 왼쪽으로 확장하는 경우 : 오른쪽 끝까지 이미 확장했거나 왼쪽이 오른쪽보다 클 때 
        else {
            --left;
            currentHeight = min(currentHeight, dailyProfit[left]);
        }
        // 양쪽에서 구한 넓이, 확장되면서 변하는 넓이들 중에서 가장 큰 값으로 업데이트
        area = max(area, currentHeight * (right - left + 1));
    }

    return area;
}

int main() {
    long n;
    cin >> n;
    for (long i = 0; i < n; i++) {
        long input;
        cin >> input;
        dailyProfit.push_back(input);
    }
    cout << maximumProfit(0, n - 1) << endl;    
}
