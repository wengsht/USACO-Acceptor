
/*
ID: wengsht1
LANG: C++
TASK: castle
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

#define key(a, b) (a*51 + b)
int N, M, K;

int rc[51][51];
int color[51][51];

int ret[2501];
int mxret = 0;
int m = 1;

int _x[4] = {0, -1, 0, 1};
int _y[4] = {-1, 0, 1, 0};
int mask[4] = {1, 2, 4, 8};

inline bool good(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < M);
}

int main()
{
#ifdef HOME
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
#endif
    scanf("%d %d", &M, &N);

    for(int i = 0;i < N;i++)
        for(int j = 0;j < M;j++)
            scanf("%d", &rc[i][j]);

    queue<int> q;

    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < M;j++)
        {
            if(color[i][j]) continue;

            int st = key(i, j);
            color[i][j] = m;
            int cnt = 1;

            q.push(st);

            while(!q.empty())
            {
                int top = q.front();
                q.pop();
                int a = top / 51, b = top % 51;

                for(int k = 0;k < 4;k++)
                {
                    if((mask[k] & rc[a][b]) == 0)
                    {
                        int xnxt = _x[k] + a;
                        int ynxt = _y[k] + b;

                        if(good(xnxt, ynxt) && !color[xnxt][ynxt])
                        {
                            color[xnxt][ynxt] = m;

                            cnt++;
                            q.push(key(xnxt, ynxt));
                        }
                    }
                }
            }
            ret[m++] = cnt;
            if(mxret < cnt) mxret = cnt;
        }
    }
    cout<<m-1<<endl<<mxret<<endl;

    int xret, yret;
    char op;
    int mx = 0;
    for(int j = 0;j < M;j++)
    {
        for(int i = N-1;i >= 0;i--)
        {
            int x = i - 1, y = j;
            if(good(x, y) && color[i][j] != color[x][y])
            {
                if(mx < ret[color[i][j]] + ret[color[x][y]]) 
                {
                    mx = ret[color[i][j]] + ret[color[x][y]];

                    op = 'N';
                    xret = i;
                    yret = j;
                }
            }
            x = i; y = j+1;
            if(good(x, y) && color[i][j] != color[x][y])
            {
                if(mx < ret[color[i][j]] + ret[color[x][y]]) 
                {
                    mx = ret[color[i][j]] + ret[color[x][y]];

                    op = 'E';
                    xret = i;
                    yret = j;
                }
            }
        }
    }
    cout<<mx<<endl<<xret+1<<" "<<yret+1<<" "<<op<<endl;
    

    return 0;
}

