// 로직만 쳐보면서 공부!
#include <string>
#include <vector>

using namespace std;

int n = 10;
bool areFriends[10][10];

// taken : 짝 찾았으면 true

int countPairings(bool taken[10])
{
    int firstFree = -1;
    for (int i = 0; i < n; i++)
    {
        if (!taken[i])
        {
            firstFree = i;
            break;
        }
    }

    if (firstFree == -1)
        return 1;
    int ret = 0;

    for (int pairWith = firstFree + 1; pairWith < n; ++pairWith)
    {
        if (!taken[pairWith] && areFriends[firstFree][pairWith])
        {
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}