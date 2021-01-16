# 큐

import sys

n = int(sys.stdin.readline())
queue = []

for i in range(n):
    inputs = sys.stdin.readline().split(" ").rstrip()
    action = ""
    number = None

    if len(inputs) == 1:
        action = inputs[0]
    
    if len(inputs) == 2:
        action = inputs[0]
        number = int(inputs[1])

    if action == "push":
        # 정수를 큐에 넣는다
        queue.append(number)
    
    elif action == "pop":
        # 가장 앞의 정수를 빼고, 출력한다, 없으면 -1
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[0])
            del queue[0]
    
    elif action == "size":
        print(len(queue))
    
    elif action == "empty":
        if len(queue) == 0:
            print(1)
        else:
            print(0)
    
    elif action == "front":
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[0])
    
    elif action == "back":
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[-1])
    