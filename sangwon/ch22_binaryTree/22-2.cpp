// 지배되는 점들을 삭제하는 함수

// 새로운 점 (x,y) 에 지배당하는 점들을 트리에서 지운다.
void removeDominated(nint x, int y) {
    map<int, int>:;iterator it = coords.lower_bound(x);
    // (x,y)보다 왼쪽에 있는 점이 없다!
    if(it == coords.begin()) return;
    --it;
    // 반복문 불변식: it는 (x,y) 의 바로 왼쪽에 있는 점
    while(true) {
        // (x,y) 바로 왼쪽에 오는 점을 찾는다
        // it 가 표시하는 점이 (x,y) 에 지배되지 않는다면 곧장 종료
        if(it->second > y) break;
        // 이전 점이 더 없으므로 it만 지우고 종료한다.
        if(it == coords.begin()) {
            coords.erase(it);
            break;
        }
        // 이전 점으로 이터레이터를 하나 옮겨놓고 it를 지운다.
        else {
            map<int, int>::iterator jt = it;
            --jt;
            coords.erase(it);
            it = jt;
        }
    }
}
// 새 점 (x,y) 가 추가되었을 때 coords 를 갱신하고,
// 다른 점에 지배당하지 않는 점들의 개수를 반환한다.
int registered(int x, int y) {
    // (x,y) 가 이미 지배당하는 경우에은 그냥 (x,y) 를 버린다.
    if(isDominated(x, y)) return coords.size();
    // 기존에 있던 점 중 (x,y) 에 지배당하는 점들을 지운다.
    removeDominated(x, y);
    coords[x] = y;
    return coords.size();
}