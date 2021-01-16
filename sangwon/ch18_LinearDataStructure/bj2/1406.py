# 1406 에디터

import sys

def solve(string, action, cursor, N):
    if action[0] == "L" and cursor > 0:
        cursor -= 1
    elif action[0] == "D" and cursor < N:
        cursor += 1
    elif action[0] == "B" and cursor > 0:
        del string[cursor-1]
        N -= 1
        cursor -= 1
    elif action[0] == "P":
        string.insert(cursor, action[-1])
        cursor += 1
    return string, cursor

listedString = list(sys.stdin.readline().strip())
N = len(listedString)
M = int(sys.stdin.readline())

string = listedString
cursor = N

for i in range(M):
    string, cursor = solve(string, sys.stdin.readline().strip(), cursor, N)
    
print("".join(listedString))
