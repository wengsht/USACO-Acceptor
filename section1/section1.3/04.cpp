
/*
ID: wengsht1
LANG: C++
TASK: calfflac
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

//
#define MX 20005
int N, M, K;

char str[MX], trf[MX];
int  _index[MX];
int  len = strlen(str), m = 0;

bool good[3][20001];

void go()
{
    int st, ed;
    int ret = 1;
    for(int i = 0;i < m;i++) { good[0][i] = true; good[1][i] = true; }

    int now = 2, nxt = 0;

    int mx = min(2000, len);

    for(int l = 2;l <= mx;l++)
    {
        for(int i = 0;i < m;i++)
        {
            if(i + l > len) break;

            if(good[nxt][i+1] && trf[i] == trf[i+l-1])
            {
                good[now][i] = true;

                if(ret < l)
                {
                    ret = l;
                    st = i;
                    ed = i+l-1;
                }
                    
            }
        }
        now = nxt;
        nxt = (now+1)%3;
        memset(good[now], false, sizeof(good[now]));
    }
    str[_index[ed] + 1] = '\0';
    cout<<ed-st+1<<endl;
    cout<<str+_index[st]<<endl;
}
int main()
{
#ifdef HOME
    freopen("calfflac.in", "r", stdin);
    freopen("calfflac.out", "w", stdout);
#endif
    string tmp;

    while(getline(cin, tmp))
    {
        strcat(str, tmp.c_str());
        str[strlen(str)] = '\n';
        str[strlen(str)+1] = '\0';
    }

    len = strlen(str);
    for(int i = 0;i < len;i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            _index[m] = i;
            trf[m++] = str[i];
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            _index[m] = i;
            trf[m++] = str[i] + ('a' - 'A');
        }
    }

    go();

    return 0;
}

