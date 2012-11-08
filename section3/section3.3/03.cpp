
/*
ID: wengsht1
LANG: C++
TASK: shopping
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

int mp[1001];
int dp[10001];

int mask[] = {1, 6, 36, 216, 1296};

inline int key(int s[], int m)
{
    int ret = 0;
    for(int i = 0;i < m;i++)
    {
        if(s[i] < 0) return -1;
        ret += s[i] * mask[i];
    }

    return ret;
}
struct Offer
{
    int c[5], k[5];
    int p;
    int keymp[5];
    int m;
}offer[100];

int p[5];
int k[5];

int dfss[5];
int tmp[5];
void dfs(int position)
{
    for(int i = 0;i <= k[position];i++)
    {
        dfss[position] = i;
        if(position < M-1) dfs(position + 1); 
        else
        {
            int keynow = key(dfss, M);

            for(int j = 0;j < N;j++)
            {
                memcpy(tmp, dfss, 20);
                for(int k = 0;k < offer[j].m;k++)
                    tmp[offer[j].keymp[k]] -= offer[j].k[k];

                int keynxt = key(tmp, M);

                if(keynxt == -1) continue;

                int d = dp[keynxt] + offer[j].p;

                if(dp[keynow] > d) dp[keynow] = d;
                
            }
            for(int j = 0;j < M;j++)
            {
                memcpy(tmp, dfss, 20);

                tmp[j] --;

                int keynxt = key(tmp, M);
                if(keynxt == -1) continue;

                int d = dp[keynxt] + p[j];

                if(dp[keynow] > d) dp[keynow] = d;
            }
        }

    }

}
int main()
{
#ifdef HOME
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);
#endif
    scanf("%d", &N);
    for(int i = 0;i < N;i++)
    {
        scanf("%d", &offer[i].m);

        for(int j = 0;j < offer[i].m;j++)
            scanf("%d %d", &offer[i].c[j], &offer[i].k[j]);

        scanf("%d", &offer[i].p);
    }
    scanf("%d", &M);

    int c;
    for(int i = 0;i < M;i++)
    {
        scanf("%d %d %d", &c, k+i, p+i);

        mp[c] = i;
    }
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < offer[i].m;j++)
            offer[i].keymp[j] = mp[offer[i].c[j]];
    }
    memset(dp, 0x7f, sizeof(dp));
    dp[0] = 0;

    dfs(0);

    int keyret = key(k, M);
    cout<<dp[keyret]<<endl;

    return 0;
}

