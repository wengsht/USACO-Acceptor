
/*
ID: wengsht1
LANG: C++
TASK: nocows
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

unsigned int dp[201][101];
int main()
{
#ifdef HOME
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
#endif
    cin>>N>>K;

    dp[0][0] = 0;
    dp[1][1] = 1;

    for(int i = 2;i <= N;i++)
    {
        for(int j = 0;j < i;j++)
        {
            int k = i - 1 - j;

            for(int jh = 1;jh <= j;jh++)
            {
                for(int kh = 1;kh <= k;kh++)
                {
                    int mx = max(jh, kh) + 1;
                    if(mx > K) break;

                    dp[i][mx] = (dp[i][mx] + dp[j][jh] * dp[k][kh]) % 9901;
                }
            }
        }
    }
    cout<<dp[N][K]<<endl;
    return 0;
}

