# 1로 만들기
# bottom-up, Dynamic Programming

cache = [-1 for i in range(1000001)]

def makeOne(x):
    cache[0] = 0
    cache[1] = 0
    
    i = 2
    while i <= x:
        cache[i] = cache[i-1] + 1
        if i % 2 == 0:
            cache[i] = min(cache[i//2] + 1, cache[i])
        if i % 3 == 0:
            cache[i] = min(cache[i//3] + 1, cache[i])
        i += 1
    
    return cache[x]
    
X = int(input())
print(makeOne(X))