
/*
ID: wengsht1
LANG: C++
TASK: ditch
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

int N, M, K;

#define MX 201
#define INF 200000000
using namespace std;

int n,m,s,t;  //s t 开始结束
int c[MX][MX],   //容量
    pf[MX],      //增流
	f[MX][MX],   //流量
    pre[MX];     //前节点
int max_flow;
void F_F()
{
	queue<int> q;
	memset( f,0,sizeof( f ) );
	max_flow = 0;
	while( true )
	{
		memset( pf,0,sizeof( pf ) );
		pf[s] = INF;
		q.push( s );

		while( !q.empty() )
		{
			int now = q.front(); 
			q.pop();
			for( int i = 1;i <= n;i++ )
			{
				if( pf[i] == 0 && c[now][i] > f[now][i] )
				{
					pre[i] = now;
					pf[i] = min( c[now][i]-f[now][i],pf[now] );
					q.push( i );
				}
			}
		}
		if( pf[t] == 0 ) break;

		for( int i = t;i != s;i = pre[i] )
		{
			f[pre[i]][i] += pf[t];
			f[i][pre[i]] -= pf[t];
		}
		max_flow += pf[t];
	}
}
int main()
{
#ifdef HOME
    freopen("ditch.in", "r", stdin);
    freopen("ditch.out", "w", stdout);
#endif
    cin>>N>>n;
    int a, d, b;

    for(int i = 0;i < N;i++)
    {
        cin>>a>>b>>d;

        c[a][b] += d;
    }
    s = 1; t = n;
    F_F();
    cout<<max_flow<<endl;

    return 0;
}

