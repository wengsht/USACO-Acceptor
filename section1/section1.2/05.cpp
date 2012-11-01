
/*
ID: wengsht1
LANG: C++
TASK: palsquare
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
char mp[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N'};

bool good(char *s)
{
    int len = strlen(s);

    for(int i = 0;i < len;i++)
    {
        if(s[i] != s[len-i-1]) return false;
    }
    return true;
}
void itoa(int m, char *out, int n)
{
    char tmp[101];
    int size = 0;
    while(m)
    {
        tmp[size++] = mp[m%n];

        m /= n;
    }
    out[size] = '\0';
    for(int i = size-1;i >= 0;i--)
        out[size-i-1] = tmp[i];
    out[size] = '\0';
}
int main()
{
#ifdef HOME
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
#endif
    cin>>N;
    char str[1000], num[1000];
    for(int i = 1;i <= 300;i++)
    {
        int sq = i * i;

        itoa(sq, str, N);
        itoa(i, num, N);

        if(good(str)) cout<<num<<" "<<str<<endl;
    }

    return 0;
}

