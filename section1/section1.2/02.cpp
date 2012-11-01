
/*
ID: wengsht1
LANG: C++
TASK: milk2
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


#define MX 10000

typedef struct 
{
    int a, b;
}Node;
int N, M, K;
Node node[MX];

bool _cmp(Node a, Node b)
{
    if(a.a != b.a) return a.a < b.a;
    return a.b < b.b;
}
int main()
{
#ifdef HOME
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
#endif
    scanf("%d", &N);
    for(int i = 0;i < N;i++) scanf("%d %d", &node[i].a, &node[i].b);
    
    sort(node, node+N, _cmp);

    int ret1 = 0, ret2 = 0;

    int st = node[0].a, ed = node[0].b;

    ret1 = ed- st;

    for(int i = 1;i < N;i++)
    {
        if(ed >= node[i].a)
            ed = max(node[i].b, ed);
        else
        {
            int r = ed - st;
            if(r > ret1) ret1 = r;
            r = node[i].a - ed;
            if(r > ret2) ret2 = r;

            ed = node[i].b;
            st = node[i].a;
        }
    }

    cout<<ret1<<" "<<ret2<<endl;

    return 0;
}

