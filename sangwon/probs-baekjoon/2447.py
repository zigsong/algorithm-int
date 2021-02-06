# 별 찍기 - 10

size = int(input())

cache = [['*' for col in range(size)] for row in range(size)]

def printResult(array):
    for i in range(size):
        print("".join(array[i]))

def recursion(size, array, x, y):
    # 기저사례: 3으로 나누어지지 않으면 return
    if size == 1: return

    for i in range(int(size/3), int(size/3*2)):
        for j in range(int(size/3), int(size/3*2)):
            array[x+i][y+j] = " "

    for i in range(3):
        for j in range(3):
            recursion(int(size/3), array, x+int(i*size/3), y+int(j*size/3))

recursion(size, cache, 0, 0)
printResult(cache)