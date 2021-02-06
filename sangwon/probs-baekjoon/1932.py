import sys

cache = [-1 for i in range(250*501 + 1)]

def max(a, b):
    if a > b: return a
    else: return b
    
def solve(i, now, n, nums):
    index = int((now-1)*now/2) + i + 1
    if now == n:
        cache[index] = nums[now-1][i]
        return cache[index] # now-1 이 인덱스이므로
    
    if cache[index] != -1:
        return cache[index]
    
    cache[index] = nums[now-1][i] + max(solve(i, now+1, n, nums), solve(i+1, now+1, n, nums))
    return cache[index]

n = int(sys.stdin.readline())
nums = []
for i in range(n):
    nums.append(list(map(int, sys.stdin.readline().split())))
    
print(solve(0, 1, n, nums))