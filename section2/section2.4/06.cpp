
/*
ID: wengsht1
LANG: C++
TASK: fracdec
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

#define MX 200000
int N, M, K;

char ret[MX];
char tmp[MX];
int  remind[MX];
int len, lent;
int dp[MX][10];

int go(int N, int M)
{
    while(N)
    {
        N *= 10;
        int k = N/ M;
        tmp[lent] = '0' + k;
        N %= M;
        remind[lent++] = N;

        if(dp[N][k])
        {
            lent--;
            return dp[N][k] - 1;
        }
        dp[N][k] = lent;
    }
    return -1;
}

int main()
{
#ifdef HOME
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);
#endif
    cin>>N>>M;

    int l = N / M;
    sprintf(ret, "%d.", l);
    len = strlen(ret);
    N %= M;

    if(N == 0)
    {
        ret[len] = '0';
        ret[len+1] = '\0';
    }
    else 
    {
        int p = go(N, M);
        tmp[lent] = '\0';
        if(p == -1)
            strcat(ret, tmp);
        else
        {
            strncat(ret, tmp, p);
            len = strlen(ret);
            ret[len++] = '(';
            ret[len++] = '\0';
            strcat(ret, tmp+p);
            len = strlen(ret);
            ret[len++] = ')';
            ret[len++] = '\0';
        }

    }
    len = strlen(ret);

    char out[100];
    memset(out, 0, sizeof(out));
    for(int i = 0;i < len;i+= 76)
    {
        strncpy(out, ret+i, 76);
        printf("%s\n", out);
    }

    return 0;
}

