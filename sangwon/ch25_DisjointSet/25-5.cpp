// 25.5 상호 배타적 집합이 주어질 때 에디터 전쟁 문제의 답을 구하는 함수의 구현

#include <vector>
#include <iostream>
using namespace std;

int maxParty(const BipartUnionFind& buf) {
    int ret;
    for(int node = 0; node < n; ++node)
        if(buf.parent[node] == node) {
            int enemy = buf.enemy[node];
            if(enemy > node) continue;
            int mySize = buf.size[node];
            int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
            ret += max(mySize, enemySize);
    }
    return ret;
}