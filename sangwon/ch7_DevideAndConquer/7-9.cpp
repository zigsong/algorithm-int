#include <vector>
#include <string>

int hugs(const string& members, const string& fans) {
    int N = members.size(), M = fans.size();
    vector<int> A(N), B(M);

    for(int i =0; i < N; ++i) A[i] = (members[i] == 'M');
    for(int i =0; i < M; ++i) B[M-i-1] = (fans[i] == 'M');

    vector<int> C = karatsuba(A, B);
    int allHugs = 0;
    for(int i = N-1; i < M; ++i) {
        if(C[i] == 0) ++allHugs;
    }
    return allHugs;
}