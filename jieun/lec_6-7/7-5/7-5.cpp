#include <iostream>

using namespace std;

char decompressed[16][16]; // 16 * 16 칸을 b, w로 칠함
void decompress(string::iterator& it, int y, int x, int size) {
  char head = *(it++); // it를 1씩 뒤로 이동시키며 it가 가리키는 원소(객체) 값 반환
  if (head == 'b' || head == 'w') {
    for (int dy=0; dy<size; dy++) {
      for (int dx=0; dx<size; dx++) {
        decompressed[y+dy][x+dx] = head;
      }
    }
  } else {
    int half = size/2;
    decompress(it, y, x, half); // 1사분면의 첫 번째 점
    decompress(it, y, x+half, half); // 2사분면의 첫 번째 점
    decompress(it, y+half, x, half); // 3사분면의 첫 번째 점
    decompress(it, y+half, x+half, half); // 4사분면의 첫 번째 점
  }
}