
/*
ID: wengsht1
LANG: C++
TASK: concom
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
int stock[101][101];
bool charge[101][101];
int a, b, p;

int main()
{
#ifdef HOME
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
#endif

    scanf("%d", &N);

    for(int i = 0;i < N;i++)
    {
        scanf("%d %d %d", &a, &b, &p);

        stock[a][b] += p;
    }
    int tmp[101];
    for(int i = 1;i <= 100;i++)
    {
        memcpy(tmp, stock[i], sizeof(tmp));
        charge[i][i] = true;

        bool ok = true;

        while(ok)
        {
            int mn = 0, l = -1;

            for(int j = 1;j <= 100;j++)
            {
                if(charge[i][j]) continue;

                if(mn < tmp[j]) 
                {
                    mn = tmp[j];

                    l = j;
                }
            }
            if(mn <= 50) break;

            charge[i][l] = true;

            for(int j = 1;j <= 100;j++) tmp[j] += stock[l][j];
        }
    }
    for(int i = 1;i <= 100;i++)
    {
        for(int j = 1;j <= 100;j++)
        {
            if(i == j) continue;

            if(charge[i][j]) cout<<i<<" "<<j<<endl;
        }
    }

    return 0;
}

