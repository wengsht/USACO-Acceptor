
/*
ID: wengsht1
LANG: C++
TASK: range
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

bool good[251][251];
int preone[251][251][2];
char input[255];
int ret[251];

void go(int r, int c)
{
    if(!good[r][c]) return ;

    int size = 2;
    for(size = 2; ;size++)
    {
        int nr = r + size - 1, nc = c + size - 1;

        if(nr >= N || nc >= N) break;

        if(preone[nr][nc][0] >= size && preone[nr][nc][1] >= size)
            ret[size]++;
        else break;
    }
}
int main()
{
#ifdef HOME
    freopen("range.in", "r", stdin);
    freopen("range.out", "w", stdout);
#endif
    scanf("%d", &N);

    for(int i = 0;i < N;i++)
    {
        scanf("%s", input);

        for(int j = 0;j < N;j++)
            if(input[j] == '1') good[i][j] = true;
    }
    for(int i = 0;i < N;i++)
    {
        if(good[i][0]) preone[i][0][0] = 1;
        if(good[0][i]) preone[0][i][1] = 1;
        for(int j = 1;j < N;j++)
        {
            if(good[i][j]) preone[i][j][0] = preone[i][j-1][0] + 1;
            if(good[j][i]) preone[j][i][1] = preone[j-1][i][1] + 1;
        }
    }
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N;j++)
        {
            go(i, j);
        }
    }
    for(int i = 2;i <= N;i++)
    {
        if(ret[i])
            cout<<i<<" "<<ret[i]<<endl;
        else break;
    }
   



    return 0;
}

