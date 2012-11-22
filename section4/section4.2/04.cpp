
/*
ID: wengsht1
LANG: C++
TASK: job
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
int N, M, K, A, B;

int a[31], b[31];
int jobs[MX];
int m;

typedef pair<int, int> Pair; 
bool good_ans(int t)
{
    priority_queue< Pair, vector<Pair>, less<Pair> > q;
    for(int i = 0;i < B;i++)
        q.push(make_pair(t-b[i], i));
    for(int i = N-1;i >= 0;i--)
    {
        Pair top = q.top();
        q.pop();

        if((top.first) >= jobs[i])
        {
            top.first -= b[top.second];
            q.push(top);
        }
        else return false;
    }
    return true;
}
int go(int l, int h)
{
    int ret = h;

    while(l <= h)
    {
        int mid = l + (h-l) / 2;

        if(good_ans(mid))
        {
            ret = mid;

            h = mid - 1;
        }
        else 
            l = mid + 1;
    }

    return ret;
}
int main()
{
#ifdef HOME
    freopen("job.in", "r", stdin);
    freopen("job.out", "w", stdout);
#endif
    scanf("%d %d %d", &N, &A, &B);

    for(int i = 0;i < A;i++)
    {
        scanf("%d", a+i);
        for(int j = 1;j <= N;j++)
            jobs[m++] = a[i] * j;
    }
    for(int i = 0;i < B;i++)
        scanf("%d", b+i);

    sort(jobs, jobs+m);

    printf("%d ", jobs[N-1]);

    int ret = go(jobs[N-1] + 1, 40000);

    printf("%d\n", ret);

    return 0;
}

