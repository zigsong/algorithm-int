#include <iostream>
#include <string>
// #include <map>
#include <set>
#include <list>

using namespace std;

// 식물 수 n, 점프 수 k
// 방향 K개 (A, B, C, D 중)

// n=7, k=5, ACDBB

typedef tuple<int, int, int> ti3;
typedef pair<int, pair<int, int>> p;

set<ti3> splus;
set<ti3> sminus;

char dirs[100001];
int n, k;
int xpos, ypos;

int main() {  
  cin >> n >> k;
  cin >> dirs;

  for (int i=0; i<n; i++) {
    int x, y;
    cin >> x >> y;
    if (i == 0) {
      xpos = x;
      ypos = y;
    }
    splus.insert({ x+y, x, y });
    sminus.insert({ x-y, x, y });
  } 

  for (int i=0; i<dirs[i] != 0; i++) {
    int currX = xpos;
    int currY = ypos;
  
    if (dirs[i] == 'A') {
      auto iter = sminus.find({ currX-currY, currX, currY });
      if (iter == prev(sminus.end())) {
        continue;
      }
      int minus, nextX, nextY;
      tie(minus, nextX, nextY) = *next(iter);
      if (minus != currX-currY) {
        continue;
      }
      sminus.erase(iter);
      splus.erase({ currX + currY, currX, currY });
      xpos = nextX;
      ypos = nextY;
    } else if (dirs[i] == 'B') {
      auto iter = splus.find({ currX+currY, currX, currY });
      if (iter == prev(splus.end())) {
        continue;
      }
      int plus, nextX, nextY;
      tie(plus, nextX, nextY) = *next(iter);
      if (plus != currX+currY) {
        continue;
      }
      sminus.erase({ currX-currY, currX, currY });
      splus.erase({ currX+currY, currX, currY });
      xpos = nextX;
      ypos = nextY;
    } else if (dirs[i] == 'C') {
      auto iter = splus.find({ currX+currY, currX, currY });
      if (iter == splus.begin()) {
        continue;
      }
      int plus, nextX, nextY;
      tie(plus, nextX, nextY) = *prev(iter);
      if (plus != currX+currY) {
        continue;
      }
      sminus.erase({ currX-currY, currX, currY });
      splus.erase({ currX+currY, currX, currY });
      xpos = nextX;
      ypos = nextY;
    } else if (dirs[i] == 'D') {
      auto iter = sminus.find({ currX-currY, currX, currY });
      if (iter == sminus.begin()) {
        continue;
      }
      int minus, nextX, nextY;
      tie(minus, nextX, nextY) = *prev(iter);
      if (minus != currX-currY) {
        continue;
      }
      sminus.erase({ currX-currY, currX, currY });
      splus.erase({ currX+currY, currX, currY });
      xpos = nextX;
      ypos = nextY;
    }
  }
  cout << xpos << " " << ypos << endl;
}