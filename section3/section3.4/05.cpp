
/*
ID: wengsht1
LANG: C++
TASK: rockers
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
int N, T, M;

int songs[21];
struct Node
{
    int used_disk, left_time;
}dp[40];

void add(Node &ret, Node d, int t)
{
    int left = d.left_time;
    if(t <= left)
    {
        ret.used_disk = d.used_disk;

        ret.left_time = d.left_time - t;
    }
    else if(t <= T)
    {
        ret.used_disk = d.used_disk + 1;

        ret.left_time = T - t;
    }
    else 
    {
        ret.used_disk = 21;
    }
}
bool _less(const Node a,const Node b)
{
    if(a.used_disk != b.used_disk) return a.used_disk < b.used_disk;

    return a.left_time > b.left_time;
}
int main()
{
#ifdef HOME
    freopen("rockers.in", "r", stdin);
    freopen("rockers.out", "w", stdout);
#endif
    scanf("%d %d %d", &N, &T, &M);

    for(int i = 1;i <= N;i++) scanf("%d", songs+i);

    memset(dp, 0, sizeof(dp));

    for(int i = 1;i <= N;i++)
    {
        for(int j = i;j >= 1;j--)
        {
            Node ret;
            add(ret, dp[j-1], songs[i]);

            if(dp[j].used_disk == 0 || _less(ret, dp[j]))
            {
                dp[j].used_disk = ret.used_disk;
                dp[j].left_time = ret.left_time;
            }
        }
    }
    int i;
    for(i = N;i >= 1;i--)
    {
        if(dp[i].used_disk <= M) break;
    }
    cout<<i<<endl;

    return 0;
}

