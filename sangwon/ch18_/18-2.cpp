// 18.2 연결 리스트를 이용한 조세푸스 문제의 구현 

void josephus(int n, int k) {
    // 리스트를 준비한다.
    list<int> survivors;
    for(int i; i <= n; ++i) survivors.push_back(i);
    // 이번에 죽을 사람을 나타내는 포인터
    list<int>::iterator kill = survivors.begin();
    while(n > 2) {
        // 첫 번째 사람이 자살한다. erase()는 지운 원소의 다음 원소를 반환한다.
        kill = survivors.erase(kill);
        if(kill == survivors.end()) kill = survivors.begin();
        --n;
        // k-1번 다음 사람으로 옮긴다.
        for(int i = 0; i < k-1; ++i) {
            ++kill;
            if(kill == survivors.end()) kill = survivors.begin()
        }
    }
    cout << survivors.front() << " " << survivors.back() << endl;
}