
/*
ID: wengsht1
LANG: C++
TASK: nuggets
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
int bug[11];

const int inf = 2000000000;
const int infcnt = 100000;
int main()
{
#ifdef HOME
    freopen("nuggets.in", "r", stdin);
    freopen("nuggets.out", "w", stdout);
#endif
    queue<int> q;
    set<int> s;

    scanf("%d", &N);
    for(int i = 0;i < N;i++) scanf("%d", bug+i);

    sort(bug, bug+N);

    if(bug[0] == 1)
    {
        cout<<0<<endl;

        return 0;
    }
    int ret = bug[0] - 1;
    for(int i = -bug[N-1] + 1; i < bug[0];i++)
    {
        if(!i) continue;
        q.push(i);
        s.insert(i);
    }
    int cnt = 0;

    while(!q.empty() && cnt < infcnt)
    {
        int top = q.front();
        q.pop();
        s.erase(top);

        int test = top + bug[N-1];


        bool ok = false;
        for(int i = 0;i < N-1;i++)
        {
            if(!s.count(test-bug[i]))
            {
                ok = true;

                break;
            }
        }
        if(!ok)
        {
            if(test > ret) ret = test;
            if(test > inf) break;
            q.push(test);
            s.insert(test);
            cnt++;
        }
    }
    if(ret > inf || cnt >= infcnt) cout<<"0"<<endl;
    else cout<<ret<<endl;

    return 0;
}

