// 三分

/*
ID: wengsht1
LANG: C++
TASK: fence3
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

class Point 
{
    public:
    Point(double xx, double yy) 
        :x(xx), y(yy)
    {}
    Point()
    {

    }
    double x, y;
};
struct Line
{
    Point a, b;
}lines[151];
int m;
inline bool VERTICAL(Line l)
{
    return l.a.x == l.b.x;
}
inline double inside(double a, double b, double c)
{
    if(a > b) swap(a, b);

    if(a <= c && b >= c) return 0;
    if(a > c) return a - c;
    return c - b;
}
double dis(Point p, Line l)
{
    double dis;
    if(VERTICAL(l))
    {
        dis = inside(l.a.y, l.b.y, p.y);

        return sqrt(pow(dis, 2) +pow(l.a.x - p.x, 2));
    }
    else
    {
        dis = inside(l.a.x, l.b.x, p.x);

        return sqrt(pow(dis, 2) + pow(l.a.y - p.y, 2));
    }
    return 0.0;
}
double cal(Point p)
{
    double ret = 0.0;
    for(int i = 0;i < m;i++)
        ret += dis(p, lines[i]);
    return ret;
}
#define INF 10000000.0
double ret = INF, retx, rety;

#define eps 0.001
void tricut(double y)
{
    double xl = 0.0, xh = 100.0;

    while(xl + eps < xh)
    {
        double lmid = (xl + xh) / 2;
        double rmid = (lmid + xh) / 2;

        if(cal(Point(lmid, y)) < cal(Point(rmid, y)))
            xh = rmid;
        else
            xl = lmid;
    }
    double ret_tmp = cal(Point(xl, y));
    if(ret_tmp < ret)
    {
        ret = ret_tmp;
        retx = xl;
        rety = y;
    }
}
int main()
{
#ifdef HOME
    freopen("fence3.in", "r", stdin);
    freopen("fence3.out", "w", stdout);
#endif
    scanf("%d", &m);
    for(int i  =0;i < m;i++)
    {
        scanf("%lf %lf %lf %lf", &lines[i].a.x, &lines[i].a.y, &lines[i].b.x, &lines[i].b.y);
    }
    for(double y = 0; y <= 100; y += 0.1)
    {
        tricut(y);
    }
    printf("%.1lf %.1lf %.1lf\n", retx, rety, ret);

    return 0;
}

