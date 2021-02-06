import sys

def factorial(n):
    if n == 0: return 1
    return n * factorial(n-1)
    
def permutation(n, r):
    ret = 1
    for i in range(n, n-r, -1):
        ret = ret * i
    return ret

def combination(n, r):
    ret = 1
    return int(permutation(n, r) / factorial(r))

T = int(sys.stdin.readline())
for i in range(T):
    N, M = map(int, sys.stdin.readline().split())
    print(combination(M, N))