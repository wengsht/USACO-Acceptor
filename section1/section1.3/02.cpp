
/*
ID: wengsht1
LANG: C++
TASK: milk
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
    int p, cnt;
}node[5001];

bool _cmp(Node a, Node b)
{
    return a.p < b.p;
}
int main()
{
#ifdef HOME
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
#endif
    scanf("%d %d", &N, &M);
    for(int i = 0;i < M;i++)
        scanf("%d %d", &node[i].p, &node[i].cnt);

    sort(node, node+M, _cmp);

    int ret = 0;

    for(int i = 0;i < M && N!= 0;i++)
    {
        if(N <= node[i].cnt)
        {
            ret += N * node[i].p;
            
            break;
        }
        ret += node[i].p * node[i].cnt;

        N -= node[i].cnt;
    }
    
    cout<<ret<<endl;
    return 0;
}

