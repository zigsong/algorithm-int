#include <iostream>
#include <string>
#include <vector>

int n, d, p, q;
double cahce[51][101];

int connected[51][51], deg[51];
double search3(int here, int days) {
    if(days == 0) return (here == p ? 1.0 : 0.0);
    double& ret = cache[here][days];
    if(ret > -0.5) return ret;
    ret = 0.0;
    for(int there = 0; there < n; ++there) 
        if(connected[here][there])
            ret += search3(there, days - 1) / deg[there];
    return ret;
}