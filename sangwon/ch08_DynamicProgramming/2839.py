# 설탕 배달
import sys

global cache
global INF
cache = [-1 for i in range(10000)]

def positiveMin(a, b):
    if a <= 0 and b <= 0:
        return -1
    elif a <= 0 and b > 0:
        return b
    elif a > 0 and b <= 0:
        return a
    elif a > 0 and b > 0:
        return min(a, b)
    

def sugar(n):
    # 기저사례
    if n == 3 or n == 5: 
        cache[n] = 1
        return 1
    if n < 3:
        return -1
    
    # 캐시에 저장되어 있으면 그 값 반환
    if cache[n] != -1:
        return cache[n]

    # 메모이제이션    
    cache[n] = positiveMin(sugar(n-3) + 1, sugar(n-5) + 1)
    return cache[n]

sys.setrecursionlimit(10000)
N = int(input())
print(sugar(N)) 

# recursionlimit 설정 안하고도 풀 수 있을까?