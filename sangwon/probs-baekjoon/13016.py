import sys

def maxDistance(i, arr):
    arr
    return 0

N = int(sys.stdin.readline())

arr = [[-1 for i in range(N)] for i in range(N)]

for i in range(N-1):
    fr, to, length = map(int, sys.stdin.readline().split())
    arr[fr-1][to-1] = length

print(arr)

# 가장 거리가 먼 국가
for i in range(N):
    maxDistance(i, arr)