def solve(N:int, A:int):
    D = [0 for i in range(N)]
    for i in range(N):
        length = 1
        max_ = A[i]
        for j in range(i,N):
            if A[j] > max_:
                length += 1
                max_ = A[j]
        D[i] = length<ㅑ
            
            
N = int(input())
A = list(map(int, input().split()))

print(solve(N, A))