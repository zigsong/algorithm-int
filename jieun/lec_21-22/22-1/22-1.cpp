#include <iostream>
#include <map>

using namespace std;

// 지배당하지 않는 점들의 목록
map<int, int> coords;

bool isDominated(int x, int y) {

  // lower_bound: coords의 오른쪽 원소 중 기준 원소와 같거나 큰 값 중 가장 왼쪽에 있는 원소의 iterator값을 리턴
  map<int, int>::iterator it = coords.lower_bound(x);
  if (it == coords.end()) return false;
  // map의 <key, value>
  // it->first: key, it->second: value
  return y < it->second;
}

void removeDominated(int x, int y) {
  map<int, int>::iterator it = coords.lower_bound(x);
  if (it == coords.begin()) return;
  --it;

  while(true) {
    if (it->second > y) break;
    if (it == coords.begin()) {
      coords.erase(it);
      break;
    } else {
      // 이전 점으로 이터레이터를 하나 옮겨 놓고 it를 지움
      map<int, int>::iterator jt = it;
      --jt;
      coords.erase(it);
      it = jt;
    }
  }
}

int registered(int x, int y) {
  // 새로 추가된 점이 지배당하는 경우에는 기존의 size를 리턴
  if (isDominated(x, y)) return coords.size();
  // 기존에 있던 점이 새 점에 의해 지배당한다면 지배당하는 점을 삭제
  removeDominated(x, y);
  // 새 점 등록
  coords[x] = y;
  return coords.size();
}