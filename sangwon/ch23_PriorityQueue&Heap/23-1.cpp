// 23.1 정수 원소를 갖는 최대 힙에 새 원소 삽입하기

// 정수를 담는 최대 힙 heap 에 새 원소 newValue 를 삽입한다.
void push_heap(vector<int>& heap, int newValue) {
    // 힙의 맨 끝에 newValue 를 삽입한다.
    heap.push_back(newValue)
    // 현재 newValue 의 위치
    int idx = heap.size() - 1;
    // 루트에 도달하거나 enwValue  이상의 원소를 가진 조상을 만날 때까지
    while(idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
        swap(heap[idx], heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}