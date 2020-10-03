# Lecture 8: 동적 계획법

by | 상원

pub date | 2020.10.02.Fri

### 동적 계획법(Dynamic Programming)이란

핵심은, 한번 계산한 것은 다시 계산하지 않겠다!

연산 오버헤드를 줄이는 대신에 메모리 오버헤드 발생?

메모리 최적화 8.9



메모이제이션

참조적 투명성 - 메모이제이션 적용 가능 



1. 기저사례 먼저 처리
2. cache 를 -1 로 초기화
3. ret 을 참조형 reference by value?
4. memset() 으로 초기화, but 제한적인 경우에만 사용 가능 (추가 설명 참고)



시간 복잡도는 최악의 경우 O(n^2)



#### 이항계수의 계산

8.1 재귀 호출을 이용한 이항 계수의 계산

[code 8-1](../sangwon/ch8_DynamicProgramming/8-1.cpp)

8.2 메모이제이션을 이용한 이항계수의 계산

[code 8-2](../sangwon/ch8_DynamicProgramming/8-2.cpp)

8.3 메모이제이션의 사용 예

[code 8-3](../sangwon/ch8_DynamicProgramming/8-3.cpp)



#### 외발뛰기(ID: JUMPGAME)

8.4 외발 뛰기 문제를 해결하는 재귀 호출 알고리즘

[code 8-4](../sangwon/ch8_DynamicProgramming/8-4.cpp)

8.5 외발 뛰기 문제를 해결하는 동적 계획법 알고리즘

[code 8-5](../sangwon/ch8_DynamicProgramming/8-5.cpp)

```c++
int main() {
    return a = function();
    // 이러면 1초 지난 후에야 return 이 일어나지 않나?
}
int function() {
    Sleep(1000);
    return 100;
}
```



#### 와일드카드(ID: WILDCARD)

8.6 와일드카드 문제를 해결하는 완전탐색 알고리즘

[code 8-6](../sangwon/ch8_DynamicProgramming/8-6.cpp)

8.7 와일드카드 문제를 해결하는 동적 계획법 알고리즘

왜 메모이제이션을 쓰는지에 대한 이해가 조금 더 필요

[code 8-7](../sangwon/ch8_DynamicProgramming/8-7.cpp)



#### 삼각형 위의 최대 경로(ID: TRIANGLEPATH)

8.8 삼각형 위의 최대 경로 문제를 푸는 메모이제이션 코드 (1)

[code 8-8](../sangwon/ch8_DynamicProgramming/8-8.cpp)

8.9 삼각형 위의 최대 경로 문제를 푸는 동적 계획법 알고리즘 (2)

[code 8-9](../sangwon/ch8_DynamicProgramming/8-9.cpp)

최적 부분 구조가 성립하는지를 알아야한다.

더 작은 문제의 최적해만으로 전체 문제의 최적해를 구할 수 없다면 성립 X

직관적이지 않은 경우 귀류법이나 대우로 증명

#### 최대 증가 부분 수열(ID: LIS)

8.10 최대 증가 부분 수열 문제를 해결하는 완전 탐색 알고리즘

[code 8-10](../sangwon/ch8_DynamicProgramming/8-10.cpp)

8.11 최대 증가 부분 수열 문제를 해결하는 동적 계획법 알고리즘 (1)

[code 8-11](../sangwon/ch8_DynamicProgramming/8-11.cpp)

8.12 최대 증가 부분 수열 문제를 해결하는 동적 계획법 알고리즘 (2)

[code 8-12](../sangwon/ch8_DynamicProgramming/8-12.cpp)

[code 8-13](../sangwon/ch8_DynamicProgramming/8-13.cpp)

[code 8-14](../sangwon/ch8_DynamicProgramming/8-14.cpp)

[code 8-15](../sangwon/ch8_DynamicProgramming/8-15.cpp)

[code 8-16](../sangwon/ch8_DynamicProgramming/8-16.cpp)

[code 8-17](../sangwon/ch8_DynamicProgramming/8-17.cpp)

[code 8-18](../sangwon/ch8_DynamicProgramming/8-18.cpp)

[code 8-19](../sangwon/ch8_DynamicProgramming/8-19.cpp)

[code 8-20](../sangwon/ch8_DynamicProgramming/8-20.cpp)

스캐폴딩으로 테스트하기(bruteforce 로 계산한 것과 동적 계획법으로 계산한 것을 비교할 수 있다)

[code 8-21](../sangwon/ch8_DynamicProgramming/8-21.cpp)

[code 8-22](../sangwon/ch8_DynamicProgramming/8-22.cpp)

[code 8-23](../sangwon/ch8_DynamicProgramming/8-23.cpp)

[code 8-24](../sangwon/ch8_DynamicProgramming/8-24.cpp)