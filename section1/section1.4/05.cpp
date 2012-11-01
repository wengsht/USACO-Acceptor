
/*
ID: wengsht1
LANG: C++
TASK: milk3
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
int a, b, c;
bool good[21*21*21];
int ret[21];
bool hasret[21];
int m;

inline int f(int a, int b, int c)
{
    return a * 21 * 21 + b * 21 + c;
}
int main()
{
#ifdef HOME
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
#endif
    cin>>a>>b>>c;

    ret[m++] = c;
    hasret[c] = true;
    good[c] = true;
    queue<int> q;
    q.push(c);

    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        int tc = top % 21; top /= 21;
        int tb = top % 21; top /= 21;
        int ta = top;

        int topo = 0;
        topo = min(ta, b - tb);
        int nxt = f(ta - topo, tb + topo, tc);

        if(!good[nxt])
        {
            good[nxt] = true;

            q.push(nxt);
        }
        topo = min(ta, c - tc);
        if(!hasret[tc+topo] && ta - topo == 0) 
        {
            ret[m++] = tc+topo;
            hasret[tc+topo] = true;
        }
        nxt = f(ta - topo, tb, tc + topo);

        if(!good[nxt])
        {
            good[nxt] = true;

            q.push(nxt);
        }
        topo = min(tb, a - ta);
        nxt = f(ta + topo, tb - topo, tc);

        if(!good[nxt])
        {
            good[nxt] = true;

            q.push(nxt);
        }
        topo = min(tb, c - tc);
        if(!hasret[tc+topo] && ta == 0) 
        {
            ret[m++] = tc+topo;
            hasret[tc+topo] = true;
        }
        nxt = f(ta, tb - topo, tc + topo);

        if(!good[nxt])
        {
            good[nxt] = true;

            q.push(nxt);
        }
        topo = min(tc, a - ta);
        if(!hasret[tc-topo] && ta + topo == 0) 
        {
            ret[m++] = tc-topo;
            hasret[tc-topo] = true;
        }
        
        nxt = f(ta + topo, tb, tc - topo);

        if(!good[nxt])
        {
            good[nxt] = true;

            q.push(nxt);
        }
        topo = min(tc, b - tb);
        if(!hasret[tc-topo] && ta == 0) 
        {
            ret[m++] = tc-topo;
            hasret[tc-topo] = true;
        }
        nxt = f(ta, tb + topo, tc - topo);

        if(!good[nxt])
        {
            good[nxt] = true;

            q.push(nxt);
        }


    }
    sort(ret, ret+m);

    cout<<ret[0];
    for(int i = 1;i < m;i++) cout<<" "<<ret[i]; cout<<endl;





    return 0;
}

