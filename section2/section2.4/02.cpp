
/*
ID: wengsht1
LANG: C++
TASK: ttwo
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define HOME 

int ch[] = {1, 2, 3, 0};
int _x[] = {-1, 0, 1, 0};
int _y[] = {0, 1, 0, -1};

#define MX 100000
int N, M, K;
char str[100];
int ret = 0;

bool board[11][11];
bool go[11][11][11][11][4][4];
int stx, sty, edx, edy, stop = 0, edop = 0;

inline bool good(int x, int y)
{
    return (x >= 0 && x < 10 && y >= 0 && y < 10);
}
bool generator(int &x, int &y, int &op)
{
    bool ok = false;
    int xnxt, ynxt;
    xnxt = x + _x[op];
    ynxt = y + _y[op];

    if(good(xnxt, ynxt) && board[xnxt][ynxt])
    {
        ok = true;
        x = xnxt;
        y = ynxt;
    }
    else op = ch[op];

    return true;
}
bool work()
{
    ret++;
    if(!generator(stx, sty, stop)) return false;
    if(!generator(edx, edy, edop)) return false;

    if(go[stx][sty][edx][edy][stop][edop]) return false;

    go[stx][sty][edx][edy][stop][edop] = true;

    return true;
}
int main()
{
#ifdef HOME
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);
#endif

    for(int i = 0;i < 10;i++)
    {
        scanf("%s", str);

        for(int j = 0;j < 10;j++)
        {
            if(str[j] == '*') board[i][j] = false;
            else
            {
                board[i][j] = true;
                if(str[j] == 'F')
                {
                    stx = i;
                    sty = j;
                }
                else if(str[j] == 'C')
                {
                    edx = i;
                    edy = j;
                }
            }
        }
    }
    bool found = false;
    go[stx][sty][edx][edy][stop][edop] = true;

    while(!found)
    {
        if(!work()) break;

        if(stx == edx && sty == edy) 
        {
            found = true;
            break;
        }
    }
    if(found) cout<<ret<<endl;
    else cout<<0<<endl;
    return 0;
}

