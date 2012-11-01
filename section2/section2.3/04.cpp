
/*
ID: wengsht1
LANG: C++
TASK: money
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

int gold[30];

long long dp[2][10001];

int main()
{
#ifdef HOME
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
#endif
    cin>>N>>M;

    for(int i = 0;i < N;i++)
        scanf("%d", gold+i);

    dp[0][0] = dp[1][0] = 1;
    int now = 1;
    for(int i = 0;i < N;i++)
    {
        now ^= 1;
        for(int l = M;l >= 0;l--)
        {
            for(int k = 1;;k++)
            {
                int j = l - k * gold[i];

                if(j < 0) break;

                dp[now][l] += dp[now ^ 1][j];
            }
        }
        memcpy(dp[now^1], dp[now], sizeof(dp[now]));
    }
    cout<<dp[now][M]<<endl;



    return 0;
}

