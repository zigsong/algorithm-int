#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <numeric>
#include <iostream>

using namespace std;

int n;           //도시의 수
double dist[][]; // 두 도시 간의 거리를 저장하는 배열

// path: 지금까지 만든 경로
// visted : 각 도시의 방문 여부
// currentLength: 지금까지 만든 경로의 길이

double shortestPath(vector<int> &path, vector<bool> &visited, double currentLength)
{
    // 기저 사례 : 모든 도시를 다 방문하면 시작 도시로 돌아가고 종료
    if (path.size() == n)
        // 현재 경로 길이 + 마지막 도시에서 시작 도시까지의 거리
        return currentLength + dist[path[0]][path.back()];
    double ref = 1000; //큰 값으로 초기화 -> 재귀 호출의 마지막 단계에서 비교할 때 무조건 마지막 cand를 반환
    for (int next = 0; next < n; ++next)
    {
        //방문한 도시면 건너뛰고
        if (visited[next])
            continue;
        // 방문하지 않은 도시가 발견될 경우! 현재까지 경로의 마지막 도시를 현재 위치로 가져옴
        int here = path.back();
        // 방문하지 않은 도시를 경로에 추가(->방문)
        path.push_back(next);
        visited[next] = true;
        // 재귀 호출하여 각각의 단계에서 min을 반환
        double cand = shortestPath(path, visited, currentLength + dist[here][next]);
        ret = min(ret, cand);
        visited[next] = false;
        path.pop_back();
    }
    // 해당 단계에서의 최소값 ret 반환
    return ret;
}
