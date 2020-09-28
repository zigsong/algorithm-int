int n;
bool areFriends[10][10];

int countParings(bool taken[10]) {
    bool finished = true;
    for(int i = 0; i < n; ++i) if(!taken[i]) finished = false;
    if(finished) return 1;
    int ret = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(!taken[i] && !taken[j] && areFriends[i][j]) {
                taken[i] = taken[j] = true;
                ret += countParings(taken);
                taken[i] = taken[j] = false;
            }
    return ret;
}

int main() {
    bool taken[10] = {1, 0, 1, 1, 1, 1, 1, 1, 1, 1};
    countParings(taken[10]);
    return 0;
}