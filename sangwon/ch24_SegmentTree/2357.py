# 2357 최솟값과 최댓값

import sys

# 단순하게 풀기 -> 느리다
def simple():
    N, M = map(int, sys.stdin.readline().split(" "))
    nums = []

    for i in range(N):
        nums.append(int(sys.stdin.readline()))
    
    for i in range(M):
        a, b = map(int, sys.stdin.readline().split(" "))
        
        temp = nums[a-1 : b]
        print(min(temp), max(temp))

# 세그먼트 트리를 이용한 풀이
import sys      
        
class RMQ:
    def __init__(self, array, left, right):
        self.array = array
        self.rangeMin = [None for i in range(4*len(array))]
        self.rangeMax = [None for i in range(4*len(array))]
        self.left = left
        self.right = right
        self.create(left, right, 0)
        
    def min(self, a, b):
        if a > b: return b
        else: return a

    def max(self, a, b):
        if a > b: return a
        else: return b
        
    def create(self, left, right, node):
        if(left == right):
            self.rangeMin[node] = self.array[left]
            self.rangeMax[node] = self.array[left]
            return self.rangeMin[node], self.rangeMax[node]
        
        mid = (left + right) // 2
        leftMin, leftMax = self.create(left, mid, node*2+1)
        rightMin, rightMax = self.create(mid+1, right, node*2+2)
        
        self.rangeMin[node] = self.min(leftMin, rightMin)
        self.rangeMax[node] = self.max(leftMax, rightMax)
        
        return self.rangeMin[node], self.rangeMax[node]

    # left right 가 우리가 찾는 길이
    # nodeLeft nodeRight 는 해당 node 에서의 잘라가는 범우;
    def query_min_recu(self, left, right, node, nodeLeft, nodeRight):
        # 하나도 안 겹칠 때
        if nodeRight < left or right < nodeLeft: return 2**63
        if left <= nodeLeft and nodeRight <= right:
            return self.rangeMin[node]
        mid = (nodeLeft + nodeRight) // 2
        leftMin = self.query_min_recu(left, right, node*2+1, nodeLeft, mid)
        rightMin = self.query_min_recu(left, right, node*2+2, mid+1, nodeRight)
        return self.min(leftMin, rightMin)
    
    def query_max_recu(self, left, right, node, nodeLeft, nodeRight):
        # 하나도 안 겹칠 때
        if nodeRight < left or right < nodeLeft: return -(2**63)
        if left <= nodeLeft and nodeRight <= right:
            return self.rangeMax[node]
        mid = (nodeLeft + nodeRight) // 2
        leftMax = self.query_max_recu(left, right, node*2+1, nodeLeft, mid)
        rightMax = self.query_max_recu(left, right, node*2+2, mid+1, nodeRight)
        return self.max(leftMax, rightMax)
    
    def query(self, left, right):
        return self.query_min_recu(left, right, 0, 0, self.right), self.query_max_recu(left, right, 0, 0, self.right)

# 세그먼트 트리      
def segmentTree():
    N, M = map(int, sys.stdin.readline().split(" "))
    nums = []

    for i in range(N):
        nums.append(int(sys.stdin.readline()))
    
    rmq = RMQ(nums, 0, N-1)  
        
    for i in range(M):
        a, b = map(int, sys.stdin.readline().split(" "))
        a, b = rmq.query(a-1, b-1)
        print(a, b)

# simple()
segmentTree()