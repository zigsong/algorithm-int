# 6603 로또

def pick(nums, picked, toPick):
    if toPick == 0:
        print(" ".join(map(str, picked)))
        return
    for num in nums:
        picked.append(num)
        i = nums.index(num) # i 인덱스 다음부터
#         print(nums)
        pick(nums[i+1:], picked, toPick-1)
        picked.pop()

while True:
    inputs = list(map(int, input().split(" ")))
    if inputs[0] == 0: break
    nums = inputs[1:]
    picked = []
    toPick = 6
    pick(nums, picked, toPick)
    print()