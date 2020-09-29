char decompressed[MAX_SIZE][MAX_SIZE];

void decompress(string::iterator& it, int y, int x, int size) {
    char head = *(it++);

    if (head == 'b' || head == 'w') {
        for (int dy = 0; dy < size; ++dy) {
            for (int dx = 0; dx < size; ++dx) {
                decompressed[y+dy][x+dx] = head;
            }
        }
    }
    else {
        int half = size/2;
        decompress(it, y, x, half);
        decompress(it, y, x+half, half);
        decompress(it, y+half, x, half);
        decompress(it, y+half, x+half, half);
    }
}