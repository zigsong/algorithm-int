// 19.6 외계 신호 문석 문제에서 사용하는 선형 합동 난수 생성기의 구현

struct RNG {
    unsigned seed;
    RNG() : seed(1983) {}
    unsigned next() {
        unsigned ret = seed;
        seed = ((seed * 214013u) + 2531011u);
        return ret % 10000 + 1;
    }
}