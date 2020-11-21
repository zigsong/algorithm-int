# 덱

import sys

n = int(sys.stdin.readline().rstrip())
dequeue = []

for i in range(n):
    inputs = sys.stdin.readline().rstrip().split(" ")
    action = ""
    number = None
    
    if len(inputs) == 1:
        action = inputs[0]

    if len(inputs) == 2:
        action = inputs[0]
        number = int(inputs[1])
        
    if action == "push_front":
        temp = [number]
        temp.extend(dequeue)
        dequeue = temp

    elif action == "push_back":
        dequeue.append(number)

    elif action == "pop_front":
        if len(dequeue) == 0:
            print(-1)
            continue
        print(dequeue[0])
        del dequeue[0]

    elif action == "pop_back":
        if len(dequeue) == 0:
            print(-1)
            continue
        print(dequeue[-1])
        del dequeue[-1]

    elif action == "size":
        print(len(dequeue))

    elif action == "empty":
        if len(dequeue) == 0:
            print(1)
        else:
            print(0)

    elif action == "front":
        if len(dequeue) == 0:
            print(-1)
            continue
        print(dequeue[0])

    elif action == "back":
        if len(dequeue) == 0:
            print(-1)
            continue
        print(dequeue[-1])