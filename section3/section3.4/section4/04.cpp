
/*
ID: wengsht1
LANG: C++
TASK: fence9
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
long long n, m, p;

int main()
{
#ifdef HOME
    freopen("fence9.in", "r", stdin);
    freopen("fence9.out", "w", stdout);
#endif
    scanf("%lld %lld %lld", &n, &m, &p);

    long long ret = 0;

    if(n <= p)
    {
        if(n != 0)
        {
            for(long long i = 1;i < n;i++)
            {
                ret += i * m / n;

                if(i*m % n == 0) 
                {
                    ret--;
                }
            }
        }
        if(n != 0 && n != p)
            ret += m-1;
        if(p > n)
        {
            for(long long i = p-1;i > n;i--)
            {
                ret += (p-i) * m / (p-n);

                if((p-i) * m % (p-n) == 0) ret--;
            }
        }
    }
    else
    {
        for(long long i = 0;i <= p;i++)
        {
            ret += i * m / n;

            if(i && i*m % n == 0) ret--;
        }
        for(long long i = p+1;i < n;i++)
        {
            ret += i * m / n - (i-p) * m / (n-p);

            if(i * m % n == 0) ret--;
        }


    }
    cout<<ret<<endl;


    return 0;
}

