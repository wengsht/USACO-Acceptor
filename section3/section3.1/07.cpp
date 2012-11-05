
/*
ID: wengsht1
LANG: C++
TASK: stamps
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
#define inf 2000000
int N, M, K;

int v[51];


int main()
{
unsigned char good[2000001];
memset(good, -1, sizeof(good));
#ifdef HOME
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);
#endif
    scanf("%d %d", &N, &K);

    for(int i = 0;i < K;i++)
        scanf("%d", v+i);

    sort(v, v+K);

    int ret;
    good[0] = 1;
    for(ret = 1; ;ret++)
    {
        for(int i = 0;i < K;i++)
        {
            if(ret - v[i] < 0) break;

            if(good[ret] > good[ret - v[i]] + 1) good[ret] = good[ret - v[i]] + 1;
        }
        if(good[ret] > N+1) break;
    }
    ret --;

    cout<<ret<<endl;

    return 0;
}

