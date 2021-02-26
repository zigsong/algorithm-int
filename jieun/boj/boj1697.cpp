//
// Created by songji on 2021/02/26.
//
// BFS

#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001;
int n, k, ans;
bool visited[MAX];
queue<pair<int,int>> q;

void bfs() {
    while(!q.empty()) {
        int curr = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (curr == k) {
            ans = depth;
            break;
        }
        if (curr + 1 < MAX && !visited[curr+1]) {
            visited[curr+1] = true;
            q.push(make_pair(curr+1, depth+1));
        }
        if (curr - 1 >= 0 && !visited[curr-1]) {
            visited[curr-1] = true;
            q.push(make_pair(curr-1, depth+1));
        }
        if (2 * curr < MAX && !visited[2*curr]) {
            visited[2*curr] = true;
            q.push(make_pair(2*curr, depth+1));
        }
    }
}

int main() {
    cin >> n >> k;
    q.push(make_pair(n, 0));
    visited[n] = 1;
    bfs();

    cout << ans << "\n";
}