
/*
ID: wengsht1
LANG: C++
TASK: rect1
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
int ll;

struct Rect
{
    int x1, y1, x2, y2, color;
}rect[1001];

int ret[2501];
int gone = 0;

int go(int p, int x1, int y1, int x2, int y2)
{
    if(x1 >= x2 || y1 >= y2) return 0;
    if(p == K) 
    {
        return (y2-y1) * (x2-x1);
    }

    int ret = 0;
    if(x1 < rect[p].x1)
    {
        ret += go(p+1, x1, y1, min(x2, rect[p].x1), y2);

        if(rect[p].x1 < x2)
        {
            ret += go(p, rect[p].x1, y1, x2, y2);
        }
    }
    else if(x1 < rect[p].x2)
    {
        if(y1 < rect[p].y1)
        {
            ret += go(p+1, x1, y1, x2, min(y2, rect[p].y1));

            if(y2 > rect[p].y1) ret += go(p, x1, rect[p].y1, x2, y2);
        }
        else if(y1 < rect[p].y2)
        {
            if(x2 <=  rect[p].x2 && y2 <= rect[p].y2) ret += 0;
            else if(x2 > rect[p].x2 && y2 > rect[p].y2)
            {
                ret += go(p+1, rect[p].x2, y1, x2, y2);
                ret += go(p+1, x1, rect[p].y2, rect[p].x2, y2);
            }
            else if(x2 > rect[p].x2)
            {
                ret += go(p+1, rect[p].x2, y1, x2, y2);
            }
            else if(y2 > rect[p].y2) ret += go(p+1, x1, rect[p].y2, x2, y2);
        }
        else ret += go(p+1, x1, y1, x2, y2);
    }
    else ret += go(p+1, x1, y1, x2, y2);

    return ret;
}
int main()
{
#ifdef HOME
    freopen("rect1.in", "r", stdin);
    freopen("rect1.out", "w", stdout);
#endif
    scanf("%d %d %d", &M, &N, &K);

    for(int i = 0;i < K;i++)
    {
        scanf("%d %d %d %d %d", &rect[i].y1, &rect[i].x1, &rect[i].y2, &rect[i].x2, &rect[i].color);
    }
    for(int i = K-1;i >= 0;i--)
    {
        ll = i;
        int tmp =  go(i+1, rect[i].x1, rect[i].y1, rect[i].x2, rect[i].y2);
        ret[rect[i].color] += tmp;
    }

    for(int i = 1;i <= 2500;i++) gone += ret[i];

    ret[1] += (M * N) - gone;
    for(int i = 1;i <= 2500;i++)
        if(ret[i])
            cout<<i<<" "<<ret[i]<<endl;
    return 0;
}

