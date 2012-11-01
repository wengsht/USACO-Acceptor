
/*
ID: wengsht1
LANG: C++
TASK: transform
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

class Node
{
public:
    char rote[11][11];
};
bool same(Node st, Node ed)
{
    for(int i = 0; i < N;i++)
    {
        for(int j = 0;j < N;j++)
            if(st.rote[i][j] != ed.rote[i][j]) return false;
    }

    return true;
}
void output(Node a)
{
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N;j++)
            cout<<a.rote[i][j];
        cout<<endl;
    }
}
Node r90(Node st)
{
    Node ret;
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++)
            ret.rote[j][N-i-1] = st.rote[i][j];
    return ret;
}
Node r180(Node st)
{
    Node ret;
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++)
            ret.rote[N-i-1][N-j-1] = st.rote[i][j];
//    output(ret);
    return ret;
}
Node r270(Node st)
{
    Node ret;
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++)
            ret.rote[N-j-1][i] = st.rote[i][j];
    return ret;
}
Node ref(Node st)
{
    Node ret;
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++)
            ret.rote[i][N-j-1] = st.rote[i][j];
    return ret;
}
bool f1(Node st, Node ed)
{
    Node nxt = r90(st);
    return same(nxt, ed);
}
bool f2(Node st, Node ed)
{
    Node nxt = r180(st);
    return same(nxt, ed);
}
bool f3(Node st, Node ed)
{
    Node nxt = r270(st);
    return same(nxt, ed);
}
bool f4(Node st, Node ed)
{
    Node nxt = ref(st);
    return same(nxt, ed);
}
bool f5(Node st, Node ed)
{
    Node nxt = ref(st);
    Node ret1 = r90(nxt);
    if(same(ret1, ed)) return true;
    ret1 = r180(nxt);
    if(same(ret1, ed)) return true;
    ret1 = r270(nxt);
    if(same(ret1, ed)) return true;

    return false;
}
bool f6(Node st, Node ed)
{
    return same(st, ed);
}
bool f7(Node st, Node ed)
{
    return true;
}

int main()
{
#ifdef HOME
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
#endif
    scanf("%d", &N);

    Node s, ed;

    for(int i = 0;i < N;i++) scanf("%s", s.rote[i]);
    for(int i = 0;i < N;i++) scanf("%s", ed.rote[i]);

    Node tmp = s;

    if(f1(s, ed))
        cout<<1<<endl;
    else if(f2(s, ed))
        cout<<2<<endl;
    else if(f3(s, ed))
        cout<<3<<endl;
    else if(f4(s, ed))
        cout<<4<<endl;
    else if(f5(s, ed))
        cout<<5<<endl;
    else if(f6(s, ed))
        cout<<6<<endl;
    else 
        cout<<7<<endl;

    return 0;
}

