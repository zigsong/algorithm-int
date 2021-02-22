# https://www.acmicpc.net/problem/1976
import sys

input = sys.stdin.readline

n_of_cities = int(input())
n_in_plan = int(input())

parent = [i for i in range(n_of_cities)]

def find(target):
    if target == parent[target]:
        return target
    
    # 자신이 속한 그룹의 번호로 해당 위치의 수를 바꾼다.
    parent[target] = find(parent[target])
    return parent[target]

def union(a, b):
    a = find(a)
    b = find(b)
    
    # 작은 쪽이 부모, 가장 작은 번호가 해당 집합의 번호
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

for i in range(n_of_cities):
    for j, is_connected in enumerate(map(int, input().split())):
        if is_connected == 1:
            union(i, j)
            
temp = None
for i in map(int, input().split()):
    if temp == None:
        temp = find(i-1)
    else:
        if temp != find(i-1):
            print("NO")
            break
else:
    print("YES")