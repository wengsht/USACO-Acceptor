
/*
ID: wengsht1
LANG: C++
TASK: pprime
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

int a, b;
int N, M, K;

int ret[100000];
int m;

bool isprime(int l)
{
    if(l <= 1) return false;
    int k = sqrt((double)l);

    for(int i = 2;i <= k;i++)
    {
        if(l % i == 0) return false;
    }
    return true;
}
int get(int l)
{
    int n = l;
    while(n)
    {
        l = l * 10 + n % 10;
        n /= 10;
    }
    return l;
}
int get2(int l, int k)
{
    int n = l;
    l = l * 10 + k;

    while(n)
    {
        l = l * 10 + n % 10;

        n /= 10;
    }
    return l;
}
int main()
{
#ifdef HOME
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
#endif

    cin>>a>>b;
    for(int i = 0;i <= 999;i++)
    {
        int j = get(i);

        if(isprime(j)) ret[m++] = j;

        for(int k = 0;k <= 9;k++)
        {
            j = get2(i, k);

            if(isprime(j)) ret[m++] = j;
        }
    }
    for(int i = 1000;i <= 9999;i++)
    {
        int j = get(i);
        if(isprime(j)) ret[m++] = j;
    }
    int st = 0;;
    while(st < m && ret[st] < a) st++;

    for(int i = st;i < m;i++)
    {
        if(ret[i] > b) break;
        cout<<ret[i]<<endl;
    }
    

    return 0;
}

