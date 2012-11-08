
/*
ID: wengsht1
LANG: C++
TASK: ratios
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

struct Mix
{
    int a, b, c;
}mix[3], ret;

int test(int i, int j, int k)
{
    int aa = mix[0].a * i + mix[1].a * j + mix[2].a * k;
    int bb = mix[0].b * i + mix[1].b * j + mix[2].b * k;
    int cc = mix[0].c * i + mix[1].c * j + mix[2].c * k;

    int a = ret.a, b = ret.b, c = ret.c;
    if(a == 0 && aa != 0 || b == 0 && bb != 0 || c == 0 && cc != 0) return -1;

    int r = -2;

    if(a != 0)
    {
        if(aa % a != 0) return -1;

        r = aa / a;
    }
    if(b != 0)
    {
        if(bb % b != 0) return -1;

        int tmp = bb / b;

        if(r != -2 && r != tmp) return -1;

        r = tmp;
    }
    if(c != 0)
    {
        if(cc % c != 0) return -1;

        int tmp = cc / c;
        if(r != -2 && r != tmp) return -1;

        r = tmp;
    }

    return r;
}
int main()
{
#ifdef HOME
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);
#endif
    scanf("%d %d %d", &ret.a, &ret.b, &ret.c);
    for(int i = 0;i < 3;i++)
        scanf("%d %d %d", &mix[i].a, &mix[i].b, &mix[i].c);

    bool ok = false;
    int ret = 0;
    for(int l = 1;l <= 300 && !ok;l++)
    {
        int mx = min(l, 100);
        for(int i = 0;i <= mx && !ok;i++)
        {
            int rem = l - i;
            int mxj = min(rem, 100);
            for(int j = 0;j <= mxj && !ok;j++)
            {
                rem = l - i - j;

                if(rem > 100) continue;

                ret = test(i, j, rem);
                if(ret >= 0)
                {
                    ok = true;

                    cout<<i<<" "<<j<<" "<<rem<<" "<<ret<<endl;

                    break;
                }
            }

        }
    }
    if(!ok) cout<<"NONE"<<endl;

    return 0;
}

