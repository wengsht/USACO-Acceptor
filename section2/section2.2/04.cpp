
/*
ID: wengsht1
LANG: C++
TASK: subset
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

unsigned int dp[2][35*35];
int main()
{
#ifdef HOME
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
#endif
    cin>>N;
    int sum = (N + 1) * N / 2;

    if(sum % 2) 
    {
        cout<<0<<endl;

        return 0;
    }
    int avg = sum / 2;

    int now = 1;
    dp[0][0] = 1;
    dp[1][0] = 1;
    for(int i = 1;i <= N;i++)
    {
        now ^= 1;
        for(int j = 0;j <= avg;j++)
        {
            if(i + j <= avg)
                dp[now][i+j] += dp[now^1][j];
        }
        memcpy(dp[now^1], dp[now], sizeof(dp[now]));
    }
    cout<<dp[now][avg] / 2<<endl;

    return 0;
}

