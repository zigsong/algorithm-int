# ch6(bruteforce) - 백준 문제 풀이

by | 상원  
pub date | 2020.12.26.Sat



## [2798 - 블랙잭](../sangwon/ch06_Bruteforce/bj2/2798.py)

### 입력

첫째 줄에 카드의 개수 N(3 ≤ N ≤ 100)과 M(10 ≤ M ≤ 300,000)이 주어진다. 둘째 줄에는 카드에 쓰여 있는 수가 주어지며, 이 값은 100,000을 넘지 않는다.

합이 M을 넘지 않는 카드 3장을 찾을 수 있는 경우만 입력으로 주어진다.

### 출력

첫째 줄에 M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 출력한다.

### 풀이

```python
import sys

def bruteforce(n, m, nums):
    ret = 0
    for i in range(0, n-2):
        for j in range(i+1, n-1):
            for k in range(j+1, n):
                sum = nums[i] + nums[j] + nums[k]
                if sum <= m: ret = max([sum, ret])
    return ret
            
n, m = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))

print(bruteforce(n, m, nums))
```





## [2231 - 분해합](../sangwon/ch06_Bruteforce/bj2/2231.py)

### 문제

어떤 자연수 N이 있을 때, 그 자연수 N의 분해합은 N과 N을 이루는 각 자리수의 합을 의미한다. 어떤 자연수 M의 분해합이 N인 경우, M을 N의 생성자라 한다. 예를 들어, 245의 분해합은 256(=245+2+4+5)이 된다. 따라서 245는 256의 생성자가 된다. 물론, 어떤 자연수의 경우에는 생성자가 없을 수도 있다. 반대로, 생성자가 여러 개인 자연수도 있을 수 있다.

자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구해내는 프로그램을 작성하시오.

### 입력

첫째 줄에 자연수 N(1 ≤ N ≤ 1,000,000)이 주어진다.

### 출력

첫째 줄에 답을 출력한다. 생성자가 없는 경우에는 0을 출력한다.

### 풀이

```python
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
```





## [10872 - 팩토리얼](../sangwon/ch06_Bruteforce/bj2/10872.py)

### 입력

첫째 줄에 정수 N(0 ≤ N ≤ 12)가 주어진다.

### 출력

첫째 줄에 N!을 출력한다.

### 풀이

```python
def fac(n):
    if n == 1 or n == 0: return 1 # n == 0 빼먹으면 에러 0! = 1 이므로
    ret = n * fac(n-1)
    return ret

n = int(input())
print(fac(n))
```





## [10870 - 피보나치 수 5](../sangwon/ch06_Bruteforce/bj2/10870.py)

### 입력

첫째 줄에 n이 주어진다. n은 20보다 작거나 같은 자연수 또는 0이다.

### 출력

첫째 줄에 n번째 피보나치 수를 출력한다.

### 풀이

```python
import sys
sys.setrecursionlimit(10000)

# bruteforce 10870번(n<20)
def fibonacci(n):
    if n == 0: return 0
    if n == 1: return 1
    ret = fibonacci(n-1) + fibonacci(n-2)
    return ret

# dp 2748번(n<=90), 2747번(n<=45)
def fibo_dp(n, cache):
    if n == 0: return 0
    if n == 1: return 1
    if cache[n] != -1: return cache[n]
    cache[n] = fibo_dp(n-1, cache) + fibo_dp(n-2, cache)
    return cache[n]

# 10826 (n <= 10,000)
# D&Q 2749번(n <= 1,000,000,000,000,000,000) 
def fibo_dq():
    pass

n = int(input())
cache = [-1 for i in range(n+1)]
print(str(fibo_dp(n, cache)))

```





# 예전에 푼 문제

## [6603 - 로또](../sangwon/ch06_Bruteforce/bj1/5503.py)

### 문제

독일 로또는 {1, 2, ..., 49}에서 수 6개를 고른다.

로또 번호를 선택하는데 사용되는 가장 유명한 전략은 49가지 수 중 k(k>6)개의 수를 골라 집합 S를 만든 다음 그 수만 가지고 번호를 선택하는 것이다.

예를 들어, k=8, S={1,2,3,5,8,13,21,34}인 경우 이 집합 S에서 수를 고를 수 있는 경우의 수는 총 28가지이다. ([1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34])

집합 S와 k가 주어졌을 때, 수를 고르는 모든 방법을 구하는 프로그램을 작성하시오.

### 입력

입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있다. 첫 번째 수는 k (6 < k < 13)이고, 다음 k개 수는 집합 S에 포함되는 수이다. S의 원소는 오름차순으로 주어진다.

입력의 마지막 줄에는 0이 하나 주어진다. 

### 출력

각 테스트 케이스마다 수를 고르는 모든 방법을 출력한다. 이때, 사전 순으로 출력한다.

각 테스트 케이스 사이에는 빈 줄을 하나 출력한다.

### 풀이

```python
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
```





## [1065 - 한수](../sangwon/ch06_Bruteforce/bj1/1065.py)

### 문제

어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 

### 입력

첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.

### 출력

첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.

### 풀이

```python
def isHansu(num):
    num_str = str(num)
    length = len(num_str)
    if length == 1: return 1

    diff = int(num_str[0]) - int(num_str[1])
    for i in range(1, length - 1):
        if diff != int(num_str[i]) - int(num_str[i+1]):
            return 0
    return 1
    
rangeNum = int(input())
ret = 0

for num in range(1, rangeNum+1):
    ret += isHansu(num)

print(ret)
```



