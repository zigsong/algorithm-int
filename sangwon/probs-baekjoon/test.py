def printTree(arr):
    n = 2
    for i, num in enumerate(arr):
        print(num, end=" ")
        if i+2 == n:
            print("")
            n = n * 2
    print("\n")
    


# node 는 트리에서의 좌표
# def init(array, rangeMin, rangeMax, left, right, node):
#     if(left == right):
#         rangeMin[node] = array[left]
#         rangeMax[node] = array[left]
#         return rangeMin[node], rangeMax[node]
#     mid = (left + right) // 2
#     leftMin, leftMax = init(array, rangeMin, rangeMax, left, mid, node*2+1)
#     rightMin, rightMax = init(array, rangeMin, rangeMax, mid+1, right, node*2+2)
#     rangeMin[node] = min(leftMin, rightMin)
#     rangeMax[node] = max(leftMax, rightMax)
#     return rangeMin[node], rangeMax[node]

# node 는 트리에서의 좌표
class RMQ:
    def __init__(self, array, left, right):
        self.array = array
        self.rangeMin = [None for i in range(4*len(array))]
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
            return self.rangeMin[node]
        mid = (left + right) // 2
        leftMin = self.create(left, mid, node*2+1)
        rightMin = self.create(mid+1, right, node*2+2)
        self.rangeMin[node] = min(leftMin, rightMin)
        return self.rangeMin[node]

    # left right 가 우리가 찾는 길이
    # nodeLeft nodeRight 는 해당 node 에서의 잘라가는 범우;
    def query_recu(self, left, right, node, nodeLeft, nodeRight):
        # 하나도 안 겹칠 때
        if nodeRight < left or right < nodeLeft: return 2**63
        if left <= nodeLeft and nodeRight <= right:
            return self.rangeMin[node]
        mid = (nodeLeft + nodeRight) // 2
        leftMin = self.query_recu(left, right, node*2+1, nodeLeft, mid)
        rightMin = self.query_recu(left, right, node*2+2, mid+1, nodeRight)
        return self.min(leftMin, rightMin)
    
    def query(self, left, right):
        return self.query_recu(left, right, 0, 0, self.right)

    def update(array, rangeMin, rangeMax, left, right, node):
        pass    
    
array = [75, 30, 100, 38, 50, 51, 52, 20, 81, 5]

rmq = RMQ(array, 0, 9)
# printTree(rmq.rangeMin)
print(rmq.query(2, 4))

# printTree(rangeMin)
# printTree(rangeMax)

