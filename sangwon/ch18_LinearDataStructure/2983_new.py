import sys

cache = [[0 for i in range(1000000001)] for i in range(1000000001)]

N, K = map(int, sys.stdin.readline().rstrip().split(" "))
K_set = sys.stdin.readline().rstrip()

X_Y_set = []


for i in range(N):
    X, Y = map(int, sys.stdin.readline().rstrip().split(" "))
    # X_Y_set.append([X, Y])
    cache[X][Y] = 1

# for direction in K_set:
#     if direction == "A":            
#     if direction == "B":
#     if direction == "C":
#     if direction == "D":