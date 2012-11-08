
/*
ID: wengsht1
LANG: C++
TASK: kimbits
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
long long N, L, I;

long long dp[35][35];
long long nums[35];

long long masks[34];
int ret;

void go(long long N, long long L, long long I)
{
    if(I <= 0) return ;

    nums[0] = 1;
    nums[1] = 1;
    for(long long i = 2;i <= N;i++)
    {
        nums[i] = 0;
        int mx = min(L, i);
        for(int j = 1;j <= mx;j++) nums[i] += dp[i][j];

    }
    long long sum = 0;

    int i = -1;
    while(sum < I)
    {
        i++;
        sum += nums[i];
    }
    if(sum > I) 
    {
        sum -= nums[i];
        ret |= masks[i-1];
        L --;
        I -= sum;
        go(i-1, L, I);
    }
    else
    {
        for(int j = 0; j < L;j++)
            ret |= masks[i-1-j];
    }

}
char rets[34];
    char tmp[34];
void output(long long ret, long long N)
{
    int m = 0;

    for(int i = 0;i < N;i++)
    {
        tmp[m++] = '0' + ret % 2;

        ret /= 2;
    }
    for(int i = m-1;i >= 0;i--) rets[m-i-1] = tmp[i];
    rets[m] = '\0';

    printf("%s\n",rets);
}
int main()
{
#ifdef HOME
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);
#endif
    cin>>N>>L>>I;

    masks[0] = 1;
    for(int i = 1;i <= 32;i++) masks[i] = masks[i-1] * 2;


    for(int i = 1;i <= N;i++) 
    {
        dp[i][1] = 1;
    }
    dp[0][1] = 0;
    for(long long i = 1;i <= N;i++)
    {
        int mx = min(i, L);

        for(int j = 2;j <= mx;j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    go(N, L, I);

    output(ret,N);

    return 0;
}

