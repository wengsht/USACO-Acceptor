
/*
ID: wengsht1
LANG: C++
TASK: cowcycle
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
int F1, F2, R1, R2;
double rate[100][100];
int tmp[20];
int ret[20];
double rates[100];
double mxdt = 100000000.0;

void test()
{
    int m = 0;
    for(int i = 0;i < N;i++)
        for(int j = 0;j < M;j++)
            rates[m++] = rate[tmp[i]][tmp[j+N]];

    sort(rates, rates+m);

    if(rates[m-1] / rates[0] < 3.0) 
        return ;

    double avg = 0, dt = 0;
    for(int i = 0;i < m-1;i++)
    {
        rates[i] = rates[i+1] - rates[i];
        avg += rates[i];
        dt  += rates[i] * rates[i];
    }
    avg /= (m-1);
    dt /= (m-1);
    dt -= avg * avg;


    if(dt < mxdt)
    {
        mxdt = dt;
        memcpy(ret, tmp, sizeof(tmp));
    }
}
int cnt = 0;
const int INF = 100000;
void dfs(int h, int mn, int mx)
{
    if(cnt++ > INF) return ;
    if(mn > mx) 
        return ;

    int lest = 0;
    if(h < N) lest = N - h - 1;
    else      lest = M + N - h - 1;
    for(int i = mn;i <= mx;i++)
    {
        tmp[h] = i;
        if(h == N+M-1)
            test();
        else if(h == N-1)
            dfs(h+1, R1, R2);
        else
        {
            if(mx - i < lest) 
                continue;
            dfs(h+1, i+1, mx);
        }
    }
}


int main()
{
#ifdef HOME
    freopen("cowcycle.in", "r", stdin);
    freopen("cowcycle.out", "w", stdout);
#endif
    scanf("%d %d", &N, &M);
    scanf("%d %d %d %d", &F1, &F2, &R1, &R2);

    for(int i = F1;i <= F2;i++)
        for(int j = R1; j <= R2;j++)
            rate[i][j] = (double)i / (double)j;

    dfs(0, F1, F2);
    
    int i;
    printf("%d", ret[i]);
    for(i = 1;i < N;i++)
        printf(" %d", ret[i]);
    printf("\n");

    printf("%d", ret[i++]);
    for(int j = 1;j < M;j++)
        printf(" %d", ret[i++]);
    printf("\n");

    return 0;
}

