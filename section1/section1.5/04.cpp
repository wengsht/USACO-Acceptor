
/*
ID: wengsht1
LANG: C++
TASK: checker
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

unsigned int board[14];

unsigned int mask[14];

int ret;
int res[14];
void dfs(int h)
{
    for(int i = 0;i < N;i++)
    {
        if(mask[i] & board[h]) continue;

        res[h] = i+1;

        if(h == N-1)
        {
            ret++;

            if(ret <= 3)
            {
                printf("%d", res[0]);
                for(int j = 1;j < N;j++) printf(" %d", res[j]);
                printf("\n");
            }
            continue;
        }
        int k = 1;
        int tmp[13];
        for(int j = h+1;j < N;j++, k++)
        {
            tmp[j] = board[j];
            board[j] |= mask[i];
            if(i + k < N) board[j] |= mask[i+k];
            if(i - k >= 0) board[j] |= mask[i-k];
        }
        dfs(h+1);
        k = 1;
        for(int j = h+1;j < N;j++, k++)
            board[j] = tmp[j];
    }
}

int main()
{
#ifdef HOME
    freopen("checker.in", "r", stdin);
    freopen("checker.out", "w", stdout);
#endif
    mask[0] = 1;
    for(int i = 1;i <= 13;i++) mask[i] = mask[i-1] * 2;
    cin>>N;
   
    dfs(0);

    cout<<ret<<endl;

    return 0;
}

