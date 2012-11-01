
/*
ID: wengsht1
LANG: C++
TASK: preface
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

char op[] = "IVXLCDM";
int ret[7];
int  _index[10001];

void go(int n)
{
    if(n >= 1000)
    {
        ret[6] += n / 1000;
        n %= 1000;
    }
    for(int i = 100;i > 0;i /= 10)
    {
        if(n >= i)
        {
            if(n / i == 9)
            {
                ret[_index[i*10]] ++;
                ret[_index[i]]++;

                n %= i;
            }
            else if(n/i >= 5)
            {
                ret[_index[i*5]] ++;

                n -= i*5;
                i *= 10;
            }
            else if(n / i == 4)
            {
                ret[_index[i*5]]++;

                ret[_index[i]]++;

                n %= i;
            }
            else
            {
                ret[_index[i]] += n / i;

                n %= i;
            }
        }
    }
}
int main()
{
#ifdef HOME
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
#endif

    _index[1] = 0; _index[5] = 1; _index[10] = 2; _index[50] = 3;
    _index[100] = 4; _index[500] = 5; _index[1000] = 6;
    cin>>N;
    for(int i = 1;i <= N;i++)
        go(i);

    for(int i = 0;i < 7;i++)
        if(ret[i])
            cout<<op[i]<<" "<<ret[i]<<endl;

    return 0;
}

