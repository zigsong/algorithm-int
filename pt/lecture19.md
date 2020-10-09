# Lecture 19: 큐와 스택, 데크

by | 혜민

pub date | 2020.10.09.Fri

### 1. 큐, 스택, 데크

- 일렬로 늘어선 종류의 자료를 넣고 꺼내는 연산 지원
- 자료는 특정한 순서로만 꺼낼 수 있음
- 구현 자체는 배열이나 연결 리스트로도 가능하지만 자료 구조 자체에 이름을 붙였다는 데에 의의가 있다!

  > **큐(Queue)** : 선입선출(FIFO, First In First Out)
  >
  > **스택(Stack)** : 후입선출(LIFO, Last In First Out)
  >
  > **데크(Double-ended queue)** : 양쪽 끝에서 자료들을 넣고 뺄 수 있는 구조, 스택과 큐를 모두 구현가능
  >
  > 모든 구조에 대해 push()와 pop()은 O(1)의 시간 복잡도를 가져야 함

---

### 2. 큐와 스택, 데크의 구현

#### 연결 리스트를 통한 구현

- 가장 간단한 방법
- 추가와 삭제를 상수 시간에 할 수 있음
- 노드의 할당과 삭제, 포인터를 따라가는데에 시간 소요


#### 동적 배열을 이용한 구현

- 한 쪽 끝에서만 자료의 추가와 삭제가 일어나는 스택의 경우 간단
- 큐와 데크의 경우 head와 tail을 관리하면서 환형 버퍼를 통해 구현

---

### 3. 스택과 큐의 활용

[code 18-2](../hyemin/18_LinearDataStructure/Josephus.cpp)
#### 예제 : 큐를 이용한 조세푸스 문제의 해법

```c++
void josephusQueue(int n, int k)
{
    // 큐를 준비한다
    queue<int> survivors;
    for (int i = 1; i <= n; i++)
        survivors.push(i);

    // queue.size() 는 O(1) 이기 때문에
    // 두 명이 남을 때까지
    while (survivors.size() > 2)
    {
        // 한명을 꺼내서 버린다
        survivors.pop();

        // k-1 명을 맨 앞에서 꺼내 큐의 뒤로 보낸다
        for (int i = 0; i < k - 1; i++)
        {
            // 구현은 뒤로 넣는 게 먼저! 
            // 지금 맨 앞 사람을 뒤에 추가해준 후
            survivors.push(survivors.front());
            // 맨 앞 사람 뽑기
            survivors.pop();
        }
    }
    // 남은 두 사람이 생존자
    int a = survivors.front();
    survivors.pop();
    int b = survivors.front();
    if (a > b)
        swap(a, b);
    cout << a << " " << b << endl;
}
```
큐로 구현해도 시간 복잡도는 O(NK)로 동일하지만 자잘한 구현이 간단해진다

[code 19-1](../hyemin/19_QueueStackDequeue/FenceByStack.cpp)
#### 예제 : 스택을 이용한 울타리 자르기 문제의 해법

```c++
// 각 판자의 높이를 저장하는 배열
vector<int> h;
// 스택을 사용한 O(n) 해법
int solveStack()
{
    // 남아 있는 판자들의 위치를 저장
    stack<int> remaining;
    // 맨 오른쪽에 높이가 0인 가상의 판자를 추가하여 모든 판자의 right[i]을 정의
    h.push_back(0);
    int ret = 0;
    for (int i = 0; i < h.size(); ++i)
    {
        // 남아 있는 판자들 중 오른쪽 끝 판자가 h[i]보다 높다면
        // 이 판자의 최대 사각형은 i에서 끝
        while (!remaining.empty() && h[remaining.top()] >= h[i])
        {
            int j = remaining.top();
            remaining.pop();
            int width = -1;
            // j번째 판자 왼쪽에 판자가 하나도 안 남아 있는 경우 left[i]=-1,
            // 아닌 경우 left[j] = 남아있는 판자 중 가장 오른쪽에 있는 판자의 번호
            if (remaining.empty())
                width = i;
            else
                width = (i - remaining.top() - 1);
            ret = max(ret, h[j] * width);
        }
        remaining.push(i);
    }
    return ret;
}
```
---

### 4. 문제 : 짝이 맞지 않는 괄호 (ID:Brackets2)
[code 19-2](../hyemin/19_QueueStackDequeue/Brackets2.cpp)

```c++
bool wellMatched(const string &formula)
{
    // 여는 괄호 문자들과 닫는 괄호 문자들
    const string opening("({["), closing(")}]");
    // 이미 열린 괄호들을 순서대로 담는 스택
    stack<char> openStack;
    for (int i = 0; i < formula.size(); ++i)
        // 여는 괄호인지 닫는 괄호인지 확인
        if (opening.find(formula[i]) != -1)
            // 여는 괄호라면 스택에 집어넣음
            openStack.push(formula[i]);

        // 여는 괄호가 아닌 경우 스택 맨 위의 문자와 맞춰보기
        // 스택이 비어 있는 경우는 실패
        else
        {
            // 다 닫혀서 없는 경우는 성공 아닌가? for문 다 돌기 전에 stack이 비었다고 해서 실패인 건 아닌데,,
            // 어차피 지금 false처리 해줘도 비어 있으면 for문 다 돌고 최종적으로는 true를 리턴할텐데 왜 굳이 false 처리를 하는가?
            // 아 openStack.pop()까지 가지 않게 하기 위한 처리! 그냥 현재 들어온 문자와 짝을 이루지 않는다는 의미의 false인듯
            if (openStack.empty())
                return false;
            // 서로 짝이 맞지 않아도 실패
            if (opening.find(openStack.top()) != closing.find(formula[i]))
                return false;
            // 짝을 맞춘 괄호는 스택에서 뺀다
            openStack.pop();
        }
    // 닫히지 않은 괄호가 없어야 성공
    return openStack.empty();
}
```

---

### 5. 문제 : 외계 신호 분석 (ID: Ites)
  
[code 19-3](../hyemin/18_LinearDataStructure/Ites.cpp)

- 온라인 알고리즘 : 전체 입력이 한꺼번에 주어지지 않아도 계산을 시작할 수 있는 알고리즘
- 오프라인 알고리즘 : 입력 전체를 이미 가지고 있다고 가정하고 동작하는 알고리즘

```C++
// 모든 입력을 저장할 수 있다고 가정
// 가장 단순한 오프라인 알고리즘
int simple(const vector<int> &signals, int k)
{
    int ret = 0;
    for (int head = 0; head < signals.size(); ++head)
    {
        int sum = 0;
        for (int tail = head; tail < signals.size(); ++tail)
        {
            // sum은 [head,tail] 구간의 합
            sum += signals[tail];
            // 부분수열의 합이 k이면 정답 부분수열의 개수 +1
            if (sum == k)
                ret++;
            // k보다 크면 부분수열 만들기 실패
            if (sum >= k)
                break;
        }
    }
}
```
시간 복잡도는 O(NK)

head가 증가할 때 후보 구간에서 tail이 줄어들지 않는 점을 이용해 최적화할 수 있다

```c++
// 최적화된 알고리즘
int optimized(const vector<int> &signals, int k)
{
    // tail이 for문 밖에 선언되어있어 head가 변해도 그대로! (최적화)
    // rangeSum 또한 head만 빠진 값으로 재사용된다 
    int ret = 0, tail = 0, rangeSum = signals[0];
    for (int head = 0; head < signals.size(); ++head)
    {
        // rangeSum이 k 이상인 최초의 구간을 만날 때까지 tail을 옮긴다
        while (rangeSum < k && tail + 1 < signals.size())
            rangeSum += signals[++tail];

        if (rangeSum == k)
            ret++;
        // signals[head]는 구간 탈출
        rangeSum -= signals[head];
    }
    return ret;
}
```
시간 복잡도는 O(N)

head가 증가하고 나면 지나쳐온 숫자들을 고려할 필요가 없다는 점을 이용해 모든 input을 저장할 필요 없는 온라인 알고리즘을 만들 수 있다

```c++
// 온라인 알고리즘
int countRanges(int k, int n)
{
    RNG rng;          // 신호값을 생성하는 난수 생성기
    queue<int> range; // 현재 구간에 들어있는 숫자들을 저장하는 큐
    int ret = 0, rangeSum = 0;
    for (int i = 0; i < n; i++)
    {
        // 구간에 숫자 추가
        int newSignal = rng.next();
        rangeSum += newSignal;
        range.push(newSignal);

        // 구간의 합이 k를 초과하는 동안 구간에서 숫자를 뺀다
        // 최적화와는 반대로 합이 k 이하인 후보 구간을 유지
        while (rangeSum > k)
        {
            rangeSum -= range.front();
            range.pop();
        }

        if (rangeSum == k)
            ret++;
    }
    return ret;
}
```


