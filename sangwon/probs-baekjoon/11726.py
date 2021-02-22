# 11726
import sys
sys.setrecursionlimit(10000)

cache = [-1 for i in range(1002)]

def solve(n):
    if n == 1:
        cache[n] = 1
        return 1
    if n == 2:
        cache[n] = 2
        return 2
    if cache[n] != -1:
        return cache[n]

    cache[n] = solve(n-1) + solve(n-2)
    return cache[n] % 10007

n = int(input()) 
print(solve(n))