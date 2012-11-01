
/*
ID: wengsht1
LANG: C++
TASK: maze1
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

int nxt[101*101][4];
int cnt[101*101];
char board[301][200];

int _x[] = {0, 0, 1, -1};
int _y[] = {1, -1, 0, 0};

int dis[101][39];
int dis2[101][39];

inline bool good(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < M);
}

void bfs(int stx, int sty, int d[101][39])
{
    queue<int> q;

    d[stx][sty] = 1;

    q.push(stx * 100 + sty);

    while(!q.empty())
    {
        int top = q.front();
        q.pop();

        int ltop = d[top/100][top%100];

        for(int i = 0;i < cnt[top];i++)
        {
            int xnxt = nxt[top][i] / 100, ynxt = nxt[top][i] % 100;

            if(d[xnxt][ynxt] == 0)
            {
                d[xnxt][ynxt] = ltop + 1;

                q.push(xnxt * 100 + ynxt);
            }
        }
    }
}

int main()
{
#ifdef HOME
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);
#endif
    char str[101];
    scanf("%[^\n]s", str);
    getchar();
    sscanf(str, "%d %d", &M, &N);

    for(int i = 0;i < 2*N+1;i++)
    {
        scanf("%[^\n]s", board[i]);
        getchar();
    }

    int stx[2], sty[2];
    int m = 0;
    for(int i = 0;i < M;i++)
    {
        if(board[0][2*i+1] == ' ')
        {
            stx[m] = 0;
            sty[m++] = i;
        }
        if(board[2*N][2*i+1] == ' ')
        {
            stx[m] = N-1;
            sty[m++] = i;
        }
    }
    for(int i = 0;i < N;i++)
    {
        if(board[2*i+1][0] == ' ')
        {
            stx[m] = i;
            sty[m++] = 0;
        }
        if(board[2*i+1][2*M] == ' ')
        {
            stx[m] = i;
            sty[m++] = M-1;
        }
    }

    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < M;j++)
        {
            int key = i * 100 + j;
            int xnxt, ynxt;

            int h = 2 * i + 1, w = 2 * j + 1;

            for(int k = 0;k < 4;k++)
            {
                xnxt = i + _x[k];
                ynxt = j + _y[k];

                if(!good(xnxt, ynxt)) continue;

                if(board[h + _x[k]][w + _y[k]] == ' ')
                    nxt[key][cnt[key]++] = xnxt * 100 + ynxt;
            }
        }
    }

    bfs(stx[0], sty[0], dis);
    bfs(stx[1], sty[1], dis2);

    int mn = 0;
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < M;j++)
        {
            int mx = min(dis[i][j], dis2[i][j]);

            if(mn < mx) mn = mx;
        }
    }
    cout<<mn<<endl;

    return 0;
}

