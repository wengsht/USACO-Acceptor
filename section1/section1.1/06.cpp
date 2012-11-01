
/*
ID: wengsht1
LANG: C++
TASK: friday
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

int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ret[7];

bool isr(int y)
{
    if(y % 100 != 0 && y % 4 == 0 || y % 400 == 0) return true;
    return false;
}
int main()
{
#ifdef HOME
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
#endif
    cin>>N;

    int st = 0;
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < 12;j++)
        {
            int d = m[j];
            if(j == 1 && isr(1900+i)) d++;

            ret[(st+12)%7] ++;

            st = (st + d) % 7;
        }
    }
    cout<<ret[5]<<" "<<ret[6];
    for(int i = 0;i < 5;i++)
        cout<<" "<<ret[i];
    cout<<endl;

    return 0;
}

