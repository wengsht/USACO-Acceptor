/*
ID: wengsht1
LANG: C++
TASK: clocks
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

string op[] = { "ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI" };
int    len[] = {4, 3, 4, 3, 5, 3, 4, 3, 4 };
#define MX 100000
int N, M, K;
int mm;
int ret[100];

bool same(int s[3][3], int b[3][3])
{
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            if(s[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

int main()
{
#ifdef HOME
    freopen("clocks.in", "r", stdin);
    freopen("clocks.out", "w", stdout);
#endif

    int st[3][3], ed[3][3];
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            cin>>st[i][j];

            st[i][j] /= 3;
            st[i][j] -= 1;

            ed[i][j] = 3;
        }
    }

    int mx = 1;
    for(int i = 1;i <= 9;i++) mx *= 4;

    for(int l = 0;l < mx;l++)
    {
        int tmp[3][3];
        for(int k = 0;k < 3;k++)
            for(int j = 0;j < 3;j++)
                tmp[j][k] = st[j][k];

        int p = 0, n = l;
        for(int i = 0;i < 9;i++, p++)
        {
            int m = n % 4;
            n /= 4;

            for(int j = 0;j < m;j++)
            {
                for(int k = 0;k < len[p];k++)
                {
                    int o = op[p][k] - 'A';
                    tmp[o/3][o%3] = (tmp[o/3][o%3] + 1) % 4;
                }

            }
        }
        if(same(tmp, ed))
        {
            mm = 0;

            for(int i = 0;i < 9;i++)
            {
                int m = l % 4;
                l /= 4;
                for(int j = 0;j < m;j++) ret[mm++] = i+1;
            }

            break;
        }

    }
    if(mm > 0)
        cout<<ret[0];
    for(int i = 1;i < mm;i++) cout<<" "<<ret[i];
    cout<<endl;

    return 0;
}

