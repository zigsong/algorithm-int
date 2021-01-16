# 연결 리스트를 통한 스택 구현

# class Queue:
#     class Node:
#         def __init__(self, element):
#             self.element = element
#             self.prev = None
#             self.next = None
            
#     def __init__(self):
#         self.head = None
#         self.tail = None
#     def push(self, element):
#         node = self.Node(element)
#         node.next = self.head
#         self.head = node
#     def pop(self):
#         self.hea

import sys
        
class Stack:
    class Node:
        def __init__(self, element):
            self.element = element
            self.prev = None
            
    def __init__(self):
        self.tail = None
        
    def push(self, element):
        node = self.Node(element)
        node.prev = self.tail
        self.tail = node
        
    def pop(self):
        tail = self.tail
        self.tail = self.tail.prev
        return tail.element
    
    def lastnum(self):
        if self.tail == None:
            return None
        return self.tail.element

N, P = map(int, sys.stdin.readline().split())

stacks = [0,0,0,0,0,0]
# 각 줄마다 스택 생성
for i in range(6):
    stacks[i] = Stack()
    
count = 0
for i in range(N):
    string, fret = map(int, sys.stdin.readline().split())
    stack = stacks[string-1]
    
    # 스택이 비어있거나, 마지막 요소보다 크면 추가하고 1번 누름
    if stack.lastnum() == None or stack.lastnum() < fret:
        count += 1
        stack.push(fret)

    # 스택의 마지막 요소보다 프렛이 작으면 pop
    if stack.lastnum() > fret:
        while stack.lastnum() != None and stack.lastnum() > fret:
            stack.pop()
            count += 1
        if stack.lastnum() == None or stack.lastnum() < fret:
            count += 1
            stack.push(fret)

print(count)