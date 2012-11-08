
/*
ID: wengsht1
LANG: C++
TASK: game1
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

int s[201];
int dp[201][201];
int sum[201];

int main()
{
#ifdef HOME
    freopen("game1.in", "r", stdin);
    freopen("game1.out", "w", stdout);
#endif
    scanf("%d", &N);

    for(int i = 1;i <= N;i++) 
    {
        scanf("%d", s+i);

        sum[i] = sum[i-1] + s[i];
    }
    for(int i = 1;i <= N;i++)
        dp[i][i] = s[i];
    for(int l = 2;l <= N;l++)
    {
        for(int i = 1;i < N;i++)
        {
            int j = i + l - 1;
            if(j > N) break;

            dp[i][j] = s[i] + (sum[j] - sum[i]  - dp[i+1][j]);
            dp[i][j] = max(dp[i][j], s[j] + (sum[j-1] - sum[i-1] - dp[i][j-1]));
        }
    }
    cout<<dp[1][N]<<" "<<sum[N] - dp[1][N]<<endl;


    return 0;
}

