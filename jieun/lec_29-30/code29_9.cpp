//
// Created by songji on 2020/11/19.
//
#include <queue>

using namespace std;

const int MAX_DISCS = 12;
int get(int state, int index) {
    return (state >> (index * 2)) & 3;
}

int set(int state, int index, int value) {
    return (state & ~(3 << (index * 2))) | (value << (index * 2));
}

int c[1<<(MAX_DISCS*2)];

// discs = 원반의 개수
int bfs(int discs, int begin, int end) {
    if (begin == end) return 0;
    queue<int> q;
    memset(c, 01, sizeof(c));
    q.push(begin);
    c[begin] = 0;
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        // 각 기둥에서 제일 위에 있는 원반의 번호를 계산
        int top[4] = { -1, -1, -1, -1};
        for (int i=discs-1; i>=0; --i) {
            top[get(here, i)] = i;
        }
        for (int i=0; i<4; ++i) {
            if (top[i] != -1) {
                for (int j=0; j<4; ++j) {
                    if (i != j && (top[j] == -1 || top[j] > top[i]) {
                        int there = set(here, top[i], j);
                        if (c[there] != -1) continue;
                        c[there] = c[here] + 1;
                        if (there == end) return c[there];
                        q.push(there);
                    }
                }
            }
        }
    }
    return -1;
}

int sgn(int x) { if (!x) return 0; return x > 0 ? 1 : -1; }
int incr(int x) { if (x < 0) return x-1; return x+1; }
int bidir(int discs, int begin, int end) {
    if (begin == end) return 0;
    queue<int> q;
    memset(c, 0, sizeof(c));
    // 정방향 탐색은 양수로, 역방향 탐색은 음수로 표시
    q.push(begin); c[begin] = 1;
    q.push(end); c[end] = -1;

    while(!q.empty()) {
        int here = q.front();
        q.pop();
        int top[4] = { -1, -1, -1, -1 };
        for (int i=discs-1; i>=0; --i) {
            top[get(here, i)] = i;
        }
        for (int i=0; i<4; ++i) {
            if (top[i] != -1) {
                for (int j=0; j<4; ++j) {
                    if (i != j && (top[j] == -1 || top[j] > top[i])) {
                        int there = set(here, top[i], j);
                        if (c[there] == 0) {
                            c[there] = incr(c[here]);
                            q.push(there);
                        }
                        else if (sgn(c[there]) != sgn(c[here])) {
                            return abs(c[there]) + abs(c[here]) - 1;
                        }
                    }
                }
            }
        }
    }
    return -1;
}