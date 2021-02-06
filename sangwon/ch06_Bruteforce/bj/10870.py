# 10870 피보나치 수열
import sys
sys.setrecursionlimit(10000)

# bruteforce 10870번(n<20)
def fibonacci(n):
    if n == 0: return 0
    if n == 1: return 1
    ret = fibonacci(n-1) + fibonacci(n-2)
    return ret

# dp 2748번(n<=90), 2747번(n<=45)
def fibo_dp(n, cache):
    if n == 0: return 0
    if n == 1: return 1
    if cache[n] != -1: return cache[n]
    cache[n] = fibo_dp(n-1, cache) + fibo_dp(n-2, cache)
    return cache[n]

# 10826 (n <= 10,000)
# D&Q 2749번(n <= 1,000,000,000,000,000,000) 
def fibo_dq():
    pass

n = int(input())
cache = [-1 for i in range(n+1)]
print(str(fibo_dp(n, cache)))
