#include <string>

string reverse(string::iterator& it) {
    char head = *it;
    ++it;
    if(head == 'b' || head == 'w') return string(1, head);
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string upperLeft = reverse(it);
    string upperRight = reverse(it);

    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}