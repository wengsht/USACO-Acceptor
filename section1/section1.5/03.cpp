
/*
ID: wengsht1
LANG: C++
TASK: sprime
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

int ret[2][MX];
int m;
bool isprime(int l)
{
    if(l <= 1) return false;
    int k = sqrt((double)l);

    for(int i = 2;i <= k;i++)
    {
        if(l % i == 0) return false;
    }
    return true;
}
int main()
{
#ifdef HOME
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
#endif

    ret[0][m++] = 2;
    ret[0][m++] = 3;
    ret[0][m++] = 5;
    ret[0][m++] = 7;


    cin>>N;

    int now = 0, mm ;
    for(int i = 1;i < N;i++)
    {
        now ^= 1;
        mm = 0;

        for(int i = 0;i < m;i++)
        {
            for(int j = 1;j <= 9;j += 2)
            {
                int tmp = ret[now ^ 1][i] * 10 + j;
                if(isprime(tmp)) ret[now][mm++] = tmp;
            }
        }
        m = mm;
    }

    for(int i = 0;i < mm;i++)
        printf("%d\n", ret[now][i]);

    return 0;
}

