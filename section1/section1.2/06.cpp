
/*
ID: wengsht1
LANG: C++
TASK: dualpal
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

bool good(char *s)
{
    int len = strlen(s);

    for(int i = 0;i < len;i++)
    {
        if(s[i] != s[len-i-1]) return false;
    }
    return true;
}
void itoa(int m, char *out, int n)
{
    char tmp[101];
    int size = 0;
    while(m)
    {
        tmp[size++] = '0' + m%n;

        m /= n;
    }
    out[size] = '\0';
    for(int i = size-1;i >= 0;i--)
        out[size-i-1] = tmp[i];
    out[size] = '\0';
}
int main()
{
#ifdef HOME
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
#endif
    cin>>N>>K;
    char tmp[1000];

    for(K++;N;K++)
    {
        int cnt = 0;
        for(int i = 2;cnt <  2 && i <= 10;i++)
        {
            itoa(K, tmp, i);

            if(good(tmp)) cnt++;
        }
        if(cnt >= 2)
        {
            cout<<K<<endl;
            N--;
        }
        
    }

    return 0;
}

