#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int MAX = 100; // 임의의 값
int n;
double dist[MAX][MAX]; // 두 도시 간의 거리 저장 Q. 왜 MAX 값으로 할까?

const int INF = 9999;

// path: 지금까지 만든 경로. 즉 2,5,8,4의 순서대로 도시를 방문했다면 path = {2, 5, 8, 4};
double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {
  if (path.size() == n) // 최종 도시 방문!
    return currentLength + dist[path[0]][path.back()]; // currentLength + 마지막 도시에서 다시 첫 번째 도시로 돌아가는 거리

  double ret = INF; // 임의의 가장 큰 상수

  // 현재 도시(here)에서 다른 도시(next)들을 모두 돌면서 가장 거리가 짧은(min) 다음 도시(next) 선정
  for (int next=0; next<n; ++next) {
    if (visited[next]) continue; // 이미 방문했던 도시는 pass
    int here = path.back();
    path.push_back(next); // 1-1. 동작 실행
    visited[next] = true; // 1-2. 동작 실행 
    double cand = shortestPath(path, visited, currentLength + dist[here][next]); // 2. 재귀 호출 (cand = candidate)

    ret = min(ret, cand);
    visited[next] = false; // 3-1. 동작 취소
    path.pop_back(); // 3-2. 동작 취소
  }
  return ret;
}