# 쿼드트리

def recursion(size, array): # 크기, 어레이 시작 좌표
    # 기저사례 1, 크기가 1이면 리턴한다.
    if size == 1: return array[0][0]
    # 기저사례 2, 모두 0이면 0 반환, 1이면 1 반환
    sum = 0
    for i in range(size):
        for j in range(size):
            sum += int(array[i][j])
    if sum == 0: return '0'
    elif sum == size**2: return '1'
    
    # 재귀 호출, 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래 순서
    nw = recursion(int(size/2), [row[:int(size/2)] for row in array[:int(size/2)]])
    ne = recursion(int(size/2), [row[int(size/2):] for row in array[:int(size/2)]])
    sw = recursion(int(size/2), [row[:int(size/2)] for row in array[int(size/2):]])
    se = recursion(int(size/2), [row[int(size/2):] for row in array[int(size/2):]])
    
    return '(' + nw + ne + sw + se + ')'


size = int(input())

array = []

for i in range(size):
    array.append(list(input()))

print(recursion(size, array))