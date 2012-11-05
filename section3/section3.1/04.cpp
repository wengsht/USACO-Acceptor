
/*
ID: wengsht1
LANG: C++
TASK: humble
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
int factors[101];
int position[101];
int ret, door;

const int inf = 0x7fffffff;

int nums[MX+5];
int m = 0;

typedef pair<int, int> Pair;
int main()
{
#ifdef HOME
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);
#endif
    scanf("%d %d", &N, &M);

    for(int i = 0;i < N;i++) 
    {
        scanf("%d", factors+i);

        position[i] = 0;
    }
    sort(factors, factors+N);

    nums[m++] = 1;

    priority_queue< Pair,vector<Pair>,greater<Pair> > q;

    for(int i = 0;i < N;i++)
        q.push(make_pair(factors[i] * 1, i));

    while(!q.empty() && m <= M)
    {
        Pair top = q.top();
        q.pop();
        position[top.second]++;
        if(nums[m-1] != top.first) nums[m++] = top.first;
        q.push(make_pair(nums[position[top.second]] * factors[top.second], top.second));
    }
    cout<<nums[m-1]<<endl;

    return 0;
}

