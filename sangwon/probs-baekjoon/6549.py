# 히스토그램에서 가장 큰 직사각형
import sys

def maxArea(n, heights):
    pass



# 입력 받는 부분
heights= []

while True:
    temp = list(map(int, sys.stdin.readline().split()))
    n = temp[0]
    if n == 0: break
    heights = temp[1:]

maxArea(n, heights)