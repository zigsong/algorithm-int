# 1065 한수

num = int(input())
length = len(str(num))
ret = 0

i = 1
while i <= num:
    if i < 10:
        ret += 1
    elif i < 100:
        ret += 1
    elif i < 1000:
        if int(str(i)[0]) - int(str(i)[1]) == int(str(i)[1]) - int(str(i)[2]):
            ret += 1
    elif i < 10000:
        if int(str(i)[0]) - int(str(i)[1]) == int(str(i)[1]) - int(str(i)[2]) and int(str(i)[1]) - int(str(i)[2]) == int(str(i)[2]) - int(str(i)[3]):
            ret += 1
    i += 1

print(ret)