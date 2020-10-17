// 한 성벽이 다른 성벽에 포함되었는지, 그리고 직접 포함되었는지 확인하는 함수

// 입력 데이터
int n, y[100], x[100], radius[100];
// x 제곱을 반환한다.
int sqr(int x) {
    return x*x;
}
// 두 성벽 a,b 의 중심점 간의 거리의 제곱을 반환한다
int sqrdist(int a, int b) {
    return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}
// 성벽 a 가 성벽 b를 포함하는지 확인한다.
bool encloses(int a, int b) {
    return radius[a] > radius[b] && sqrdist(a, b) < sqr(radius[a] - radius[b]);
}
// '성벽' 트리에서 parent 가 child 의 부모인지 확인한다.
// parent 는 child 를 '직접' 포함해야 한다. 
bool isChild(int parent, int child) {
    if(!encloses(parent, child)) return false;
    for(int i = 0; i < n; ++i)
        if(i != parent  && i != child && encloses(parent, i) && encloses(i, child))
            return false;
    return true;
}
