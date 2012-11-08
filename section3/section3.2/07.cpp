
/*
ID: wengsht1
LANG: C++
TASK: butter
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
#define inf 225000000
int N, P, C;
int a, b, c;

int head[3000], v[3000], w[3000], nxt[3000];
int m;

int ret = inf;

int cows[801];

void addw(int a, int b, int c)
{
    w[m] = c;
    v[m] = b;
    nxt[m] = head[a];
    head[a] = m++;
}

typedef pair<int, int> Pair;
void dijkstra(int st)
{
    priority_queue< Pair, vector<Pair>, greater<Pair> > q;

    q.push(make_pair(0, st));
    int tmp = 0;
    int len[801];
    memset(len, 0x7f, sizeof(len));

    int cnt = 0;
    while(!q.empty() && cnt < N)
    {
        Pair top = q.top();
        q.pop();

        int l = top.first, u = top.second;

        if(l > len[u]) continue;

        len[u] = l;
        cnt += cows[u];

        tmp += len[u] * cows[u];

        if(tmp >= ret) return ;

        for(int i = head[u]; i != -1;i = nxt[i])
        {
            int nxtv = v[i];

            int nxtl = len[u] + w[i];

            if(len[nxtv] > nxtl)
            {
                len[nxtv] = nxtl;

                q.push(make_pair(nxtl, nxtv));
            }
        }
    }
    if(cnt == N && tmp < ret) ret = tmp;
}
int main()
{
#ifdef HOME
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);
#endif
    memset(head, -1, sizeof(head));
    scanf("%d %d %d", &N, &P, &C);
    for(int i = 0;i < N;i++)
    {
        scanf("%d", &a);

        cows[a] ++;
    }
    for(int i = 0;i < C;i++)
    {
        scanf("%d %d %d", &a, &b, &c);

        addw(a, b, c);
        addw(b, a, c);
    }
    for(int i = 1;i <= P;i++) dijkstra(i);

    cout<<ret<<endl;

    return 0;
}

