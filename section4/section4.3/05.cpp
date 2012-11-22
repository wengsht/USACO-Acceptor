
/*
ID: wengsht1
LANG: C++
TASK: lgame
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

#define MX 40005
int N, M, K;

char text[10];
int  text_code;
int  mx_ret;
int  good_code[MX];
int  cm;
int  good_score[MX];
int  sm;

struct Word
{
    char raws[8];
    int  code;
}word[MX];
int m;

#define MX_CODE 520000
int head[MX_CODE], nxt[MX], V[MX];

int cnt;
void add(int u, int v)
{
    V[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

int mp[26];

const int d[] = {2, 3, 5, 7, 11 ,13, 17};
const int s[] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
int score[18];
int get_code_raws(char *text)
{
    int now = 0;

    memset(mp, -1, sizeof(mp));

    int ret = 1;
    int len = strlen(text);
    for(int i = 0;i < len;i++)
    {
        if(mp[text[i]-'a'] == -1)
        {
            mp[text[i]-'a'] = d[now++];
            score[mp[text[i] - 'a']] = s[text[i] - 'a'];
        }

        ret *= mp[text[i]-'a'];
    }
    return ret;
}
int get_score(int code)
{
    int ret = 0;
    for(int i = 0;i < 7;i++)
    {
        while(code % d[i] == 0)
        {
            ret += score[d[i]];
            code /= d[i];
        }
    }
    return ret;
}
int get_code(char *p)
{
    int len = strlen(p);

    int ret = 1;
    int tmp = text_code;
    for(int i = 0;i < len;i++)
    {
        if(-1 != mp[p[i] - 'a'] && tmp % mp[p[i] - 'a'] == 0)
        {
            ret *= mp[p[i] - 'a'];

            tmp /= mp[p[i] - 'a'];
        }
        else
        {
            ret = -1;
            break;
        }
    }
    return ret;
}
int main()
{
#ifdef HOME
    freopen("lgame.in", "r", stdin);
#endif
    scanf("%s", text);
    text_code = get_code_raws(text);
#ifdef HOME
    freopen("lgame.dict", "r", stdin);
    freopen("lgame.out", "w", stdout);
#endif
    memset(head, -1, sizeof(head));
    while(scanf("%s", word[m].raws) && word[m].raws[0] != '.')
    {
        if(m > 0 && strcmp(word[m].raws, word[m-1].raws) == 0)
            continue;
        word[m].code = get_code(word[m].raws);

        if(word[m].code > 0)
        {
            add(word[m].code, m);
            m++;
        }
    }
    int mxx = text_code;
    for(int i = 2; i <= mxx; i++)
    {
        if(head[i] != -1)
            good_code[cm++] = i;
    }
    mx_ret = 0;
    for(int i = 0;i < cm;i++)
    {
        int s_i = get_score(good_code[i]);
        int r_code = text_code / good_code[i];

        if(s_i > mx_ret)
        {
            mx_ret = s_i;

            sm = 0;
            good_score[sm++] = good_code[i];
        }
        else if(s_i == mx_ret)
            good_score[sm++] = good_code[i];

        for(int j = i;j < cm;j++)
        {
            int s_j = get_score(good_code[j]);
            if(r_code % good_code[j] == 0)
            {
                if(s_i + s_j > mx_ret)
                {
                    mx_ret = s_i + s_j;

                    sm = 0;
                    good_score[sm++] = good_code[i] * good_code[j];
                }
                else if(s_i + s_j == mx_ret)
                    good_score[sm++] = good_code[i] * good_code[j];
            }

        }
    }
    sort(good_score, good_score + sm);

    cm  = 0;
    good_code[cm++] = good_score[0];
    for(int i = 1;i < sm;i++)
        if(good_score[i] != good_score[i-1])
            good_code[cm++] = good_score[i];

    printf("%d\n", mx_ret);
    int tmp[MX];
    int tmpm = 0;
    for(int i = 0;i < m;i++)
    {
        if(text_code % word[i].code == 0)
        {
            int s_i = get_score(word[i].code);

            if(s_i == mx_ret)
                printf("%s\n", word[i].raws);
            else
            {
                tmpm = 0;
                for(int j = 0;j < cm;j++)
                {
                    if(good_code[j] % word[i].code == 0)
                    {
                        int r_j = good_code[j] / word[i].code;

                        for(int k = head[r_j]; k != -1;k = nxt[k])
                        {
                            if(V[k] >= i)
                                tmp[tmpm++] = V[k];
                        }
                    }
                }
                sort(tmp, tmp+tmpm);

                for(int j = 0;j < tmpm;j++)
                {
                    printf("%s %s\n", word[i].raws, word[tmp[j]].raws);
                }
            }
        }
    }
    return 0;
}

