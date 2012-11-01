
/*
ID: wengsht1
LANG: C++
TASK: prefix
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

char pri[201][11];
int len[201];
int m;
char S[200001], tmp[200001];
int dp[200001];

int main()
{
#ifdef HOME
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
#endif
    while(scanf("%s", pri[m]) && pri[m][0] != '.')
    {
        len[m] = strlen(pri[m]);
        m++;
    }

    while(cin>>tmp)
        strcat(S, tmp);

    N = strlen(S);

    int mx = 0;
    dp[0] = 1;
    for(int i = 1;i <= N;i++)
    {
        for(int j = 0;j < m;j++)
        {
            int k = i - len[j];
            if(k >= 0 && dp[k] && strncmp(S+k, pri[j], len[j]) == 0)
            {
//                dp[i] = max(dp[i], dp[k] + len[j]);

                dp[i] = true;
                if(mx < i) mx = i;
                break;
            }
        }
    }
    cout<<mx<<endl;

    return 0;
}

