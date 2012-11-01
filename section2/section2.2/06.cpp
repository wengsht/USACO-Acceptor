
/*
ID: wengsht1
LANG: C++
TASK: lamps
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
int N, C, K;

int on[101], off[101];
int mon, moff;

struct Ret
{
    int state[101];
    int cnt;
}ret[16];

bool _cmp(Ret a, Ret b)
{
    for(int i = 0;i < N;i++)
    {
        if(a.state[i] != b.state[i])
            return a.state[i] < b.state[i];
    }
    return false;
}
bool same(Ret a, Ret b)
{
    for(int i = 0;i < N;i++)
    {
        if(a.state[i] != b.state[i])
            return false;
    }
    return true;
}
int mask[] = {1, 2, 4, 8};

void init(Ret rt)
{
    memset(rt.state, 0, sizeof(rt.state));
}
int main()
{
#ifdef HOME
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
#endif
    scanf("%d %d", &N, &C);

    for(int i = 0;i < 16;i++)
    {
        for(int j = 0;j < N;j++)
            ret[i].state[j] = 1;
    }
    while(scanf("%d", &K) && K > 0)
        on[mon++] = K;
    while(scanf("%d", &K) && K > 0)
        off[moff++] = K;

    for(int i = 0;i < 16;i++)
    {
        int cnt = 0;
        if(1 & i)
        {
            for(int j = 0;j < N;j++) ret[i].state[j] ^= 1;

            cnt++;
        }
        if(2 & i)
        {
            for(int j = 1;j < N;j+=2) ret[i].state[j] ^= 1;

            cnt++;
        }
        if(4 & i)
        {
            for(int j = 0;j < N;j+=2) ret[i].state[j] ^= 1;

            cnt++;
        }
        if(8 & i)
        {
            for(int j = 0;j < N;j+=3) ret[i].state[j] ^= 1;

            cnt++;
        }

        ret[i].cnt = cnt;
        if((C - cnt) % 2 == 1) ret[i].cnt = 10000001;

        for(int j = 0;j < mon;j++) if(ret[i].state[on[j]-1] == 0) ret[i].cnt = 10000001;
        for(int j = 0;j < moff;j++) if(ret[i].state[off[j]-1]) ret[i].cnt = 10000001;
    }
    sort(ret, ret+16, _cmp);

    bool ok = false;
    for(int i = 0;i < 16;i++)
    {
        for(int j = i+1;j < 16;j++)
        {
            if(same(ret[i], ret[j]))
            {
                ret[i].cnt = min(ret[i].cnt, ret[j].cnt);

                ret[j].cnt = 1000001;
            }
        }
    }
    for(int i = 0;i < 16;i++)
    {
        if(ret[i].cnt <= C)
        {
            ok = true;

            for(int j = 0;j < N;j++) printf("%d", ret[i].state[j]);
            printf("\n");
        }
    }
    if(!ok)
        printf("IMPOSSIBLE\n");

    return 0;
}

