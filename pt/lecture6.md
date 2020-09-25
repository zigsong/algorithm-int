## Lecture6: 무식하게 풀기
by: 지은  
pub date: 2020.9.26.Sat

### 재귀 호출과 완전 탐색

**base case**
- 더 이상 쪼개지지 않는 최소한의 작업에 도달했을 때 답을 곧장 반환하는 조건문
- 모든 입력이 항상 base case에 의해 계산될 수 있도록 신경써야 함
- 주로 input이 0,1일 때 사용 (ref: p.154)


```c++

  int recursiveSum(int n) {
    if(n == 1) return 1; // base case
    return n + recursiveSum(n-1);
  }

```
- 중복된 코드(for loop 등)를 줄여줌

1. 각 단계에서 가능한 경우 실행
2. 재귀 함수 호출
3. 1 이전 상태로 복귀

[code 6-2](https://github.com/snulion-study/algorithm-int/blob/jieun/jieun/6-2/6-2.cpp)

---

#### 예제: 보글 게임  

**시간 복잡도** | 단어의 길이에 따라 지수적으로 증가  
➡️ 현재 위치를 둘러싼 상하좌우 + 대각선 4방향 = 8방향의 재귀 탐색을 하기 때문에, 8^n으로 증가

**재귀 호출** | 원래 문제의 부분 문제들로 구성

[code 6-3](https://github.com/snulion-study/algorithm-int/blob/jieun/jieun/6-3/6-3.cpp)

### 문제: 소풍
- 가능한 조합의 수 ➡️ 완전 탐색  
- 두 명씩 짝 지어준 후, 아직 짝 짓지 못한 친구들 중에서 다시 재귀 호출
- 짝 짓는 친구들끼리 중복 count 가능성
➡️ 남아있는 친구들 중에서 가장 번호가 빠른 친구로 짝 지어주기 **(제한)**

[code 6-4](https://github.com/snulion-study/algorithm-int/blob/jieun/jieun/6-4/6-4.cpp)


### 문제: 게임판 덮기  
- 블록을 놓는 순서는 중요하지 않음 (중복 count 가능성) 
➡️ 특정한 순서대로 답을 생성하도록 강제: 가장 윗줄, 가장 왼쪽부터 시작 **(제한)**
- 이거 너무 어려운 것 같음 난이도(하)라는 것에 충격

[code 6-6](https://github.com/snulion-study/algorithm-int/blob/jieun/jieun/6-6/6-6.cpp)

### 최적화 문제 
- 문제의 답이 여러 개일 때, 특정 기준에 따라 가장 '좋은' 답 찾아내기
- 완전 탐색의 방법

#### 예제: 여행하는 외판원
- 완전 탐색 - 시간 안에 답을 구할 수 있을지 확인
[code 6-7](https://github.com/snulion-study/algorithm-int/blob/jieun/jieun/6-7/6-7.cpp)

### 문제: 시계 맞추기
- 스위치를 누르는 순서는 중요하지 않음
- 각 스위치를 몇 번 누를 것인지, 조합의 문제 
- 각 스위치는 최대 3번까지만 누르면 됨 (4번 누르면 한 바퀴 돌아 원점으로 가기 때문)
- 솔직히 이건 잘 모르겠음 (solve 함수)

[code 6-8](https://github.com/snulion-study/algorithm-int/blob/jieun/jieun/6-8/6-8.cpp)

### 많이 등장하는 완전 탐색 유형  
- 모든 순열 만들기
- 모든 조합 만들기
- 2^n가지 경우의 수 만들기  
