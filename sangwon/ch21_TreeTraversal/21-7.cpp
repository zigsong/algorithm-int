int n, y[100], x[100], radius[100];

int sqr(int x) {
    return x*x;
}

int sqrdist(int a, int b) {
    return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}

bool encloses(int a, int b) {
    return radius[a] > radius[b] && sqrdist(a, b) < sqr(radius[a] - radius[b]);

    bool isChild(int parent, int child) {
        if(!encloses(parent, child)) return false;
        for(int i = 0; i < n; ++i)
            if(i != parent  && i != child && encloses(parent, i) && encloses(i, child))
                return false;
        return true;
    }
}