# 큐
import sys

n = int(sys.stdin.readline())

queue = []

for i in range(n):
    # input
    action_num = sys.stdin.readline().split(" ")
    number = None
    
    if len(action_num) == 1:
        action = action_num[0].rstrip()
    else:
        action = action_num[0].rstrip()
        number = int(action_num[1].rstrip())

    if action == "push":
        # 정수를 큐에 넣는다
        queue.append(number)
    
    if action == "pop":
        # 가장 앞의 정수를 빼고, 출력한다, 없으면 -1
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[0])
            del queue[0]
    
    if action == "size":
        print(len(queue))
    
    if action == "empty":
        if len(queue) == 0:
            print(1)
        else:
            print(0)
    
    if action == "front":
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[0])
    
    if action == "back":
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[-1])
    