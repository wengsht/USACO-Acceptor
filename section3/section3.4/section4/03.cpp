
/*
ID: wengsht1
LANG: C++
TASK: heritage
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

char in1[100], pre1[100];

void go(char *in1, char *pre1, int l)
{
    if(!l) return ;
    char hed = pre1[0];

    int i = 0;
    while(in1[i] != hed) i++;

    go(in1, pre1+1, i);
    go(in1+i+1, pre1+i+1, l - i -1);

    cout<<hed;
}
int main()
{
#ifdef HOME
    freopen("heritage.in", "r", stdin);
    freopen("heritage.out", "w", stdout);
#endif

    cin>>in1>>pre1;

    go(in1, pre1, strlen(in1));
    cout<<endl;

    return 0;
}

