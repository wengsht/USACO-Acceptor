/*
ID: wengsht1
LANG: C++
TASK: ride
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

int cal(string a)
{
    int ret = 1;
    for(int i = 0;i < a.length();i++)
    {
        ret = ret * ( a[i] - 'A' + 1) % 47;
    }
    return ret;
}
int main()
{
#ifdef HOME
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
#endif

    string a, b;

    while(cin>>a>>b)
    {
        int ra = 0, rb = 0;

        ra = cal(a);
        rb = cal(b);

        if(ra == rb)
            cout<<"GO"<<endl;
        else
            cout<<"STAY"<<endl;
    }

    return 0;
}

