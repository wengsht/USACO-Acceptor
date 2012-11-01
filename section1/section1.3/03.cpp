
/*
ID: wengsht1
LANG: C++
TASK: barn1
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

int M, S, C;
int stall[201];
int dp[201][51];

int main()
{
#ifdef HOME
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
#endif
    scanf("%d %d %d", &M, &S, &C);
    for(int i = 0;i < C;i++) scanf("%d",stall+i);

    sort(stall, stall+C);

    for(int i = 1;i <= M;i++) dp[0][i] = 1;

    for(int i = 1;i < C;i++)
    {
        dp[i][1] = stall[i] - stall[0] + 1;
        for(int j = 2;j <= M;j++)
        {
            dp[i][j] = min(dp[i-1][j-1] + 1, dp[i-1][j] + stall[i] - stall[i-1]);
        }
    }
    int ret = 99999;

    for(int i = 1;i <= M;i++)
    {
        if(ret > dp[C-1][i]) ret = dp[C-1][i];
    }
    cout<<ret<<endl;

    return 0;
}

