
/*
ID: wengsht1
LANG: C++
TASK: fc
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

#define MX 10005
int N, M, K;

struct Point
{
    double x, y;
}point[MX], res[MX];
bool _cmpy(Point a, Point b)
{
    if(a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}
bool left(Point a, Point b, Point c)
{
    return (a.x - c.x)*(b.y - c.y) >= (b.x - c.x) * (a.y - c.y);
}
int convex(Point *points, int n, Point *res)
{
    sort(points, points+n, _cmpy);
    if(n <= 2)
    {
        for(int i = 0;i < n;i++) res[i] = points[i];

        return n;
    }

    int top = 1;
    for(int i = 0;i < 3;i++) res[i] = points[i];
    for(int i = 2;i < n;++i)
    {
        while(top && left(points[i], res[top], res[top-1]))
            top--;
        res[++top] = points[i];
    }

    int len = top;
    res[++top] = points[n-2];
    for(int i = n-3;i >= 0;i--)
    {
        while(top != len && left(points[i], res[top], res[top-1]))
            top--;
        res[++top] = points[i];
    }
    return top;
}
double dis(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main()
{
#ifdef HOME
    freopen("fc.in", "r", stdin);
    freopen("fc.out", "w", stdout);
#endif
    scanf("%d", &N);
    for(int i = 0;i < N;i++)
        scanf("%lf %lf", &point[i].x, &point[i].y);

    M = convex(point, N, res);
    double ret = 0;
    for(int i = 0;i < M;i++)
    {
        int j = (i+1) % M;

        ret += dis(res[i], res[j]);
    }
    printf("%.2lf\n", ret);

    return 0;
}

