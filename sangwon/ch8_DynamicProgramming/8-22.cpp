// 8.22 두니발 박사의 탈옥 문제를 해결하는 완전 탐색 알고리즘

int n, d, p, q;

int connected[51][51], deg[51];
double search(vector<int>& path) {
    if(path.size() == d+1) {
        if(path.back( != q)) return 0.0;
        double ret = 1.0;
        for(int i =0; i + 1 < path.size(); ++i) 
            ret /= def[path[i]];
        return ret;
    }
    double ret = 0;
    
    for(int there = 0; there < n; ++there)
        if(connected[path.back()][there]) {
            path.push_back(there);
            ret += search(path);
            path.pop_back();
        }
    return ret;
}