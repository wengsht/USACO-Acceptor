
/*
ID: wengsht1
LANG: C++
TASK: fence6
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

#define MX 10000
int N, M, K;

int v[2][MX], nxt[2][MX], head[2][MX];
int m[2];

int len[101];

int ret = 100000000;

void add(int p, int u, int v1)
{
    v[p][m[p]] = v1;
    nxt[p][m[p]] = head[p][u];
    head[p][u] = m[p]++;
}
bool had[101];

void go(int st, int pre, int now, int l)
{
    int se = 0;
    for(int i = head[0][now]; i != -1;i = nxt[0][i])
    {
        if(v[0][i] == pre)
        {
            se = 1;
            break;
        }
    }
    for(int i = head[se][now]; i != -1; i = nxt[se][i])
    {
        int nxt_v = v[se][i];
        int new_l = l + len[nxt_v];
        if(st == nxt_v)
        {
            if(ret > l) ret = l;

            continue;
        }
        if(had[nxt_v]) continue;
        if(new_l >= ret) continue;

        bool tmp = had[nxt_v];
        had[nxt_v] = true;
        go(st, now, nxt_v, new_l);
        had[nxt_v] = tmp;
    }
}

int main()
{
#ifdef HOME
    freopen("fence6.in", "r", stdin);
    freopen("fence6.out", "w", stdout);
#endif
    memset(head, -1, sizeof(head));
    int u, n1, n2, v;
    scanf("%d", &N);
    for(int i = 0;i < N;i++)
    {
        scanf("%d", &u);
        scanf("%d %d %d", len+u, &n1, &n2);
        for(int i = 0;i < n1;i++)
        {
            scanf("%d", &v);
            add(0, u, v);
        }
        for(int i = 0;i < n2;i++)
        {
            scanf("%d", &v);
            add(1, u, v);
        }
    }


    for(int i = 1;i <= N;i++)
    {
        had[i] = true;

        go(i, -1, i, len[i]);
    }

    cout<<ret<<endl;

    return 0;
}

