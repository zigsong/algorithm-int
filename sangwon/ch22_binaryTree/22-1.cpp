// 한 점이 다른 점에 지배당하는지 확인하는 함수

// 현재 다른 점에 지배당하지 않는 점들의 목록을 저장한다.
// coords[x] = y
map<int, int> coords;
bool isDominated(int x, int y) {
    // x 보다 오른쪽에 있는 점 중 가장 왼쪽에 있는 점을 찾는다.
    map<int, int>::iterator it = coords.lower_bound(x);
    // 그런 점이 없으면 (x,y) 는 지배당하지 않는다.
    if(it == coords.ends()) return false;
    // 이 점은 x보다 오른쪽에 잇는 점 중  가장 위에 잇는 점이므로
    // (x,y) 가 어느 점에 지배되려면 이 점에도 지배되어야 한다.
    return y < it->second;
}

// 이게 가능한 것은 지배당한 점들은 모두 삭제했기 때문