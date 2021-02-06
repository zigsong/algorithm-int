# 6603 로또

def printlist(lst):
    print(" ".join(map(str, lst)))

def lotto(k, s, picked, start):
    if len(picked) == 6: 
        printlist(picked)
        return
    for i in range(start, k):
        picked.append(s[i])
        lotto(k, s, picked, i+1)
        picked.pop()

while True:
    nums = list(map(int, input().split()))
    if nums[0] == 0: break
    k = nums[0]
    s = nums[1:]
    lotto(k, s, [], 0)
    print()