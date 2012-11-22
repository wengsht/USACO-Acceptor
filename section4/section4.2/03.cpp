
/*
ID: wengsht1
LANG: C++
TASK: stall4
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

#define MX 40500
int N, M, K;

int V[MX], nxt[MX], head[MX];
int m;

void add(int u, int v)
{
    nxt[m] = head[u];
    V[m] = v;
    head[u] = m++;
}

int x[MX], y[MX];
bool y_acc[MX];

int find_path(int u)
{
    for(int i = head[u];i != -1; i = nxt[i])
    {
        if(y_acc[V[i]]) continue;
        y_acc[V[i]] = true;

        if(y[V[i]] == 0 || (find_path(y[V[i]])))
        {
            y[V[i]] = u;
            x[u] = V[i];
            return V[i];
        }
    }
    return 0;
}
int go()
{
    int ret = 0;
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));

    for(int i = 1;i <= N;i++)
    {
        memset(y_acc, false, sizeof(y_acc));
        if(0 != (find_path(i)))
            ret++;
    }

    return ret;
}

int main()
{
#ifdef HOME
    freopen("stall4.in", "r", stdin);
    freopen("stall4.out", "w", stdout);
#endif
    cin>>N>>M;
    memset(head, -1, sizeof(head));

    int a;
    for(int i = 1;i <= N;i++)
    {
        cin>>K;
        for(int j = 0;j < K;j++)
        {
            cin>>a;

            add(i, a);
        }
    }
    int ret = go();

    cout<<ret<<endl;

    return 0;
}

