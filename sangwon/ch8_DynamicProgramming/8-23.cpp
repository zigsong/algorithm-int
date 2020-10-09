// 8.23 두니발 박사의 탈옥 문제를 해곃하는 동적 계획법 알고리즘

int n, d, p, q;
double cache[51][101];

int connected[51][51], deg[51];
double search2(int here, int days) {
    if(days == d) return (here == q ? 1.0 : 0.0);
    double& ret = cache[here][days];
    if(ret > -0.5) return ret;
    ret = 0.0;
    for(int there = 0; there < n; ++there)
        if(connected[here][there])
            ret += search2(there, days+1) / deg[here];
    return ret;
}