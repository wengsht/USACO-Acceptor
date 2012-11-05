
/*
ID: wengsht1
LANG: C++
TASK: inflate
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

struct Node
{
    int p, t;
}node[10001];
int m;

int mx[10001];
int dp[2][10001];

int a, b;

int main()
{
#ifdef HOME
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);
#endif
    scanf("%d %d", &M, &N);
    for(int i = 0;i < N;i++)
    {
        scanf("%d %d", &a, &b);
        if(mx[b] < a) mx[b] = a;
    }
    int premx = 0;
    for(int i = 1;i <= M;i++)
    {
        if(premx < mx[i])
        {
            node[m].p = mx[i];
            node[m++].t = i;
        }
        premx = mx[i];
    }
    int now = 1, rep, tmp;
    for(int i = 0;i < m;i++)
    {
        now ^= 1;

        rep = (now ^ 1);

        for(int l = M;l > 0;l--)
        {
            int j = l-node[i].t;
            int s = node[i].p;
            for(;j >= 0;j-=node[i].t, s += node[i].p)
            {
                if(j >= 0) tmp = dp[rep][j] + s;
                if(dp[now][l] < tmp) dp[now][l] = tmp;
            }
        }

        memcpy(dp[rep], dp[now], sizeof(dp[now]));
    }
    int ret = 0;
    for(int i = 1;i <= M;i++)
        ret = max(ret, dp[now][i]);

    cout<<ret<<endl;
    return 0;
}

