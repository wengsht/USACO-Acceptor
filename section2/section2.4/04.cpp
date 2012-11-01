
/*
ID: wengsht1
LANG: C++
TASK: cowtour
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
#define INF 10000000
int N, M, K;
bool connect[151][151];
double dis[151][151];
double dis2[151][151];
char str[161];

double x[151], y[151];

inline double dpath(double x1, double y1, double x2, double y2)
{
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

inline bool xmulti(int i, int p,int j)
{
    return (x[i] - x[j]) * (y[p] - y[j]) - 
        (x[p] - x[j]) * (y[i] - y[j]);

}
inline bool f(int x, int y, int k)
{
    return (x <= k && y >= k || x >= k && y <= k);
}
inline bool line(int i, int j, int k)
{
    bool ok = f(x[i], x[j], x[k]) && f(y[i], y[j], y[k]);
    
    return (ok && ((xmulti(i,k,j) == 0) && 
            ((x[k] - x[i]) * (x[k] - x[j]) <= 0 ||
             (y[k] - y[i]) * (y[k] - y[j]) <= 0)));
}
int main()
{
#ifdef HOME
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);
#endif
    scanf("%d", &N);

    for(int i = 0;i < N;i++) scanf("%lf %lf", x+i, y+i);
    for(int i = 0;i < N;i++)
    {
        scanf("%s", str);

        dis[i][i] = 0;
        for(int j = i+1;j < N;j++)
        {
            if(str[j] == '1')
            {
                connect[i][j] = true;

                dis[j][i] = dis[i][j] = dpath(x[i], y[i], x[j], y[j]);
            }
            else
            {
                dis[j][i] = dis[i][j] = INF;
            }
        }
    }
    double mx = 0;
    for(int k = 0;k < N;k++)
        for(int i = 0;i < N;i++)
            for(int j = 0;j < N;j++)
                if(dis[i][j] > dis[i][k] + dis[k][j]) dis[i][j] = dis[i][k] + dis[k][j];

    mx = INF;

    for(int i = 0;i < N;i++)
    {
        for(int j = i+1;j < N;j++)
        {
            if(dis[i][j] < INF) continue;

            double ij = dpath(x[i], y[i], x[j], y[j]);
            double mxtmp = ij;
            bool ok = true;
            for(int k = 0;k < N && ok;k++)
            {
                if(dis[k][i] >= INF && dis[k][j] >= INF) continue;
                for(int k2 = k+1;k2 < N && ok;k2++)
                {
                    double d1 = dis[k][i] + dis[k2][j];
                    double d2 = dis[k][j] + dis[k2][i];

                    double d3 = min(d1, d2) + ij;

                    double mn = min(d3, dis[k][k2]);
                    if(mn < INF)
                    {
                        mxtmp = max(mn, mxtmp);

                        if(mxtmp > mx)
                        {
                            ok = false;
                            break;
                        }
                    }

                }
            }

            if(mx > mxtmp) mx = mxtmp;
        }
    }
    cout<<fixed<<mx<<endl;

    return 0;
}

