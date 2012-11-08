
/*
ID: wengsht1
LANG: C++
TASK: msquare
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

int aa[] = {7,6,5,4,3,2,1,0};
int bb[] = {3,0,1,2,5,6,7,4};
int cc[] = {0,6,1,3,4,2,5,7};

string ret[45000];

int f[] = {5040, 720, 120, 24, 6, 2, 1, 1};
int key(int st)
{
    int ret = 0;
    int nums[8];
    for(int i = 7;i >= 0;i--, st /= 10) nums[i] = st % 10;

    for(int i = 0;i < 8;i++)
    {
        int cnt = 0;
        for(int j = i+1;j < 8;j++)
            if(nums[j] < nums[i]) cnt++;

        ret = ret + cnt * f[i];
    }

    return ret;
}
int A(int st)
{
    int nums[8];
    int tmp[8];
    for(int i = 7;i >= 0;i--, st /= 10) nums[i] = st % 10;

    for(int i = 0;i < 8;i++) tmp[i] = nums[aa[i]];

    int ret = 0;
    for(int i = 0;i < 8;i++) ret = ret * 10 + tmp[i];

    return ret;
}
int B(int st)
{
    int nums[8];
    int tmp[8];
    for(int i = 7;i >= 0;i--, st /= 10) nums[i] = st % 10;

    for(int i = 0;i < 8;i++) tmp[i] = nums[bb[i]];

    int ret = 0;
    for(int i = 0;i < 8;i++) ret = ret * 10 + tmp[i];

    return ret;
}
int C(int st)
{
    int nums[8];
    int tmp[8];
    for(int i = 7;i >= 0;i--, st /= 10) nums[i] = st % 10;

    for(int i = 0;i < 8;i++) tmp[i] = nums[cc[i]];

    int ret = 0;
    for(int i = 0;i < 8;i++) ret = ret * 10 + tmp[i];

    return ret;
}
int main()
{
#ifdef HOME
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);
#endif
    for(int i = 0;i < 40320;i++) ret[i] = "";

    int st = 12345678;
    int a;
    int ed = 0;
    for(int i = 0;i < 8;i++)
    {
        cin>>a;
        ed = ed * 10 + a;
    }

    queue<int> q;
    q.push(st);

    if(st == ed)
    {
        cout<<0<<endl<<endl;

        return 0;
    }

    while(!q.empty())
    {
        int top = q.front(); q.pop();

        string md = ret[key(top)];

        int a = A(top), b = B(top), c = C(top);
        int keya = key(a), keyb = key(b), keyc = key(c);

        if(a != st && ret[keya].length() == 0)
        {
            ret[keya] = md + 'A';

            q.push(a);
            if(a == ed)
            {
                cout<<ret[keya].length()<<endl<<ret[keya]<<endl;
                break;
            }
        }
        if(b != st && ret[keyb].length() == 0)
        {
            ret[keyb] = md + 'B';

            q.push(b);
            if(b == ed)
            {
                cout<<ret[keyb].length()<<endl<<ret[keyb]<<endl;
                break;
            }
        }
        if(c != st && ret[keyc].length() == 0)
        {
            ret[keyc] = md + 'C';

            q.push(c);
            if(c == ed)
            {
                cout<<ret[keyc].length()<<endl<<ret[keyc]<<endl;
                break;
            }
        }
    }

    return 0;
}

