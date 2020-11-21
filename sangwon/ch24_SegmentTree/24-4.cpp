// 24.4 숫자의 최대 출현 회수 문제의 두 개의 답을 합치기

// 부분 구간의 계산 결과
struct RangeResult {
    // 이 구간의 크기
    int size;
    // 가장 자주 등장하는 숫자의 출현 횟수
    int mostFrequent;
    // 왼쪽 끝 숫자와 왼쪽 끝 숫자의 출현 횟수
    int leftNumber, leftFreq;
    // 오른쪽 끝 숫자와 오른쪽 끝 숫자의 출현 횟수
    int rightNumber, rightFreq;
};

// 왼쪽 부분 구간의 계산 결과 a, 오른쪽 부분 구간의 계산결과 b를 합친다.
RangeResult merge(const RangeResult& a, cconst RangeResult& b) {
    RangeResult ret;
    // 구간의 크기는 쉽게 계산 가능
    ret.size = a.size + b.size;
    
    // 왼쪽 숫자는 a.elftNumber로 정해져있다.
    // 왼쪽 부분 구간이 전부 a.leftNumber인 경우만 별도로 처리
    // 예: [1,1,1,1] 과 [1,2,2,2] 를 합칠 때
    ret.leftNumber = a.leftNumber;
    ret.leftFreq = a.leftFreq;
    if(a.size == a.leftFreq && a.leftNumber == b.leftNumber)
        ret.leftFreq += b.leftFreq;
    
    // 오른쪽 끝 숫자도 비슷하게 계산
    ret.rightNumber = b.rightNumber;
    ret.rightFreq = b. rightFreq;
    if(b.size == b.rightFreq && a.rightNumber == b.rightNumber)
        ret.leftFreq += a.rightFreq;
    
    // 가장 많이 출현하는 수의 빈도수는 둘 중 큰 쪽으로
    // 두 수를 합쳤을 때 mostFrequent 보다 커지는지 확인한다.
    ret.mostFrequent = max(a.mostFrequent, b.mostFrequent);
    if(a.rightNumber == b.leftNumbe)
        ret.mostFrequent = max(ret.mostFrequent, a.rightFreq + b.leftFreq);
    return ret;
}