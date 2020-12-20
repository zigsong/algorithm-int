// 28.9 

#include <map>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int> > adj;
vector<int> discovered;
vector<bool> isCutVertex;
int counter = 0;

int findCutVertex(int here, bool isRoot) {
    discovered[here] = counter++;
    int ret = discovered[here];
    int children = 0;
    for(int i = 0; i < adj[here].size(); ++i) {
        int there = adj[here][i];
        if(discovered[there] == -1) {
            ++children;
            int subtree = findCutVertex(there, false);
            if(!isRoot && subtree >= discovered[here])
                isCutVertex[here] = true;
            ret = min(ret, subtree);
        }
        else
            ret = min(ret, discovered[there]);
    }
    if(isRoot) isCutVertex[here] = (children >= 2);
    return ret;
}