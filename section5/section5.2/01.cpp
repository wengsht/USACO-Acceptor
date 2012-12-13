
/*
ID: wengsht1
LANG: C++
TASK: snail
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

#define MX 100000
int N, M, K;

int ret;

int Board[121][121];

int nxt[2][4] = {{1, 2, 3, 0}, {3, 0, 1, 2}};

int rev[4] = {2, 3, 0, 1};
int _x[] = {0, 1, 0, -1};
int _y[] = {1, 0, -1, 0};


inline bool good(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}
int go(int d, int stx, int sty)
{
    if(Board[stx][sty])
        return 0;
    int tmp = 1;

    Board[stx][sty] = 2;

    int nxtx , nxty;
    int tmpx = stx, tmpy = sty;
    while(true)
    {
        nxtx = stx + _x[d];
        nxty = sty + _y[d];

        if(!good(nxtx, nxty) || Board[nxtx][nxty] == 1)
        {
            int rr = 0;
            for(int i = 0;i < 2;i++)
            {
                int nxtd = nxt[i][d];
                nxtx = stx + _x[nxtd];
                nxty = sty + _y[nxtd];

                if(good(nxtx, nxty) && Board[nxtx][nxty] == 0)
                {
                    rr = max(rr, go(nxtd, nxtx, nxty));
                }
            }
            tmp += rr;

            break;
        }
        else if(Board[nxtx][nxty] == 0)
        {
            Board[nxtx][nxty] = 2;
            tmp ++;

            stx = nxtx;
            sty = nxty;
        }
        else
        {
            break;
        }
    }
    int dd = rev[d];
    while(!(stx == tmpx && sty == tmpy))
    {
        Board[stx][sty] = 0;
        stx += _x[dd];
        sty += _y[dd];
    }
    Board[stx][sty] = 0;

    return tmp;
}
int main()
{
#ifdef HOME
    freopen("snail.in", "r", stdin);
    freopen("snail.out", "w", stdout);
#endif
    cin>>N>>M;

    char c;
    int r, x;
    for(int i = 0;i < M;i++)
    {
        cin>>c>>r;

        x = c - 'A';
        r --;

        Board[r][x] =  1;
    }

    ret = go(0, 0, 0);
    ret = (max(ret, go(1, 0, 0)));

    cout<<ret<<endl;

    return 0;
}

