
/*
ID: wengsht1
LANG: C++
TASK: race3
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

#define MX 205
int N, M, K;
int a;

int head[MX], nxt[MX], V[MX];
int m;

void add(int u, int v)
{
    V[m] = v;
    nxt[m] = head[u];
    head[u] = m++;
}
int ret1[MX], ret2[MX];
int m1, m2;


int color[MX];
bool dfs(int now, int pre)
{
    for(int i = head[now]; i != -1;i = nxt[i])
    {
        if(color[V[i]])
            continue;

        if(V[i] == N-1)
            return true;

        color[V[i]] = 1;
        if(dfs(V[i], now))
            return true;
    }
    return false;
}
bool test(int p)
{
    memset(color, 0, sizeof(color));
    color[0] = 1;
    color[p] = true;
    return !dfs(0, -1);
}
bool test2(int p)
{
    memset(color, 0, sizeof(color));

    queue<int> q;
    color[0] = 1;
    color[p] = 1;

    q.push(0);

    while(!q.empty())
    {
        int top = q.front();
        q.pop();

        for(int i = head[top]; i != -1;i = nxt[i])
        {
            if(color[V[i]])
                continue;

            color[V[i]] = 1;

            q.push(V[i]);
        }
    }

    bool ok = true;

    for(int i = head[p];i != -1;i = nxt[i])
    {
        if(V[i] != p && color[V[i]]) 
            ok = false;
    }
    for(int i = 0;i < N && ok;i++)
    {
        if(p == i)
            continue;
        for(int j = head[i];j != -1;j = nxt[j])
        {
            if(V[j] == p) 
                continue;
            if(color[i] != color[V[j]])
            {
                ok = false;
                break;
            }

        }

    }
    return ok;
}

int main()
{
#ifdef HOME
    freopen("race3.in", "r", stdin);
    freopen("race3.out", "w", stdout);
#endif
    memset(head, -1, sizeof(head));
    while(scanf("%d", &a) && a != -1)
    {

        while(a != -2)
        {
            add(N, a);
            scanf("%d", &a);
        }
        N++;
    }

    for(int i = 1;i < N-1;i++)
    {
        if(test(i))
        {
            ret1[m1++] = i;

            if(test2(i))
                ret2[m2++] = i;
        }
    }
    printf("%d", m1);
    for(int i = 0;i < m1;i++)
        printf(" %d", ret1[i]);
    printf("\n");
    printf("%d", m2);
    for(int i = 0;i < m2;i++)
        printf(" %d", ret2[i]);
    printf("\n");

    return 0;
}

