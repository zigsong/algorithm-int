# https://www.acmicpc.net/problem/1717
import sys

input = sys.stdin.readline

sys.setrecursionlimit(1000000) # 1 ≤ n ≤ 1,000,000
# 최악의 경우 뒤에서부터 2개씩 바꾸며 앞으로 내려오고, find(1000000)을 하면 
# recursion 이 1000000 번 일어난다


n, m = map(int, input().split())
parent = [i for i in range(n+1)]

def find(target):
    if target == parent[target]:
        return target
    
    # 자신이 속한 그룹의 번호로 해당 위치의 수를 바꾼다. recursion
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
    

for _ in range(m):
    code, a, b = map(int, input().split())
    if code == 0:
        union(a, b)
    else:
        if find(a) == find(b):
            print('YES')
        else:
            print('NO')