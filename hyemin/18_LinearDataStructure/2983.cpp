#include <map>
#include <set>
#include <tuple>
#include <iostream>

using namespace std;

typedef tuple<int, int, int> ti3;
typedef pair<int, pair<int, int>> p;

set<ti3> splus;
set<ti3> sminus;

char dir[100010];
int n, m;
int xpos;
int ypos;
int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s", dir);
    for (int i = 0; i < n; i++)
    {
        //cout << i << endl;
        int x, y;
        scanf("%d%d", &x, &y);
        if (i == 0)
        {
            xpos = x;
            ypos = y;
        }
        splus.insert({x + y, x, y});
        sminus.insert({x - y, x, y});
    }

    //set<ti3>::iterator iter;

    for (int i = 0; dir[i] != 0; i++)
    {
        int nowx = xpos;
        int nowy = ypos;
        if (dir[i] == 'A')
        {
            auto iter = sminus.find({nowx - nowy, nowx, nowy});
            if (iter == prev(sminus.end()))
            {
                continue;
            }
            int minus, nextx, nexty;
            tie(minus, nextx, nexty) = *next(iter);
            if (minus != nowx - nowy)
            {
                continue;
            }
            sminus.erase(iter);
            splus.erase({nowx + nowy, nowx, nowy});
            xpos = nextx;
            ypos = nexty;
        }

        else if (dir[i] == 'B')
        {
            auto iter = splus.find({nowx + nowy, nowx, nowy});
            if (iter == prev(splus.end()))
            {
                continue;
            }
            int plus, nextx, nexty;
            tie(plus, nextx, nexty) = *next(iter);
            if (plus != nowx + nowy)
            {
                continue;
            }
            sminus.erase({nowx - nowy, nowx, nowy});
            splus.erase({nowx + nowy, nowx, nowy});
            xpos = nextx;
            ypos = nexty;
        }

        else if (dir[i] == 'C')
        {
            auto iter = splus.find({nowx + nowy, nowx, nowy});
            if (iter == splus.begin())
            {
                continue;
            }
            int plus, nextx, nexty;
            tie(plus, nextx, nexty) = *prev(iter);
            if (plus != nowx + nowy)
            {
                continue;
            }
            sminus.erase({nowx - nowy, nowx, nowy});
            splus.erase({nowx + nowy, nowx, nowy});
            xpos = nextx;
            ypos = nexty;
        }
        else if (dir[i] == 'D')
        {
            auto iter = sminus.find({nowx - nowy, nowx, nowy});
            if (iter == sminus.begin())
            {
                continue;
            }
            int minus, nextx, nexty;
            tie(minus, nextx, nexty) = *prev(iter);
            if (minus != nowx - nowy)
            {
                continue;
            }
            sminus.erase({nowx - nowy, nowx, nowy});
            splus.erase({nowx + nowy, nowx, nowy});
            xpos = nextx;
            ypos = nexty;
        }
    }
    printf("%d %d", xpos, ypos);
}