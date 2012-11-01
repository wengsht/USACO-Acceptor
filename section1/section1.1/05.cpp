/*
ID: wengsht1
LANG: C++
TASK: gift1
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <set>
using namespace std;

#define HOME 

#define MX 100000
int N, M, K;
int a, b;

map<string, int> _index;
int ret[101];
string st, names[101];
int main()
{
#ifdef HOME
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
#endif

    cin>>N;
    for(int i = 0;i < N;i++)
    {
        cin>>st;
        names[i] = st;
        _index[st] = i;
    }
    for(int i = 0;i < N;i++)
    {
        cin>>st;
        cin>>a>>b;
        if(b == 0) continue;

        int c = a / b;
        int d = a - c * b;
        ret[_index[st]] -= (a-d);
        for(int j = 0;j < b;j++)
        {
            cin>>st;
            ret[_index[st]] += c;
        }
    }
    for(int i = 0;i < N;i++)
        cout<<names[i]<<" "<<ret[i]<<endl;

    return 0;
}

