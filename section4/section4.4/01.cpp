
/*
ID: wengsht1
LANG: C++
TASK: shuttle
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
int w[13], b[13];
int ret[MX], m;

int main()
{
#ifdef HOME
    freopen("shuttle.in", "r", stdin);
    freopen("shuttle.out", "w", stdout);
#endif
    cin>>N;
    int p = 1;

    for(int i = 1;i <= N;i++)
        w[i] = p++;
    p++;
    for(int i = 1;i <= N;i++)
        b[i] = p++;

    for(int i = 1;i <= N;i++)
    {
        if(i % 2 == 1)
        {
            for(int j = 0;j < i-1;j++)
            {
                ret[m++] = w[N-j];
                w[N-j] += 2;
            }
            ret[m++] = w[N-i+1];
            w[N-i+1] ++;
        }
        else
        {
            for(int j = 0;j < i-1;j++)
            {
                ret[m++] = b[j+1];
                b[j+1] -= 2;
            }
            ret[m++] = b[i];
            b[i]--;
        }
    }
    if(N % 2 == 0)
    {
        for(int i = N;i >= 1;i--)
        {
            for(int j = i;j >= 1;j--)
            {
                if(w[j] < N+1+j)
                {
                    ret[m++] = w[j];
                    w[j] += 2;
                }
                
            }
            for(int j = N-i+1; j <= N;j++)
            {
                if(b[j] > j)
                {
                    ret[m++] = b[j];

                    b[j] -= 2;
                }
            }
        }
    }
    else
    {
        for(int i = N;i >= 1;i--)
        {
            for(int j = N-i+1; j <= N;j++)
            {
                if(b[j] > j)
                {
                    ret[m++] = b[j];

                    b[j] -= 2;
                }
            }
            for(int j = i;j >= 1;j--)
            {
                if(w[j] < j+N+1)
                {
                    ret[m++] = w[j];
                    w[j] += 2;
                }
                
            }
        }
    }

    int cnt = 1;
    printf("%d", ret[0]);
    for(int i = 1;i < m;i++)
    {
        if(cnt%20 != 0) printf(" ");
        printf("%d", ret[i]);
        cnt++;

        if(cnt % 20 == 0)
            printf("\n");
    }
    if(cnt % 20 != 0)
        printf("\n");


    return 0;
}


