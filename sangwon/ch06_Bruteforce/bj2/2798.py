import sys

def bruteforce(n, m, nums):
    ret = 0
    for i in range(0, n-2):
        for j in range(i+1, n-1):
            for k in range(j+1, n):
                sum = nums[i] + nums[j] + nums[k]
                if sum <= m: ret = max([sum, ret])
    return ret
            
n, m = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))

print(bruteforce(n, m, nums))

