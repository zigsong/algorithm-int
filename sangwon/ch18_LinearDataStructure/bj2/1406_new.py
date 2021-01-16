# 1406 
import sys

class ListNode:
    def __init__(self, element):
        self.element = element
        self.prev = None
        self.next = None
        
class LinkedList:
    def __init__(self):
        head = ListNode(0)
        self.head = head
        self.now = head
        
    def append(self, node):
        now = self.now
        next = self.now.next
        node.next = next
        node.prev = now
        now.next = node
        if next != None:
            next.prev = node
        self.now = self.now.next
    
    def leftMove(self):
        if self.now.prev != None:
            self.now = self.now.prev
            
    def rightMove(self):
        if self.now.next != None:
            self.now = self.now.next
       
    def delete(self):
        if self.now.prev != None:
            prev = self.now.prev
            next = self.now.next
            prev.next = next
            if next != None:
                next.prev = prev
            self.now = prev
    
    def print(self):
        cur = self.head.next
        while cur.next != None:
            print(cur.element, end="")
            cur = cur.next
        print(cur.element)
            
        
string = sys.stdin.readline().strip()

linked = LinkedList()
for char in string:
    linked.append(ListNode(char))
    
M = int(sys.stdin.readline())
for i in range(M):
    action = sys.stdin.readline().strip()
    if action[0] == "L":
        linked.leftMove()
    elif action[0] == "D":
        linked.rightMove()
    elif action[0] == "B":
        linked.delete()
    elif action[0] == "P":
        linked.append(ListNode(action[-1]))

linked.print()