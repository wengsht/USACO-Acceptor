
/*
ID: wengsht1
LANG: C++
TASK: fact4
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

int main()
{
#ifdef HOME
    freopen("fact4.in", "r", stdin);
    freopen("fact4.out", "w", stdout);
#endif
    cin>>N;

    int ret = 1;

    for(int i = 1;i <= N;i++)
    {
        ret = ret * i;
        while(ret % 10 == 0) ret /= 10;
        ret %= 1000;
    }
    while(ret % 10 == 0) ret /= 10;
    cout<<ret%10<<endl;

    return 0;
}

