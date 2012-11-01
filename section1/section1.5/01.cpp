
/*
ID: wengsht1
LANG: C++
TASK: numtri
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

int dp[1001][1001];
int data[1001][1001];
int main()
{
#ifdef HOME
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
#endif
    scanf("%d", &N);

    for(int i = 0;i < N;i++)
        for(int j = 0;j <= i;j++)
            scanf("%d", &data[i][j]);

    dp[0][0] = data[0][0];

    for(int i = 1;i < N;i++)
    {
        dp[i][0] = dp[i-1][0] + data[i][0];
        for(int j = 1;j <= i;j++)
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + data[i][j];
    }

    int mx = 0;
    for(int i = 0;i < N;i++)
        if(mx < dp[N-1][i]) mx = dp[N-1][i];

    cout<<mx<<endl;

    return 0;
}

