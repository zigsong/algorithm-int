# 9934 
# 전위순회, devide and conquer

import sys

# devide and conquer
def devcon(nums, output, floor):
    # 기저사례, len(nums) == 1
    if len(nums) == 1:
        output[floor].append(nums[0])
        return
    
    rootIndex = len(nums)//2
    
    root = [nums[rootIndex]] # int 를 list로
    left = nums[:rootIndex] # list
    right = nums[rootIndex+1:] # list
    
    devcon(root, output, floor)
    devcon(left, output, floor+1)
    devcon(right, output, floor+1)
    
K = int(sys.stdin.readline().rstrip())

nums = list(map(int, sys.stdin.readline().rstrip().split(" ")))

# K 가 층의 수
output = [[] for i in range(K)]
devcon(nums, output, 0)

for i in output:
    print(" ".join(map(str, i)))