/*
ID: wengsht1
LANG: C++
TASK: spin
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

struct Wheel
{
    int speed; 
    int w;
    int l[5], r[5];
}wheel[5];

bool test()
{
    int had[360];
    memset(had, 0, sizeof(had));

    for(int i = 0;i < 5;i++)
    {
        for(int j = 0;j < wheel[i].w;j++)
        {
            int l = wheel[i].l[j];
            for(int k = 0;k <= wheel[i].r[j];k++)
                had[(l+k)%360] ++;
        }
    }
    for(int i = 0;i < 360;i++) 
    {
        if(had[i] >= 5)
            return true;
    }

    return false;
}

void go()
{
    for(int i = 0;i < 5;i++)
    {
        for(int j = 0;j < wheel[i].w;j++)
        {
            wheel[i].l[j] += wheel[i].speed;
            wheel[i].l[j] %= 360;
        }
    }
}
int main()
{
#ifdef HOME
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);
#endif
    for(int i = 0;i < 5;i++)
    {
        scanf("%d %d", &wheel[i].speed, &wheel[i].w);

        for(int j = 0;j < wheel[i].w;j++)
            scanf("%d %d", &wheel[i].l[j], &wheel[i].r[j]);
    }

    for(ret = 0;ret <= 359;ret++)
    {
        if(test()) break;

        go();
    }

    if(ret < 360) cout<<ret<<endl;
    else cout<<"none"<<endl;
    return 0;
}

