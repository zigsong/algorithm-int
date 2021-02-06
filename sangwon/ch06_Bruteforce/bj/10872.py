def fac(n):
    if n == 1 or n == 0: return 1 # n == 0 빼먹으면 에러 0! = 1 이므로
    ret = n * fac(n-1)
    return ret

n = int(input())
print(fac(n))