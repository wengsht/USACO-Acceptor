
/*
ID: wengsht1
LANG: C++
TASK: fence4
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
int ret;

struct Node
{
    double x, y;
    bool good;
}node[201];

#define eps 1e-10
inline bool cross(Node a ,Node b, Node c, Node d)
{
    if( min(a.x, b.x) > max(c.x, d.x) ||
        min(a.y, b.y) > max(c.y, d.y) ||
        min(c.x, d.x) > max(a.x, b.x) ||
        min(c.y, d.y) > max(a.y, b.y) ) return 0;

    double h, i, j, k;
    h = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    i = (b.x - a.x) * (d.y - a.y) - (b.y - a.y) * (d.x - a.x);
    j = (d.x - c.x) * (a.y - c.y) - (d.y - c.y) * (a.x - c.x);
    k = (d.x - c.x) * (b.y - c.y) - (d.y - c.y) * (b.x - c.x);

    return h * i <= eps && j * k <= eps;
}
bool test()
{
    for(int i = 1;i < N;i++)
        for(int j = 1;j < i-1; j++)
            if(cross(node[i], node[i+1], node[j], node[j+1])) return false;

    for(int i = 2;i < N-1;i++)
        if(cross(node[i], node[i+1], node[1], node[N])) return false;

    return true;
}
int main()
{
#ifdef HOME
    freopen("fence4.in", "r", stdin);
    freopen("fence4.out", "w", stdout);
#endif
    scanf("%d", &N);
    scanf("%lf %lf", &node[0].x, &node[0].y);

    for(int i = 1;i <= N;i++) scanf("%lf %lf", &node[i].x, &node[i].y);

    if(!test())
    {
        printf("NOFENCE\n");

        return 0;
    }

    for(int i = 1;i <= N;i++)
    {
        int j = i+1;
        if(j > N) j = 1;


        Node test;
        test.x = node[i].x;
        test.y = node[i].y;

        double x_add = (node[j].x - node[i].x) / 200.0;
        double y_add = (node[j].y - node[i].y) / 200.0;

        bool good = false;
        for(int k = 1;k < 200 && !good;k++)
        {
            test.x += x_add;
            test.y += y_add;

            int z;
            for(z = 1;z <= N;z++)
            {
                if(z == i) continue;

                int c = z + 1;
                if(c > N) c = 1;

                if(cross(node[0], test, node[z], node[c])) break;
            }
            if(z > N) good = true;
        }
        if(good) ret++;
        node[i].good = good;
    }

    printf("%d\n", ret);
    for(int i = 1;i < N-1;i++)
    {
        if(node[i].good)
        {
            printf("%.0lf %.0lf %.0lf %.0lf\n", node[i].x, node[i].y, node[i+1].x, node[i+1].y);
        }
    }
    if(node[N].good)
        printf("%.0lf %.0lf %.0lf %.0lf\n", node[1].x, node[1].y, node[N].x, node[N].y);
    if(node[N-1].good)
        printf("%.0lf %.0lf %.0lf %.0lf\n", node[N-1].x, node[N-1].y, node[N].x, node[N].y);
   


    return 0;
}

