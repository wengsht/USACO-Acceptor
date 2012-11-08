
/*
ID: wengsht1
LANG: C++
TASK: camelot
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

inline bool good(int r, int c)
{
    return (r >= 0 && r < N && c >= 0 && c < M);
}

int d[31][31][31][31];
char c;

int kr[10000], kc[10000];
int m;

typedef pair<int, int> Pair;

int _r[] = {2, 2, 1, 1, -2, -2, -1, -1};
int _c[] = {1, -1, 2, -2, 1, -1, 2, -2};

#define inf 10000
// 贪心  king只自己走最多三步
#define tanxinmx 3 
int cal(int r, int c)
{
    int ret = 0;
    for(int i = 1;i < m;i++)
    {
        ret += d[kr[i]][kc[i]][r][c];
    }

    int kingmx = max(abs(r-kr[0]), abs(c-kc[0]));

    int mn = kingmx + ret;
    int mntoking = 0;
    for(int a = 0;a < N;a++)
    {
        for(int b = 0;b < M;b++)
        {
            int kingto = max(abs(a-kr[0]), abs(b-kc[0]));

            if(kingto >= tanxinmx) continue;

            mntoking = inf;
           
            for(int i = 1;i < m;i++)
            {
                int tm = d[kr[i]][kc[i]][a][b] - d[kr[i]][kc[i]][r][c];

                if(tm < mntoking)
                {
                    mntoking = tm;
                }

            }
            int tmp = ret + mntoking + kingto + d[a][b][r][c];
            if(tmp < mn) mn = tmp;
        }
    }
    return mn;
}

int main()
{
#ifdef HOME
    freopen("camelot.in", "r", stdin);
    freopen("camelot.out", "w", stdout);
#endif
    scanf("%d %d", &M, &N);
    for(int i = 0;i < N;i++)
        for(int j = 0;j < M;j++)
            for(int k = 0;k < N;k++)
                for(int z = 0;z < M;z++)
                    d[i][j][k][z] = inf;

    cin>>c>>kc[m];
    kr[m] = c - 'A';
    kc[m++]--;

    while(cin>>c>>kc[m])
    {
        kc[m]--;
        kr[m] = c - 'A';
        m++;
    }
    for(int a = 0;a < N;a++)
    {
        for(int b = 0;b < M;b++)

        {
            queue<Pair> q;

            q.push(make_pair(a, b));

            d[a][b][a][b] = 0;

            while(!q.empty())
            {
                Pair top = q.front();

                q.pop();

                int r = top.first, c = top.second;
                int l = d[a][b][r][c];

                int rn, cn;

                for(int j = 0;j < 8;j++)
                {
                    rn = r + _r[j];
                    cn = c + _c[j];

                    if(good(rn, cn) && (d[a][b][rn][cn] >= inf))
                    {
                        d[a][b][rn][cn] = l+1;

                        q.push(make_pair(rn, cn));
                    }
                }
            }
        }
    }

    if(m == 1)
    {
        cout<<0<<endl;

        return 0;
    }

    int ret = 1000000000;
    for(int i = 0;i < N;i++)
        for(int j = 0;j < M;j++)
            ret = min(cal(i, j), ret);

    cout<<ret<<endl;
    return 0;
}

