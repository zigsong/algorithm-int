def bruteforce(n):
    for i in range(1, n+1):
        if decomp(i) == n: return i
    return 0

def decomp(n):
    sum = n
    n_str = str(n)
    for i in n_str:
        sum += int(i)
    return sum
        
n = int(input())

print(bruteforce(n))