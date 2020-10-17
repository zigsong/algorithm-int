map<int, int> coords;
bool isDominated(int x, int y) {
    map<int, int>::iterator it = coords.lower_bound(x);
    if(it == coords.ends()) return false;
    return y < it->second;
}