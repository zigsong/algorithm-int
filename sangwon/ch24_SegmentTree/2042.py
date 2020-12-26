# 2042 세그먼트 트리

import sys

def printTree(arr):
    n = 2
    for i, num in enumerate(arr):
        print(num, end=" ")
        if i+2 == n:
            print("")
            n = n * 2
    print("\n")

# 세그먼트 트리를 사용하지 않은 간단한 구현 -> 시간 초과
def simple():
    N, M, K = map(int, sys.stdin.readline().rstrip().split(" "))

    nums = []

    for i in range(2, N+2):
        num = int(sys.stdin.readline().rstrip())
        nums.append(num)

    for i in range(N+2, N+M+K+2):
        a, b, c = map(int, sys.stdin.readline().rstrip().split(" "))
        if a == 1:
            # b 번째 수를 c 로 바꾼다
            nums[b-1] = c
            
        elif a == 2:
            # b 번째 수부터 c번째 수까지의 합을 구하여 출력
            print(sum(nums[b-1:c]))

import sys

class Segment:
    def __init__(self, array, N):
        self.array = array
        self.rangeSum = [None for i in range(4*N)]
        self.N = N
        self.create(left=0, right=N-1, node=0)
    
    def create(self, left, right, node):
        if left == right:
            sum = self.array[left]
            self.rangeSum[node] = sum
            return sum
        mid = (left + right) // 2
        leftSum = self.create(left, mid, 2*node+1)
        rightSum = self.create(mid+1, right, 2*node+2)
        sum = leftSum + rightSum     
        self.rangeSum[node] = sum
        return sum
    
    def update_rec(self, index, newValue, node, nodeLeft, nodeRight):
        if index < nodeLeft or nodeRight < index:
            return self.rangeSum[node]
        if nodeLeft == nodeRight:
            self.rangeSum[node] = newValue
            return newValue
        mid = (nodeLeft + nodeRight) // 2
        self.rangeSum[node] = (
            self.update_rec(index, newValue, 2*node+1, nodeLeft, mid) 
            + self.update_rec(index, newValue, 2*node+2, mid+1, nodeRight)
        )
        return self.rangeSum[node]
    
    def update(self, index, newValue):
        self.array[index] = newValue
        self.update_rec(index, newValue, 0, 0, self.N-1)
    
    def query_rec(self, left, right, node, nodeLeft, nodeRight):
        if right < nodeLeft or nodeRight < left:
            return 0
        if left <= nodeLeft and nodeRight <= right:
            return self.rangeSum[node]
        mid = (nodeLeft + nodeRight) // 2
        return (
            self.query_rec(left, right, 2*node+1, nodeLeft, mid) 
            + self.query_rec(left, right, 2*node+2, mid+1, nodeRight)
        )
            
    def query(self, left, right):
        return self.query_rec(left, right, 0, 0, self.N-1)
        

def segmentTree():
    N, M, K = map(int, sys.stdin.readline().rstrip().split(" "))

    nums = []

    for i in range(N):
        num = int(sys.stdin.readline().rstrip())
        nums.append(num)
    
    segment = Segment(nums, N)

    for i in range(M+K):
        a, b, c = map(int, sys.stdin.readline().rstrip().split(" "))
        
        if a == 1:
            # b 번째 수를 c 로 바꾼다   
            segment.update(index=b-1, newValue=c)
            
        elif a == 2:
            # b 번째 수부터 c번째 수까지의 합을 구하여 출력
            print(segment.query(left=b-1, right=c-1))
     
segmentTree()       
# simple()
