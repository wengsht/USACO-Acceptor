
/*
ID: wengsht1
LANG: C++
TASK: frameup
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

char input[50];
int board[50][50];
int m;
bool used[50];
char ret[50];

string rett[10000];
int mm;

bool check(int x1, int y1, int x2, int y2, int c, int cnt)
{
    for(int i = y1;i <= y2;i++)
    {
        if(board[x1][i] != c && !used[board[x1][i]])
            return false;
        if(board[x1][i] == c)
            cnt--;
    }
    for(int i = y1;i <= y2;i++)
    {
        if(board[x2][i] != c && !used[board[x2][i]])
            return false;
        if(board[x2][i] == c)
            cnt--;
    }
    for(int i = x1+1;i < x2;i++)
    {
        if(board[i][y1] != c && !used[board[i][y1]])
            return false;
        if(board[i][y1] == c)
            cnt--;
    }
    for(int i = x1+1;i < x2;i++)
    {
        if(board[i][y2] != c && !used[board[i][y2]])
            return false;
        if(board[i][y2] == c)
            cnt--;
    }
    return (!cnt);
}

int x[31][31], y[31][31];
bool go(int c)
{
    int i, j;
    int mnx = N-1, mny = M-1, mxx = 0, mxy = 0;
    int cnt = 0;
    for(i = 0;i < N;i++)
    {
        for(j = 0;j < M;j++)
        {
            if(board[i][j] == c)
            {
                cnt++;
                if(mnx > i) mnx = i;
                if(mny > j) mny = j;
                if(mxx < i) mxx = i;
                if(mxy < j) mxy = j;
            }
        }
    }
    if(check(mnx, mny, mxx, mxy, c, cnt))
    {
        return true;
    }
    return false;
}
void dfs(int h)
{
    for(int i = 0;i < 26;i++)
    {
        if(!used[i])
        {
            if(go(i))
            {
                ret[K-h-1] = 'A' + i;
                if(h == K-1)
                {
                    rett[mm++] = ret;
                    return ;
                }
                used[i] = true;

                dfs(h+1);

                used[i] = false;
            }
        }
    }
}

int main()
{
#ifdef HOME
    freopen("frameup.in", "r", stdin);
    freopen("frameup.out", "w", stdout);
#endif
    scanf("%d %d", &N, &M);
    memset(used, true, sizeof(used));
    used[26] = false;
    for(int i = 0;i < N;i++)
    {
        scanf("%s", input);
        for(int j = 0;j < M;j++)
        {
            if(input[j] == '.')
                board[i][j] = 26;
            else
            {
                board[i][j] = input[j] - 'A';
                used[input[j] - 'A'] = false;
            }
        }
    }
    for(int i = 0;i < 26;i++)
        if(!used[i]) 
            K++;

    ret[K] = '\0';
    dfs(0);

    sort(rett, rett+mm);
    for(int i = 0;i < mm;i++)
        cout<<rett[i]<<endl;
    return 0;
}

