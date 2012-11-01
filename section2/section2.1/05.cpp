
/*
ID: wengsht1
LANG: C++
TASK: holstein
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

int need[1001];
int scoop[16][1001];

struct Ret
{
    int feed[15];
    int m;
}ret, tmp;

void dfs(int h)
{
    int ok = true;
    for(int i = 0;i < N;i++)
    {
        need[i] -= scoop[h][i];

        if(need[i] > 0) ok = false;
    }
    tmp.feed[tmp.m++] = h;
    if(ok && ret.m > tmp.m)
    {
        ret.m = tmp.m;
        for(int j = 0;j < tmp.m;j++) ret.feed[j] = tmp.feed[j];
    }
    else if(h+1 < M) dfs(h+1);
    for(int i = 0;i < N;i++)
        need[i] += scoop[h][i];
    tmp.m--;

    if(h+1 < M) dfs(h+1);
}
int main()
{
#ifdef HOME
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
#endif
    ret.m = 9999;
    scanf("%d", &N);
    for(int i = 0;i < N;i++) scanf("%d", need+i);

    scanf("%d", &M);
    for(int i = 0;i < M;i++)
    {
        for(int j = 0;j < N;j++)
            scanf("%d", &scoop[i][j]);
    }
    dfs(0);

    cout<<ret.m;
    for(int i = 0;i < ret.m;i++) cout<<" "<<ret.feed[i]+1; cout<<endl;

    return 0;
}

