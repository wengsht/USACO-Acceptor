/*
ID: wengsht1
LANG: C++
TASK: frac1
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

struct Node
{
    int a, b;
}node[160*161];

int gcd(int a, int b)
{
    return (b ? gcd(b, a%b) : a);
}
bool _cmp(Node a, Node b)
{
    return ((double)a.a / a.b < (double)b.a / b.b);
}

int m;
int main()
{
#ifdef HOME
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
#endif
    cin>>N;

    node[m].a = 0;
    node[m++].b = 1;
    node[m].a = 1;
    node[m++].b = 1;

    for(int i = 2;i <= N;i++)
    {
        for(int j = 1;j < i;j++)
        {
            if(gcd(i, j) == 1)
            {
                node[m].a = j;
                node[m++].b = i;
            }
        }
    }
    sort(node, node+m, _cmp);
    for(int i = 0;i < m;i++)
        printf("%d/%d\n", node[i].a, node[i].b);
    return 0;
}

