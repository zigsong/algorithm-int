# 1로 만들기

import sys

cache = [-1 for i in range(1000001)]

def makeOne(x):
    # base case
    if x == 3: 
        cache[x] = 1
        return 1
    if x == 2: 
        cache[x] = 1
        return 1
    
    # check cache
    if cache[x] != -1:
        return cache[x]
    
    # memoization
    # 3으로 나누어 떨어지거나, 2로 나누어 떨어지거나, 둘 다 아니거나
    if x % 3 == 0 and x % 2 == 0:
        cache[x] = min(makeOne(x//3)+1, makeOne(x//2)+1, makeOne(x-1)+1)
        return cache[x]
    elif x % 3 == 0 and x % 2 != 0:
        cache[x] = min(makeOne(x//3)+1, makeOne(x-1)+1)
        return cache[x]
    elif x % 3 != 0 and x % 2 == 0:
        cache[x] = min(makeOne(x//2)+1, makeOne(x-1)+1)
        return cache[x]
    else:        
        cache[x] = makeOne(x-1)+1
        return cache[x]
        
# sys.setrecursionlimit(100000)
X = int(input())
print(makeOne(X))