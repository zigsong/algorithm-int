#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

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

int main()
{
    int cases;
    cin >> cases;
    for (int cc = 0; cc < cases; ++cc)
    {
        int n, k;
        cin >> n >> k;
        josephus(n, k);
        josephusQueue(n, k);
    }
}
