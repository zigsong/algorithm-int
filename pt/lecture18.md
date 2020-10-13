# Lecture 18: 선형 자료구조

by | 혜민

pub date | 2020.10.09.Fri

### 선형 자료구조

- 일렬로 늘어선 종류의 자료 여러 개를 저장하기 위한 가장 기초적인 자료 구조
- 대표적으로 동적 배열과 연결 리스트가 있음
- 서로 다른 특성과 장점을 가지고 있음

---

### 1. 동적 배열

- 기존 배열의 문제 : 처음 배열을 선언할 때 배열의 크기를 지정해야 함
- 동적 배열 : 자료의 개수에 따라 크기가 변경됨 (기존 배열을 통해 만들어낸 별도의 자료 구조)
- 동적 배열의 특성
  - 배열의 크기를 변경하는 `resize()` 연산이 가능하고 시간 복잡도는 O(n)
  - 주어진 원소를 배열의 맨 끝에 추가하는 `append()` 연산이 가능하고 시간 복잡도는 O(1)
  


#### 동적 배열의 재할당 과정

```c++
// 배열 용량이 꽉 찼으면 재할당받는다
if (size == capacity)
{
    // 용량을 M만큼 늘린 새 배열을 할당받는다
    int newCapacity = capacity + M;
    int *newArray = new int[newCapacity];
    // 기존의 자료를 복사한다
    for (int i = 0; i < size; i++)
        newArray[i] = array[i];
    // 기존 배열을 삭제하고 새 배열로 바꿔치기
    if (array)
        delete[] array;
    array = newArray;
    capacity = newCapacity;
}
// 배열의 끝에 원소 삽입
array[size++] = newValue;
```
재할당 과정의 시간 복잡도는 O(N+M)

-> `append()`과정을 여러 번 거치면 언젠가 재할당되는 순간이 있을텐데, 어떻게 `append()`의 시간 복잡도가 O(1)일까?



#### 동적 배열의 재할당 전략

`append()`와 같이 호출할 때마다 수행 시간이 달라지는 경우 수행 시간의 평균으로 시간 복잡도를 계산

따라서 재할당을 효율적으로 하는 것이 중요!

-> 상수 시간에 `append()` 를 구현하는 방법은 현재 가진 원소에 개수에 비례해서 여유분을 확보하는 것

```
n번의 append() 연산을 하는데, 배열 용량을 1부터 시작하여 2배씩 늘린다고 가정해보자

i(i>=0)번째의 재할당 시에 복사하는 원소의 개수는 2^i개

...

n번째 재할당 시에 복사하는 원소의 개수는 2^n-1개

이므로 전체 과정에서 복사하는 원소의 개수는 2^0+2^1+2^2+...+2^k-1 = (2^k-1)-1 + 2^k-1이므로 이는 시간 복잡도가 O(N) + O(N) = O(N)

따라서 한 번의 append() 연산의 시간 복잡도는 O(N)/N = O(1)이라고 할 수 있음

```

---

### 2. 연결 리스트

- 동적 배열의 문제 : 임의의 위치에 원소를 삽입하거나 삭제하는 데에 시간이 오래 걸림 (O(N))
- 연결 리스트 : 원소들이 메모리에 흩어져 있고 다음 원소룰 가리키는 포인터를 가지고 있는 자료구조
- 연결 리스트의 특성
  - i번째 노드를 찾는 연산의 시간 복잡도가 O(N)
  - 새 노드를 삽입하거나 삭제하는 연산의 시간 복잡도가 O(1)
  - 한 리스트를 다른 리스트에 삽입하는 연산 `splicing()` 또한 시간 복잡도가 O(1)
  - 삭제했던 원소를 돌려놓는 `recoverNode()` 도 포인터를 다시 돌려놓는 방법으로 가능
  

[code 18-1](../hyemin/18_LinearDataStructure/LinkedList.cpp)
```C++
// 연결 리스트에서 노드를 삭제하고 다시 추가하기

// node 이전/이후 노드의 포인터를 바꿔서 node를 리스트에서 삭제(접근할 수 없게)한다
void deleteNode(ListNode *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

// node 이전/이후의 노드의 포인터를 바꿔서 자기 자신을 다시 리스트에 삽입(접근할 수 있게)한다
void recoverNode(ListNode *node)
{
    node->prev->next = node;
    node->next->prev = node;
}
}
```
---

### 3. 동적 배열과 연결 리스트의 비교


| 작업 | 동적 배열 | 연결 리스트 |
| :------------: | :-----------: | :-------------------: |
| 이전 원소/ 다음 원소 찾기 | O(1) | O(1)  | 
| 맨 뒤에 원소 추가/삭제하기 | O(1)  | O(1)  |
| 맨 뒤 이외의 위치에 원소 추가/삭제하기 | **O(n)** | **O(1)** |
| 임의의 위치의 원소 찾기 | **O(1)** | **O(n)** |
| 크기 구하기 | **O(1)**  | **O(n)** 혹은 구현에 따라 O(1) |

---


### 4. 조세푸스 문제 (문제 ID: JOSEPHUS)

[code 18-2](../hyemin/18_LinearDataStructure/Josephus.cpp)

```C++
void josephus(int n, int k)
{
    // 리스트를 준비한다
    list<int> survivors;
    for (int i = 1; i <= n; i++)
        survivors.push_back(i);

    // 이번에 죽을 사람을 나타내는 포인터
    list<int>::iterator kill = survivors.begin();
    while (n > 2)
    {
        // 첫 번째 사람이 자살한다 -> kill이 가리키는 원소를 지우고 다음 원소를 반환하여 kill이 가리키게
        kill = survivors.erase(kill);
        // kill이 리스트에 끝에 도달하면 처음으로 옮겨준다
        if (kill == survivors.end())
            // end는 back과 달리 맨 뒤의 원소가 아니라 맨 뒤의 다음 원소 반환
            kill = survivors.begin();
        --n;

        // kill을 k-1 번 다음 사람으로 옮긴다
        // 이미 자살한 다음을 가리키고 있기 때문에 k-1
        for (int i = 0; i < (k - 1) % n; i++)
        {
            ++kill;
            if (kill == survivors.end())
                kill = survivors.begin();
        }
    }

    // 오름차순 출력을 위해 정렬한다
    survivors.sort();
    cout << survivors.front() << " " << survivors.back() << endl;
}
```

