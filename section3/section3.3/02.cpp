
/*
ID: wengsht1
LANG: C++
TASK: fence
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

int connect[501][501];
int  nxtmn[501];
int  ret[5002];
int  cnt[502];
int m;

void dfs(int st)
{
    if(nxtmn[st] > 500)
    {
        ret[m++] = st;

        return ;
    }
    int nxt = nxtmn[st];
    connect[st][nxt] --; 
    connect[nxt][st] --;

    int findnxt = nxt;
    while(findnxt <= 500 && !connect[st][findnxt]) findnxt++;
    nxtmn[st] = findnxt;

    if(st == nxtmn[nxt])
    {
        findnxt = st;
        while(findnxt <= 500 && !connect[nxt][findnxt]) findnxt++;
        nxtmn[nxt] = findnxt;
    }

    dfs(nxt);

    if(nxtmn[st] > 500) ret[m++] = st;
    else dfs(st);
}
int main()
{
#ifdef HOME
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
#endif
    scanf("%d", &N);

    int st = 501, sta = 501;
    for(int i = 1;i <= 500;i++) nxtmn[i] = 501;

    for(int i = 0;i < N;i++)
    {
        scanf("%d %d", &M, &K);

        connect[M][K] ++; connect[K][M] ++ ;

        cnt[M] ++;
        cnt[K] ++;
        if(sta > M) sta = M;
        if(sta > K) sta = K;
        if(nxtmn[M] > K) nxtmn[M] = K;
        if(nxtmn[K] > M) nxtmn[K] = M;
    }
    for(int i = 1; i <= 500;i++)
    {
        if(cnt[i] > 0 && cnt[i] % 2)
        {
            st = i;
            break;
        }
    }
    if(st > 500) st = sta;

    dfs(st);

    for(int i = m-1;i >= 0;i--)
        cout<<ret[i]<<endl;

    return 0;
}

