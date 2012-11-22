
/*
 *  从这题开始蛋疼了估计。。 强剪枝是搜google的。。
 */
/*
ID: wengsht1
LANG: C++
TASK: fence8
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

int board[51], rails[1025];
int tmp[51];
int sumb;
int sums[1025];
int sum_empty;
int ret;

int position[129];

bool dfs(int h, int r)
{
    if(r > sum_empty) return false;

    int mn = position[rails[h]];
    for(int i = mn;i < N;i++)
    {
        if(tmp[i] >= rails[h])
        {
            if(!h) return true;
            tmp[i] -= rails[h];
            position[rails[h]] = i;

            if(tmp[i] < rails[0])
            {
                if(dfs(h-1, r+tmp[i]))
                    return true;
            }
            else
            {
                if(dfs(h-1, r))
                    return true;
            }
            position[rails[h]] = mn;
            tmp[i] += rails[h];
        }
    }
    return false;
}
bool test(int mid)
{
    memset(position, -1, sizeof(position));
    sum_empty = sumb - sums[mid-1];

    if(sum_empty < 0) return false;

    memcpy(tmp, board, sizeof(board));

    return dfs(mid-1, 0);
}
void go()
{
    int l = 1, h = M;
    while(l <= h)
    {
        int mid = l + ((h - l) >> 1);

        if(test(mid)) 
        {
            ret = mid;
            l = mid + 1;
        }
        else h = mid - 1;
    }
}
int main()
{
#ifdef HOME
    freopen("fence8.in", "r", stdin);
    freopen("fence8.out", "w", stdout);
#endif
    scanf("%d", &N);
    for(int i = 0;i < N;i++) 
    {
        scanf("%d", board+i);
        sumb += board[i];
    }
    sort(board, board+N);

    scanf("%d", &M);
    for(int i = 0;i < M;i++) scanf("%d", rails+i);
    sort(rails, rails+M);
    sums[0] = rails[0];
    for(int i = 1;i < M;i++) sums[i] = sums[i-1] + rails[i];

    go();

    cout<<ret<<endl;

    return 0;
}

