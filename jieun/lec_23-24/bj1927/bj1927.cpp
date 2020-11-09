#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n;

int main() {
  priority_queue< int, vector<int>, greater<int> > minHeap;
  scanf("%d", &n); 
  for (int i=0; i<n; i++) {
    int x;
    scanf("%d", &x);

    if (x == 0) {
      if (!minHeap.empty()) {
        printf("%d\n", minHeap.top());
        minHeap.pop();
      } else {
        printf("%d\n", 0);
      }
    } else {
      minHeap.push(x);
    }
  }
}