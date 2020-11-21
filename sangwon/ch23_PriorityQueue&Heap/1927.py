# 1927
# 최소 힙 
# 시간초과!!!!!!! 재귀호출을 줄이자
# 우선순위 큐로 풀어야 하나?

# 힙은 리스트로 나타낼 수 있다

# 배열에 자연수 x 를 넣는다
    # 배열의 마지막에 집어넣고, 부모가 자식보다 크면 위치 바꿔주기
    
# 배열에서 가장 작은 값을 출력하고, 그 값을 배열에서 제거 -> 루트 제거
import sys

def changeEach(array, indexA, indexB):
    temp = array[indexA]
    array[indexA] = array[indexB]
    array[indexB] = temp
    return array

def upperSort(min_heap, cur):
    # 기저사례! 빼먹으면 무한 순환의 늪에 빠진다
    if cur == 0:
        return
    if min_heap[int((cur-1)//2)] > min_heap[cur]:
        changeEach(min_heap, (cur-1)//2, cur)
        upperSort(min_heap, (cur-1)//2)
    
def downSort(min_heap, cur):
    if cur*2 + 2 < len(min_heap):
        if min_heap[cur] > min_heap[cur*2 + 2]:
            changeEach(min_heap, cur, cur*2+2)
            downSort(min_heap, cur*2 + 2)
    
    if cur*2 + 1 < len(min_heap):
        if min_heap[cur] > min_heap[cur*2 + 1]:
            changeEach(min_heap, cur, cur*2+1)
            downSort(min_heap, cur*2 + 1)
            
        
N = int(sys.stdin.readline().rstrip())

min_heap = []

for i in range(N):
    x = int(sys.stdin.readline().rstrip())
        
    if x != 0:
        min_heap.append(x)
        if len(min_heap) > 1:
            cur = len(min_heap) - 1
            upperSort(min_heap, cur)
        
    else:
        # 기저사례, 비어있는 경우
        if len(min_heap) == 0:
            print(0)
        else:
            changeEach(min_heap, 0, -1)
            popped = min_heap.pop()
            print(popped)
            downSort(min_heap, 0)
            
    # print("min_heap: ", min_heap)