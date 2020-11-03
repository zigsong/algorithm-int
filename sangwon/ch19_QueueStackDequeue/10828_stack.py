# 스택

import sys

n = int(sys.stdin.readline().rstrip())
stack = []

for i in range(n):
    inputs = sys.stdin.readline().rstrip().split(" ")
    action = ""
    number = None

    if len(inputs) == 1:
        action = inputs[0]
        number = None

    if len(inputs) == 2:
        action = inputs[0]
        number = int(inputs[1])

    if action == "push":
        stack.append(number)

    elif action == "pop":
        if len(stack) == 0:
            print(-1)
        else:
            print(stack.pop())
    elif action == "size":
        print(len(stack))
    elif action == "empty":
        if len(stack) == 0:
            print(1)
        else:
            print(0)
    elif action == "top":
        if len(stack) == 0:
            print(-1)
        else:
            print(stack[-1])