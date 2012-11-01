
/*
ID: wengsht1
LANG: C++
TASK: runround
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

int nums[11];
int m;

bool used[10];
bool getto[10];
int tmp[10];

void get(int n)
{
    while(n)
    {
        nums[m++] = n % 10;

        n /= 10;
    }
}

bool hadadd = false;

inline bool test()
{
    bool mask[10];
    memset(mask, false, sizeof(mask));

    int j = 0;
    mask[0] = true;
    for(int i = 0;i < m-1;i++)
    {
        j = (tmp[j] + j) % m;

        if(mask[j]) return false;
        mask[j] = true;
    }
    return ((j + tmp[j])%m == 0);
}
bool go(int p)
{
    int mn = nums[m-1-p];

    if(hadadd) mn = 1;

    bool t = hadadd;
    for(int i = mn;i <= 9;i++)
    {
        if(!used[i])
        {
            tmp[p] = i;

            used[i] = true;
            if(nums[m-1-p] < i) hadadd = true;
            if(p == m-1 && test() || go(p+1))
                return true;

            hadadd = t;

            used[i] = false;
        }
    }
    return false;
}
int main()
{
#ifdef HOME
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
#endif
    cin>>N;

    get(N);
    int t = m;
    N++;
    m = 0;
    get(N);

    if(m > t)
        hadadd = true;

    if(!go(0))
    {
        m++;
        hadadd = true;

        go(0);
    }
    for(int i = 0;i < m;i++) cout<<tmp[i]; 
    cout<<endl;

    return 0;
}

