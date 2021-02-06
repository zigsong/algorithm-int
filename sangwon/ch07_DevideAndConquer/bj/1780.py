# 종이의 개수
import sys    

def check(matrix):
    first = matrix[0][0]
    for row in matrix: 
        for element in row:
            if element != first:
                return False
    return True
            
def numOfPaper(n, matrix, result):
    # 크기가 1인 경우
    if n == 1:
        if matrix[0][0] < 0:
            result[0] += 1
        elif matrix[0][0] == 0:
            result[1] += 1
        else:
            result[2] += 1
        return
    # 모두가 같은 숫자인 경우
    if check(matrix):
        if matrix[0][0] < 0:
            result[0] += 1
        elif matrix[0][0] == 0:
            result[1] += 1
        else:
            result[2] += 1
        return

    for i in range(3):
        for j in range(3):
            ret = numOfPaper(
                n//3, 
                [row[j * n//3 : (j+1) * n//3] for row in matrix[i * n//3 : (i+1) * n//3]],
                result
            )

n = int(sys.stdin.readline())
matrix = []

for i in range(n):
    matrix.append(list(map(int, sys.stdin.readline().split())))

result = [0,0,0]
numOfPaper(n, matrix, result)

for i in result:
    print(i)