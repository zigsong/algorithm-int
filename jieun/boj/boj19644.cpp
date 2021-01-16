//
// Created by songji on 2021/01/12.
//

#include <iostream>
#include <deque>

using namespace std;

// 1. 기관총으로 죽일 수 있으면 죽이고 그렇지 않으면 폭탄을 사용
// 2. 즉 쏴 죽이지 못하거나 폭탄이 없다 -> 죽음
// * 주의할 점 - 폭탄과 기관총 두 가지를 동시에 사용할 수 없음
// queue에는 iterator가 없음 -> deque 사용

int main() {
    // l: 기관총 진지 앞쪽 길의 거리
    // ml: 기관총의 유효 사거리
    // mk: 각 1m 당 살상력
    // c: 수평 세열 지향성 지뢰의 개수
    int l, ml, mk, c;
    cin >> l >> ml >> mk >> c;
    deque<int> dq; // 처리 중인 좀비

    for (int i=1; i<=l; i++) {
        int zi;
        cin >> zi;
        dq.push_back(zi); // 처음 체력들을 큐에 담기
    }

    while (!dq.empty()) {
        int first = dq.front(); // 1번 좀비
        if (first <= 0) { // 이미 죽었다면 (앞에서 기관총 쏴서 연달아 hp 감소한 상태)
            dq.pop_front(); // 제거
            continue;
        }

        if (first <= mk) { // 1번 좀비를 기관총으로 쏴 죽일 수 있다면
            for (int i=0; i<ml; i++) {
                dq[i] -= mk; // 사격 거리 내에 있는 좀비들 hp 감소
            }
            dq.pop_front(); // 1번 좀비는 제거
            continue;
        }

        if (c > 0) { // 지뢰가 남아있다면
            dq.pop_front(); // 1번 좀비만 제거 가능
            c--;
            continue;
        } else {
            cout << "NO"; // 1번 좀비 제거 실패
            return 0;
        }
    }
    cout << "YES";
    return 0;
}