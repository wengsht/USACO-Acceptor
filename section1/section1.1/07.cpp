/*
ID: wengsht1
LANG: C++
TASK: beads
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
string str;
int len;
int dpl[100000][2];
int dpr[100000][2];

int main()
{
#ifdef HOME
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
#endif
    cin>>N;
    cin>>str;

    len = str.length();

    bool b = true, r = true, w = true;

    for(int i = 0;(b || r) && (i != 0 || w);i = (i-1+len)%len)
    {
        w = false;
        if(str[i] == 'b')
        {
            r = false;
            if(b) dpl[0][0]++;
        }
        else if(str[i] == 'r')
        {
            b = false;
            if(r) dpl[0][1]++;
        }
        else
        {
            if(r) dpl[0][1]++;
            if(b) dpl[0][1]++;
        }
    }
    b = r = w = true;
    for(int i = len-1;(b || r) && (i != len-1 || w); i = (i+1) % len)
    {
        w = false;
        if(str[i] == 'b')
        {
            r = false;
            if(b) dpr[len-1][0]++;
        }
        else if(str[i] == 'r')
        {
            b = false;
            if(r) dpr[len-1][1]++;
        }
        else
        {
            if(r) dpr[len-1][1]++;
            if(b) dpr[len-1][0]++;
        }
    }
    for(int i = 1;i < len;i++)
    {
        if(str[i] == 'b')
        {
            dpl[i][0] = dpl[i-1][0] + 1;
            dpl[i][1] = 0;
        }
        else if(str[i] == 'r')
        {
            dpl[i][1] = dpl[i-1][1] + 1;
            dpl[i][0] = 0;
        }
        else
        {
            dpl[i][1] = dpl[i-1][1] + 1;
            dpl[i][0] = dpl[i-1][0] + 1;

        }
    }
    for(int i = len-2;i >= 0;i--)
    {
        if(str[i] == 'b')
        {
            dpr[i][0] = dpr[i+1][0] + 1;
            dpr[i][1] = 0;
        }
        else if(str[i] == 'r')
        {
            dpr[i][1] = dpr[i+1][1] + 1;
            dpr[i][0] = 0;
        }
        else
        {
            dpr[i][1] = dpr[i+1][1] + 1;
            dpr[i][0] = dpr[i+1][0] + 1;
        }
    }

    int ret = 0, tmp;
    for(int i = 0;i < len-1;i++)
    {
        tmp = max(dpl[i][0], dpl[i][1]) + max(dpr[i+1][0], dpr[i+1][1]);

        if(ret < tmp) ret = tmp;
    }
    tmp = max(dpl[len-1][0], dpl[len-1][1]) + max(dpr[0][0], dpr[0][1]);
    if(ret < tmp) ret = tmp;

    if(ret > len) ret = len;

    cout<<ret<<endl;
    return 0;
}

