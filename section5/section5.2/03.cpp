// 位运算暴力搜索
/*
ID: wengsht1
LANG: C++
TASK: wissqu
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

#define f(i) (1<<i)

const int mask_mx = (1 << 16);
const int mask_inf = mask_mx - 1;
int   mask[mask_mx];
int   mask_one[16];

int _x[] = {1,1,1,-1,-1,-1,0,0};
int _y[] = {0,-1,1,0,-1,1,1,-1};

inline bool good(int x, int y)
{
    return (x >= 0 && x < 4 && y >= 0 && y < 4);
}
int a[5];
#define A a[0]
#define B a[1]
#define C a[2]
#define D a[3]
#define E a[4]

bool ok = false;
int  ret = 0;

int cnt[5] = {3, 3, 3, 4, 3};
int board[16];
int f[16];
void init()
{
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            int n = (i << 2) + j;
            mask_one[n] = (1<<n);
            for(int k = 0;k < 8;k++)
            {
                int x_nxt = i + _x[k], y_nxt = j + _y[k];

                if(good(x_nxt, y_nxt))
                    mask_one[n] |= (1 << ((x_nxt<<2) + y_nxt));
            }

        }
    }
    for(int i = 0;i < mask_mx;i++)
    {
        int j = i;
        int k = 0;
        while(j)
        {
            if(j % 2)
                mask[i] |= mask_one[k];

            ++k;
            j >>= 1;
        }
    }
    f[0] = 1;
    for(int i = 1;i < 16;i++) 
        f[i] = f[i-1] * 2;
}
int road[2][16];
int had;
void dfs(int h)
{
    int tmp;
    int mn = 0, mx = 4;
    if(!h)
        mn = mx = 3;
    for(int j = mn;j <= mx;j++)
    {
        if(!cnt[j]) continue;
        tmp = mask[a[j]];
        for(int i = 0;i < 16;i++)
        {
            if((had & f[i]) == 0 && 0 == (tmp & 1))
            {
                road[0][h] = i;
                road[1][h] = j;
                if(h == 15)
                {
                    if(!ok)
                    {
                        ok = true;

                        for(int k = 0;k < 16;k++)
                            cout<<(char)('A'+road[1][k])<<" "<<road[0][k] / 4 + 1<<" "<<road[0][k] % 4 + 1<<endl;
                    }
                    ret++;

                    return ;
                }
                int t = board[i];
                a[t] -= f[i];
                a[j] |= f[i];
                board[i] = j;
                cnt[j] --;
                had |= f[i];

                dfs(1+h);
                
                a[t] |= f[i];
                board[i] = t;
                a[j] -= f[i];
                cnt[j]++;
                had -= f[i];
            }
            tmp >>= 1;
        }
    }

}
int main()
{
#ifdef HOME
    freopen("wissqu.in", "r", stdin);
    freopen("wissqu.out", "w", stdout);
#endif
    init();

    char input[5];
    for(int i = 0;i < 4;i++)
    {
        scanf("%s", input);
        for(int j = 0;j < 4;j++)
        {
            board[(i<<2)+j] = input[j] - 'A';
            int n = (i << 2) + j;
            a[input[j]-'A'] |= (1<<n);
        }
    }
    dfs(0);

    cout<<ret<<endl;

    return 0;
}

