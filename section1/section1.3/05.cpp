
/*
ID: wengsht1
LANG: C++
TASK: crypt1
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
int num[10];

int tmp[5];
int had[10];
int ret;

bool good(int m)
{
    int ret = 0;
    while(m)
    {
        if(!had[m%10]) return false;

        m /= 10;
        ret++;
    }
    if(ret > 3) return false;
    return true;
}
bool good1(int m)
{
    int ret = 0;
    while(m)
    {
        if(!had[m%10]) return false;

        m /= 10;
        ret++;
    }
    if(ret > 4) return false;
    return true;
}
bool test()
{
    int a = tmp[0]*100 + tmp[1]*10 + tmp[2];
    int b = tmp[3];
    int c = tmp[4];
    int d = b*10 + c;

    return good(a*b) && good(a*c) && good1(a*d);
}
void dfs(int h)
{
    if(h == 5)
    {
        if(test()) ret++;

        return ;
    }

    for(int i = 0;i < N;i++)
    {
        tmp[h] = num[i];
        dfs(h+1);
    }
}

int main()
{
#ifdef HOME
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
#endif
    cin>>N;

    for(int i = 0;i < N;i++) 
    {
        cin>>num[i];
        had[num[i]] = true;
    }

    dfs(0);

    cout<<ret<<endl;

    return 0;
}

