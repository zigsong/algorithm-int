# 개구리 공주
# 시간 초과된 코드!

import sys

N, K = map(int, sys.stdin.readline().rstrip().split(" "))
K_set = sys.stdin.readline().rstrip()

X_Y_set = []

for i in range(N):
    X, Y = map(int, sys.stdin.readline().rstrip().split(" "))
    X_Y_set.append([X, Y])

now_X = X_Y_set[0][0]
now_Y = X_Y_set[0][1]

# A ++, B +- C -+ D --
for direction in K_set:
    dist = 1000000000
    minIndex = None
    
    # print("Now:", now_X, now_Y)

    if direction == 'A':
        for i in range(1, len(X_Y_set)):
            # print(X_Y_set[i][0], Y_set[i])
            # print(X_Y_set[i][0] - Y_set[i] == now_X - now_Y and X_Y_set[i][0] > now_X)
            
            if X_Y_set[i][0] - X_Y_set[i][1] == now_X - now_Y and X_Y_set[i][0] > now_X and X_Y_set[i][0] - now_X < dist:
                dist = X_Y_set[i][0] - now_X
                minIndex = i

        if minIndex == None:
            print(now_X, now_Y)
            break
        
        temp_X = X_Y_set[minIndex][0]
        temp_Y = X_Y_set[minIndex][1]

        X_Y_set.remove([now_X, now_Y])

        now_X = temp_X
        now_Y = temp_Y
        # print("Next:", now_X, now_Y)

    elif direction == 'B':
        for i in range(1, len(X_Y_set)):
            # print(X_Y_set[i][0], X_Y_set[i][1])
            # print(X_Y_set[i][0] + X_Y_set[i][1] == now_X + now_Y and X_Y_set[i][0] > now_X)        
            if X_Y_set[i][0] + X_Y_set[i][1] == now_X + now_Y and X_Y_set[i][0] > now_X and X_Y_set[i][0] - now_X < dist:
                dist = X_Y_set[i][0] - now_X
                minIndex = i

        if minIndex == None:
            print(now_X, now_Y)
            break

        temp_X = X_Y_set[minIndex][0]
        temp_Y = X_Y_set[minIndex][1]

        X_Y_set.remove([now_X, now_Y])

        now_X = temp_X
        now_Y = temp_Y
        # print("Next:", now_X, now_Y)        

    elif direction == 'C':
        for i in range(1, len(X_Y_set)):
            # print(X_Y_set[i][0], X_Y_set[i][1])
            # print(X_Y_set[i][0] + X_Y_set[i][1] == now_X + now_Y and X_Y_set[i][0] < now_X)
            if X_Y_set[i][0] + X_Y_set[i][1] == now_X + now_Y and X_Y_set[i][0] < now_X and now_X - X_Y_set[i][0] < dist:
                dist = now_X - X_Y_set[i][0]
                minIndex = i

        if minIndex == None:
            print(now_X, now_Y)
            break

        temp_X = X_Y_set[minIndex][0]
        temp_Y = X_Y_set[minIndex][1]

        X_Y_set.remove([now_X, now_Y])

        now_X = temp_X
        now_Y = temp_Y
        # print("Next:", now_X, now_Y)

    elif direction == 'D':
        for i in range(1, len(X_Y_set)):
            # print(X_Y_set[i][0], X_Y_set[i][1])
            # print(X_Y_set[i][0] - X_Y_set[i][1] == now_X - now_Y and X_Y_set[i][0] < now_X)
            if X_Y_set[i][0] - X_Y_set[i][1] == now_X - now_Y and X_Y_set[i][0] < now_X and now_X - X_Y_set[i][0] < dist:
                dist = now_X - X_Y_set[i][0]
                minIndex = i

        if minIndex == None:
            print(now_X, now_Y)
            break

        temp_X = X_Y_set[minIndex][0]
        temp_Y = X_Y_set[minIndex][1]

        X_Y_set.remove([now_X, now_Y])

        now_X = temp_X
        now_Y = temp_Y
        # print("Next:", now_X, now_Y)
                 