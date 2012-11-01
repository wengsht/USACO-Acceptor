
/*
ID: wengsht1
LANG: C++
TASK: namenum
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

string mp[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO","PRS","TUV","WXY"};

string ret[5001];
int m;
int len;


bool good(string a, string b)
{
    if(a.length() != len) return false;

    for(int i = 0;i < len;i++)
    {
        int ok = false;
        for(int j = 0;j < 3;j++)
        {
            if(mp[b[i] - '0'][j] == a[i]) ok = true;
        }
        if(ok == false) return false;
    }
    return true;
}

int main()
{
#ifdef HOME
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
#endif
    cin>>str;
    len = str.length();

    freopen("dict.txt", "r", stdin);
    string tmp;
    while(cin>>tmp)
    {
        if(good(tmp, str))
        {
            ret[m++] = tmp;
        }
    }
    sort(ret, ret+m);
    for(int i = 0;i < m;i++)
        cout<<ret[i]<<endl;

    if(m == 0) cout<<"NONE"<<endl;
    return 0;
}

