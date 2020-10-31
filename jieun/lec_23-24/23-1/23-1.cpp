#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void push_heap(vector<int>& heap, int newValue) {
  heap.push_back(newValue);
  // newValue의 index
  int idx = heap.size()-1;
  while(idx > 0 && heap[(idx-1)/2] < heap[idx]) {
    swap(heap[idx], heap[(idx-1)/2]);
    idx = (idx-1)/2;
  }
}
