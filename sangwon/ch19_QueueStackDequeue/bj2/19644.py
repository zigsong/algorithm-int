import sys

def solve(L, Cammo):
    for i in range(L):
        hp = int(sys.stdin.readline())
        if hp > Mk*min([Ml, L]):
            if Cammo <= 0:
                return False
            Cammo -= 1
    return True

L = int(sys.stdin.readline())
Ml, Mk = map(int, sys.stdin.readline().split())
Cammo = int(sys.stdin.readline())

if solve(L, Cammo):
    print("YES")
else:
    print("NO")