# 2042 세그먼트 트리

# 세그먼트 트리를 사용하지 않은 간단한 구현 -> 시간 초과
import sys

N, M, K = map(int, sys.stdin.readline().rstrip().split(" "))

nums = []

for i in range(2, N+2):
    num = int(sys.stdin.readline().rstrip())
    nums.append(num)

## segment tree ##
for i in range(N+2, N+M+K+2):
    a, b, c = map(int, sys.stdin.readline().rstrip().split(" "))
    if a == 1:
        # b 번째 수를 c 로 바꾼다
        nums[b-1] = c
        
    elif a == 2:
        # b 번째 수부터 c번째 수까지의 합을 구하여 출력
        print(sum(nums[b-1:c]))


##### 세그먼트 트리를 사용하지 않은 구현!
# for i in range(N+2, N+M+K+2):
#     a, b, c = map(int, sys.stdin.readline().rstrip().split(" "))
#     if a == 1:
#         # b 번째 수를 c 로 바꾼다
#         nums[b-1] = c
        
#     elif a == 2:
#         # b 번째 수부터 c번째 수까지의 합을 구하여 출력
#         print(sum(nums[b-1:c]))
        
