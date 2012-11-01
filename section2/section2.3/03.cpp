
/*
ID: wengsht1
LANG: C++
TASK: zerosum
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

int tmp[10];
char op[] = " +-";

bool test()
{
   int nums[10];
   int m = 0;
   int opp[10];

   opp[0] = 1;

   nums[0] = 1;
   for(int i = 0;i < N-1;i++)
   {
       if(tmp[i] > 0)
       {
           m++;

           nums[m] = i+2;

           opp[m] = (tmp[i] == 2 ? -1:1);
       }
       else
           nums[m] = nums[m] * 10 + i+2;
   }
   int ret = 0;

   for(int i = 0;i <= m;i++) ret += nums[i] * opp[i];

   return (ret == 0);
}

void dfs(int h)
{
    for(int i = 0;i < 3;i++)
    {
        tmp[h] = i;

        if(h == N-2)
        {
            if(test())
            {
                printf("1");

                for(int i = 1;i < N;i++)
                {
                    printf("%c%d", op[tmp[i-1]], i+1);
                }
                printf("\n");
            }
        }
        else dfs(h+1);
    }
}
int main()
{
#ifdef HOME
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
#endif
    cin>>N;

    dfs(0);

    return 0;
}

