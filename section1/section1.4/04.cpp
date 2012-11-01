
/*
ID: wengsht1
LANG: C++
TASK: ariprog
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

int bound[251*250];
bool has[251*251+251*251];
int m;

void _init()
{
    for(int i = 0;i <= M;i++)
    {
        for(int j = i;j <= M;j++)
        {
            int p = i*i + j*j;
            if(!has[p])
            {
                has[p] = true;

                bound[m++] = p;
            }
        }
    }
    sort(bound, bound+m);
}

struct Node
{
    int a, d;
}node[10001];

int _count;

bool _cmp(Node a, Node b)
{
    if(a.d != b.d) return a.d < b.d;
    return a.a < b.a;
}
int main()
{
#ifdef HOME
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
#endif
    cin>>N>>M;

    _init();

    int mx = M*M*2;

    for(int i = 0;i < m;i++)
    {
        for(int j = i+1;j < m;j++)
        {
            int d = bound[j] - bound[i];

            int cnt = 1;

            int k = 1;
            while(cnt < N)
            {
                if(bound[i] + d*k > mx || !has[bound[i] + d*k])
                    break;
                else 
                    cnt++;

                k++;
            }
            if(cnt >= N)
            {
                node[_count].a = bound[i];
                node[_count++].d = d;
            }
        }
    }
    sort(node, node+_count, _cmp);
    if(_count == 0)
        cout<<"NONE"<<endl;
    else
    {
        for(int i = 0;i < _count;i++)
            cout<<node[i].a<<" "<<node[i].d<<endl;
    }
    
    return 0;
}

