#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void pop_heap(vector<int>& heap) {
  heap[0] = heap.back();
  heap.pop_back();
  int here = 0;
  while(true) {
    int left = here * 2 + 1, right = here * 2 + 2;
    int next = here;
    if (left < heap.size() && heap[next] < heap[left]) next = left;
    if (right < heap.size() && heap[next] < heap[right]) next = right;
    if (next == here) break;
    swap(heap[here], heap[next]);
    here = next;
  }
}