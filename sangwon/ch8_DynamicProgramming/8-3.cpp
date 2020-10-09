// 8.3 메모이제이션의 사용 예

// -1 로 초기화된 cache
int cache[2500][2500];

int someObscureFunction(int a, int b) {
    // 기저 사례에 걸리면 바로 return 하여 추가 연산을 막는다.
    if (...) return ...;

    // cache 에 저장된 답이 있으면 바로 반환한다. 참조형으로 호출하면...
    int& ret = cache[a][b];
    if(ret != -1) return ret;

    // 여기에서 답을 계산한다
    ...
    // 참조형으로 호출하면 ret 에 값을 저장하는 순간 cache[a][b] 에도 값이 저장된다.
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
}