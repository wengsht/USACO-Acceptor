
/*
ID: wengsht1
LANG: C++
TASK: sort3
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
int input[1001], cnt[4];
int ctmp[4][4];

int main()
{
#ifdef HOME
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
#endif

    cin>>N;
    for(int i = 0;i < N;i++)
    {
        cin>>input[i];

        cnt[input[i]] ++;
    }

    int k = 0;
    for(int i = 1;i <= 3;i++)
    {
        for(int j = 0;j < cnt[i];j++)
            ctmp[i][input[k++]]++;
    }

    int ret = 0;
    int mn = min(ctmp[1][2], ctmp[2][1]);
    ret += mn;
    ctmp[1][2] -= mn;
    ctmp[1][1] += mn;
    ctmp[2][1] -= mn;
    ctmp[2][2] += mn;

    mn = min(ctmp[1][3], ctmp[3][1]);
    ret += mn;
    ctmp[1][3] -= mn;
    ctmp[1][1] += mn;
    ctmp[3][1] -= mn;
    ctmp[3][3] += mn;

    mn = min(ctmp[2][3], ctmp[3][2]);
    ret += mn;
    ctmp[2][3] -= mn;
    ctmp[3][2] -= mn;
    ctmp[2][2] += mn;
    ctmp[3][3] += mn;

    int rm = max(ctmp[1][2], ctmp[1][3]);
    ret += rm * 2;

    cout<<ret<<endl;





    return 0;
}

