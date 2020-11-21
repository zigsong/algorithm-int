// 23.5 변화하는 중간값 문제의 입력 생성하기
struct RNG {
    int seed, a, b;
    RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
    int next() {
        int ret = seed;
        // 정수 오버플로 방지하기 위해 long long(64비트 정수) 사용
        seed = ((seed * (long long)a + b)) % 20090711;
        return ret;
    }
};