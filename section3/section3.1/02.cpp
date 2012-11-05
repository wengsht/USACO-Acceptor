
/*
ID: wengsht1
LANG: C++
TASK: agrinet
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

struct Edge
{
    int v, u, d;
}edge[10001];
int m, p;

int N, M, K;
int father[101];

bool _cmp(Edge a, Edge b)
{
    return a.d < b.d;
}
int find_father(int p)
{
    return (father[p] == p ? p : (father[p] = find_father(father[p])));
}
int main()
{
#ifdef HOME
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);
#endif
    scanf("%d", &N);

    for(int i = 0;i < N;i++) father[i] = i;
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N;j++)
        {
            scanf("%d", &p);

            if(i < j) 
            {
                edge[m].v = i;
                edge[m].u = j;
                edge[m++].d = p;

            }
        }
    }
    sort(edge, edge+m, _cmp);

    int ret = 0;
    int cnt = 0;

    int c = 0;
    while(cnt < N-1)
    {
        int fv = find_father(edge[c].v);
        int fu = find_father(edge[c++].u);

        if(fv == fu) continue;

        father[fv] = fu;

        cnt++;
        ret += edge[c-1].d;
    }
    cout<<ret<<endl;

    return 0;
}

