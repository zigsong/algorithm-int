# https://www.acmicpc.net/problem/14725
import sys

input = sys.stdin.readline

class Node:
    def __init__(self, key, level=0):
        self.key = key
        self.level = level
        self.children = {}
        
class Trie:
    def __init__(self):
        self.head = Node(None)
    
    def insert(self, lst):
        cur_node = self.head
        
        for i, elem in enumerate(lst):
            # cur_node 의 자손중에 없으면 새로 노드 생성
            if elem not in cur_node.children:
                cur_node.children[elem] = Node(key=elem, level=i)
                
            cur_node = cur_node.children[elem]
    
    def print(self):
        self.__print_rec(self.head)
            
    def __print_rec(self, cur_node):
        if cur_node.key is not None:
            print("--" * cur_node.level + cur_node.key)
        
        for child in sorted(cur_node.children):
            self.__print_rec(cur_node.children[child])
        
        
        
n_of_info = int(input())

trie = Trie()

for _ in range(n_of_info):
    temp = input().strip().split()
    n_of_foods = temp[0]
    foods = temp[1:]

    trie.insert(foods)
    
trie.print()