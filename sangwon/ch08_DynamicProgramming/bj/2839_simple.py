# 설탕 배달
# 굳이 DP 로 풀 이유가 있나?, 시간 초과 문제

# 우선 Bruteforce

# 1 -> 5 1개 빼고 3 2개 추가
# 2 -> 5 2개 빼고 3 4개 추가
# 3 -> 3 1개 추가
# 4 -> 5 1개 빼고 3 3개 추가

def sugar(N):
    if N == 4: return -1
    if N % 5 == 1:
        return N // 5 + 1
    elif N % 5 == 2:
        return N // 5 + 2
    elif N % 5 == 3:
        return N // 5 + 1 
    elif N % 5 == 4:
        return N // 5 + 2
    else:
        return N // 5


N = int(input())
print(sugar(N))