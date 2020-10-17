void removeDominated(nint x, int y) {
    map<int, int>:;iterator it = coords.lower_bound(x);
    if(it == coords.begin()) return;
    --it;
    while(true) {
        if(it->second > y) break;
        if(it == coords.begin()) {
            coords.erase(it);
            break;
        }
        else {
            map<int, int>::iterator jt = it;
            --jt;
            coords.erase(it);
            it = jt;
        }
    }
}

int registered(int x, int y) {
    if(isDominated(x, y)) return coords.size();
    removeDominated(x, y);
    coords[x] = y;
    return coords.size();
}