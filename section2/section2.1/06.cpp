
/*
ID: wengsht1
LANG: C++
TASK: hamming
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
int N, B, D;

int mask[] = {1, 2, 4, 8, 16,32, 64, 128, 256};
bool good(int i, int j)
{
    int cnt = 0;
    for(int k = 0;k < 8;k++)
    {
        if((i & mask[k]) != (j & mask[k])) cnt++;
    }
    return cnt >= D;

}
int ret[256];
int m;
int main()
{
#ifdef HOME
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
#endif
    cin>>N>>B>>D;

    int mx = 1;
    for(int i = 1;i <= B;i++) mx *= 2;
    ret[m++] = 0;

    for(int i = 1;i < mx;i++)
    {
        bool ok = true;
        for(int j = 0;j < i;j++)
        {
            if(!good(ret[j], i)) ok = false;
        }
        if(ok) ret[m++] = i;
    }
    printf("%d", ret[0]);
    for(int i = 1;i < N;i++) 
    {
        if((i+1) % 10 != 1) printf(" ");
        printf("%d", ret[i]);
        if((i+1) % 10 == 0) printf("\n");
    }
    if(N % 10 != 0) printf("\n");

    return 0;
}

