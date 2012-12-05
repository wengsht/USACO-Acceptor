
/*
ID: wengsht1
LANG: C++
TASK: starry
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
#define MX_POINTS 160
int N, M, K;
char board[101][101];
char st;

int _x[] = {1, -1, 0, 0, 1, -1, 1, -1};
int _y[] = {0, 0, 1, -1, -1, 1, 1, -1};

inline bool good(int x, int y)
{
    return (x >= 0 && y >= 0 && x < N && y < M && board[x][y] == '1');
}
typedef pair< int,int > Pair;
struct Point 
{
    int x, y;
};
struct Rect
{
    Point point[MX_POINTS];
    int cnt;
}rect[26][8];

bool _cmp(Point a, Point b)
{
    if(a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}
bool same(Rect rect, Point *tmp, int cnt)
{
    if(rect.cnt != cnt) return false;

    for(int i = 0;i < cnt;i++)
    {
        if(rect.point[i].x != tmp[i].x || rect.point[i].y != tmp[i].y)
            return false;
    }
    return true;

}

void floodfill(int x, int y)
{
    int rmn = x, rmx = x, cmn = y, cmx = y;
    queue<Pair> q;
    q.push(make_pair(x, y));

    Point tmp[161];int  cnt = 0;
    board[x][y] = st;

    tmp[cnt].x = x;
    tmp[cnt++].y = y;
    while(!q.empty())
    {
        Pair top = q.front();
        q.pop();
        int xtop = top.first, ytop = top.second;

        for(int i = 0;i < 8;i++)
        {
            int xnxt = xtop + _x[i], ynxt = ytop + _y[i];

            if(!good(xnxt, ynxt))
                continue;

            board[xnxt][ynxt] = st;

            q.push(make_pair(xnxt, ynxt));

            tmp[cnt].x = xnxt;
            tmp[cnt++].y = ynxt;

            if(rmn > xnxt) rmn = xnxt;
            if(rmx < xnxt) rmx = xnxt;
            if(cmn > ynxt) cmn = ynxt;
            if(cmx < ynxt) cmx = ynxt;
        }
    }
    rmx -= rmn;
    cmx -= cmn;

    int p = st - 'a';

    sort(tmp, tmp+cnt, _cmp);
    for(int i = 0;i < cnt;i++)
    {
        tmp[i].x -= rmn;
        tmp[i].y -= cmn;

    }

    for(int i = 0;i < p;i++)
    {
        for(int j = 0;j < 8;j++)
        {
            if(same(rect[i][j], tmp, cnt))
            {
                p = i;

                break;
            }
        }
    }
    if(p == st-'a')
    {
        for(int i = 0;i < 8;i++)
        {
            rect[p][i].cnt = cnt;
        }
        for(int i = 0;i < cnt;i++)
        {
            rect[p][0].point[i].x = tmp[i].x;
            rect[p][0].point[i].y = tmp[i].y;

            rect[p][1].point[i].x = tmp[i].x;
            rect[p][1].point[i].y = cmx - tmp[i].y;
            
            rect[p][2].point[i].x = rmx - tmp[i].x;
            rect[p][2].point[i].y = tmp[i].y;

            rect[p][3].point[i].x = rmx - tmp[i].x;
            rect[p][3].point[i].y = cmx - tmp[i].y;

            rect[p][4].point[i].x = tmp[i].y;
            rect[p][4].point[i].y = tmp[i].x;

            rect[p][5].point[i].x = cmx - tmp[i].y;
            rect[p][5].point[i].y = tmp[i].x;

            rect[p][6].point[i].x = tmp[i].y;
            rect[p][6].point[i].y = rmx - tmp[i].x;

            rect[p][7].point[i].x = cmx - tmp[i].y;
            rect[p][7].point[i].y = rmx - tmp[i].x;
        }

        for(int i  =0;i < 8;i++)
            sort(rect[p][i].point, rect[p][i].point+rect[p][i].cnt, _cmp);

        st ++;
    }
    if(p < st-'a')
    {
        for(int i = 0;i < cnt;i++)
        {
            board[tmp[i].x + rmn][tmp[i].y + cmn] = 'a' + p;
        }
    }
}
void go()
{
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < M;j++)
        {
            if(board[i][j] == '0' || board[i][j] != '1')
                continue;

            floodfill(i, j);
        }
    }
}

int main()
{
#ifdef HOME
    freopen("starry.in", "r", stdin);
    freopen("starry.out", "w", stdout);
#endif
    scanf("%d %d", &M, &N);

    for(int i = 0;i < N;i++)
        scanf("%s", board[i]);

    st = 'a';
    go();


    for(int i = 0;i < N;i++)
        printf("%s\n", board[i]);

    return 0;
}

