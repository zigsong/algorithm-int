# https://www.acmicpc.net/problem/5052
import sys

input = sys.stdin.readline

class Node:
    def __init__(self, key, data=None):
        self.key = key
        self.data = data
        self.children = {}
        
class Trie:
    def __init__(self):
        self.head = Node(None)
    
    def insert(self, string):
        cur_node = self.head
        
        for char in string:
            # cur_node 의 자손중에 없으면 새로 노드 생성
            if char not in cur_node.children:
                cur_node.children[char] = Node(char)
                
            cur_node = cur_node.children[char]
        
        if cur_node.children == {}:
            return True
        else:
            return False
        
        
n_of_test_case = int(input())

for _ in range(n_of_test_case):
    n_of_number = int(input())
    numbers = []
    for _ in range(n_of_number):
        numbers.append(input().strip())
    numbers.sort(reverse=True)
    
    trie = Trie()
    for number in numbers:
        if trie.insert(number) == False:
            print('NO')
            break
    else:
        print('YES')
        