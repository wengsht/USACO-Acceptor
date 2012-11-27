
/*
ID: wengsht1
LANG: C++
TASK: milk6
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
#define INF 0x7fffffff
using namespace std;

int n,m,s,t;  //s t 开始结束
long long c[MX][MX],   //容量
    pf[MX],      //增流
	f[MX][MX],   //流量
    pre[MX];     //前节点
long long max_flow;
int ret[1001];
int retm;

int mmm;
struct Edge
{
    int a, b;
    long long e;
}edge[1001];
void F_F(int n)
{
	queue<long long> q;
	memset( f,0,sizeof( f ) );
	max_flow = 0;
    s = 1;
    t = N;
	while( true )
	{
		memset( pf,0,sizeof( pf ) );
		pf[s] = INF;
		q.push( s );

		while( !q.empty() )
		{
			long long now = q.front(); 
			q.pop();
			for( long long i = 1;i <= n;i++ )
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

		for( long long i = t;i != s;i = pre[i] )
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
    freopen("milk6.in", "r", stdin);
    freopen("milk6.out", "w", stdout);
#endif
    scanf("%d %d", &N, &M);
    long long a, b, cc;
    for(int i = 0;i < M;i++)
    {
        cin>>a>>b>>cc;
        cc = 1001 * cc + 1;

        c[a][b] += cc;
        edge[mmm].a = a;
        edge[mmm].b = b;
        edge[mmm++].e = cc;
    }
    F_F(N);
    cout<<max_flow/1001<<" "<<max_flow%1001<<endl;
    
    long long tmp = max_flow;
    for(int i = 0;i < M;i++)
    {
        c[edge[i].a][edge[i].b] -= edge[i].e;

        F_F(N);

        if(tmp == max_flow + edge[i].e)
        {
            ret[retm++] = i+1;
            tmp -= edge[i].e;
        }
        else
            c[edge[i].a][edge[i].b] += edge[i].e;
    }
    for(int i = 0;i < retm;i++)
        cout<<ret[i]<<endl;
   
    return 0;
}

