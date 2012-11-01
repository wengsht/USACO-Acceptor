
/*
ID: wengsht1
LANG: C++
TASK: comehome
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

int mp[256];
int w[55][55];

typedef pair<int,int> Pair;

void dijkstra()
{
    priority_queue< Pair,vector<Pair>,greater<Pair> > q;

    for(int i = 0;i < 51;i++)
    {
        if(w[51][i] < 10000) 
            q.push(make_pair(w[51][i], i));
    }

    while(!q.empty())
    {
        Pair top = q.top();

        q.pop();
        int d = top.first, p = top.second;

        if(w[51][p] < d) continue;

        if(p >= 26 && p != 51)
        {
            char ret = 'A' + p-26;
            cout<<ret<<" "<<w[51][p]<<endl;
            break;
        }

        for(int i = 0;i < 52;i++)
        {
            if(w[51][i] > w[51][p] + w[p][i]) 
            {
                w[51][i] = w[51][p] + w[p][i];

                q.push(make_pair(w[51][i], i));
            }
        }

    }
}
int main()
{
#ifdef HOME
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);
#endif

    int m;
    for(int i = 'a';i <= 'z';i++) mp[i] = m++;
    for(int i = 'A';i <= 'Z';i++) mp[i] = m++;

    for(int i = 0;i < 52;i++)
    {
        w[i][i] = 0;
        for(int j = i+1;j < 52;j++)
            w[i][j] = w[j][i] = 100000;
    }

    scanf("%d", &N);

    char stc, edc;
    int st, ed;
    int p;
    for(int i = 0;i < N;i++)
    {
        cin>>stc>>edc>>p;
        st = stc;
        ed = edc;

        if(w[mp[st]][mp[ed]] > p)
            w[mp[ed]][mp[st]]=w[mp[st]][mp[ed]] = p;
    }
    dijkstra();

    return 0;
}

