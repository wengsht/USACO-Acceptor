
/*
ID: wengsht1
LANG: C++
TASK: contact
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
int a, b, c;
char input[200001];
char tmp[200];

struct Node
{
    string s;
    int p;
}rets[50000];

bool _cmp(Node a, Node b)
{
    if(a.p != b.p) return a.p > b.p;
    else if(a.s.length() != b.s.length()) return a.s.length() < b.s.length();
    else return a.s < b.s;
}
int m;
int main()
{
#ifdef HOME
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);
#endif
    scanf("%d %d %d", &a ,&b, &c);

    while(scanf("%s", tmp) != EOF) strcat(input, tmp);

    int len = strlen(input);

    map<string, int> ret;

    string now;
    for(int i = 0;i < len;i++)
    {
        now = "";
        for(int j = 0;j < a-1 && i+j < len;j++) now += input[i+j];

        for(int j = a-1;j < b && i+j < len;j++)
        {
            now += input[i+j];

            ret[now] ++;
        }
    }
    map<string, int>::iterator mp;
    for(mp = ret.begin(); mp != ret.end();mp++)
    {
        rets[m].s = mp->first;
        rets[m++].p = mp->second;
    }
    sort(rets, rets+m, _cmp);

    int k = 0;

    printf("%d\n%s", rets[0].p, rets[0].s.c_str());
    int i = 1, j = 1;
    while(k < c)
    {
        if(i >= m) 
        {
            printf("\n");

            break;
        }
        if(rets[i].p == rets[i-1].p)
        {
            if(j == 6)
            {
                printf("\n");
                j = 0;
            }
            else printf(" ");
            printf("%s", rets[i].s.c_str());
            j++;
        }
        else
        {
            k++;
            printf("\n");
            if(k >= c) break;

            printf("%d\n%s", rets[i].p, rets[i].s.c_str());
            j = 1;
        }
        i++;
    }


    return 0;
}

