# 1065 한수

def isHansu(num):
    num_str = str(num)
    length = len(num_str)
    if length == 1: return 1

    diff = int(num_str[0]) - int(num_str[1])
    for i in range(1, length - 1):
        if diff != int(num_str[i]) - int(num_str[i+1]):
            return 0
    return 1
    
rangeNum = int(input())
ret = 0

for num in range(1, rangeNum+1):
    ret += isHansu(num)

print(ret)
