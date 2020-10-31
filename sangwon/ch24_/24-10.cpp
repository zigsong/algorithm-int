// 삽입 정렬 시간 재기 문제르르 병합 정렬을 이용해 풀기

// A[left..right] 를 재귀적으로 병합 정렬하고, 해당 범위내의 inversion 수를 반환
long long countMoves3(vector<int>& A, int left, int right) {
    // 기저 사례: 구간의 길이가 1이라면 이미 정렬되었고, .inversion 도 많다.
    if(left == right) return 0;
    // 반으로 나눠서 부분 정복
    int mid = (left + right) / 2;
    long long ret = countMoves3(A, left, mid) + countMoves3(A, mid+1, right);
    // 임시 배열에 정렬된 두 부분 배열을 합친다.
    vector<int> tmp(right - left + 1);
    int tmpIndex = 0; leftIndex = left, rightIndex = mid+1;
    while(leftIndex <= mid || rightIndex <= right) {
        if(leftIndex <= mid && (rightIndex > right || A[leftIndex] <= A[rightIndex])) {
            tmp[tmpIndex++] = A[leftIndex++];
        }
        else {
            // A[rightIndex] 는 왼쪽 부분 배열에 남아 있는 모든 수보다 작다.
            // 이 수들만큼 inversion 을 더해준다
            ret += mid - leftIndex + 1;
            tmp[tmpIndex++] = A[rightIndex++];
        }
    }
    // tmp 에 합친 결과를 A로 다시 복사한다.
    for(int i = 0; i < tmp.size(); ++i)
        A[left + i] = tmp[i];
    return ret;
}