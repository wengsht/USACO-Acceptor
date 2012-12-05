
/*
ID: wengsht1
LANG: C++
TASK: theme
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

#define MX 5005
int N, M, K;
int s[MX];
int dp[MX][157];
int ret;

int getdp(int i, int j)
{
    int l = j >> 5, r = j & (0x1f);

    return dp[i][l] & (1 << r);
}
void setdp(int i, int j)
{
    int l = j >> 5, r = j & (0x1f);

    dp[i][l] |= (1<<r);
}
int main()
{
#ifdef HOME
    freopen("theme.in", "r", stdin);
    freopen("theme.out", "w", stdout);
#endif
    scanf("%d", &N);
    for(int i = 0;i < N;i++)
        scanf("%d", s+i);

    for(int i = 0;i < N-1;i++)
        s[i] = s[i] - s[i+1];

    for(int i = 0;i < N;i++)
    {
        for(int j = i+2;j < N;j++)
        {
            if(ret > N - j)
                break;
            if(getdp(i, j))
                continue;
            else
            {
                int pi = i, pj = j;
                int r = 0;
                while(s[pi] == s[pj] && pi + 1 < j)
                {
                    setdp(pi, pj);
                    r++;
                    pi++;
                    pj++;
                }

                if(ret < r) 
                    ret = r;
            }
        }
    }
    if(ret < 4)
        cout<<0<<endl;
    else 
        cout<<ret+1<<endl;

    return 0;
}

