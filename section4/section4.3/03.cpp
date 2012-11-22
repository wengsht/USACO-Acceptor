
/*
ID: wengsht1
LANG: C++
TASK: prime3
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

struct Ret
{
    int nu[5];
}ret[MX];
int m;

int board[5][5];
int tmpr[5];
int tmpc[5];
int tmpa, tmpb;

int f[10][5];
bool _cmp(Ret a, Ret b)
{
    for(int i = 0;i < 5;i++)
        if(a.nu[i] != b.nu[i])
            return a.nu[i] < b.nu[i];

    return true;
}

bool isprime[MX+5];
int prime[MX+5];

void prime_list()
{
    memset(isprime, true, sizeof(isprime));

    for(int i = 2;i < MX;i++)
    {
        if(isprime[i])
            prime[++prime[0]] = i;

        for(int j = 1;prime[j] * i < MX;j++)
        {
            isprime[prime[j] * i] = false;

            if(i % prime[j] == 0) break;
        }
    }
}

int r_sum[5];
int c_sum[5];
int suma, sumb;

inline void go(int r, int c, int p)
{
    r_sum[r] -= p;
    c_sum[c] -= p;
    tmpr[r] += f[p][c];
    tmpc[c] += f[p][r];

    if(r == c)
    {
        tmpa += f[p][r];
        suma -= p;
    }
    if(r == 4-c)
    {
        tmpb += f[p][c];
        sumb -= p;
    }
}
inline void reset(int r, int c, int p)
{
    r_sum[r] += p;
    c_sum[c] += p;
    tmpr[r] -= f[p][c];
    tmpc[c] -= f[p][r];

    if(r == c)
    {
        tmpa -= f[p][r];
        suma += p;
    }
    if(r == 4-c)
    {
        tmpb -= f[p][c];
        sumb += p;
    }
}
void dfs(int r, int c)
{
    int p = r * 5 + c;

    int kk;
    switch(p)
    {
        case 1: //(0,1)
            for(int i = 1;i <= 9;i++)
            {
                go(0, 1, i);

                if(r_sum[0] >= 1 && c_sum[1] >= 0)
                    dfs(0, 3);
                else
                {
                    reset(0, 1, i);
                    break;
                }

                reset(0, 1, i);
            }
            break;

        case 2: //(0, 2)
            kk = c_sum[2];
            if(kk > 9) break;
            go(0, 2, kk);

            if(isprime[tmpc[2]] && r_sum[0] >= 2)
                dfs(4, 1);

            reset(0, 2, kk);
            break;
        case 3: //(0, 3)
            kk = r_sum[0];
            if(kk > 9) break;

            go(0, 3, kk);
            if(isprime[tmpr[0]] && c_sum[3] >= 0)
                dfs(2, 1);

            reset(0, 3, kk);
            break;
        case 4: //(0, 4)
            for(int i = 1;i <= 9;i+=2)
            {
                if(i == 5) continue;

                go(0, 4, i);

                if(sumb >= 1 && r_sum[0] >= 3 && c_sum[4] >= 3)
                    dfs(4, 0);
                else
                {
                    reset(0, 4, i);
                    break;
                }

                reset(0, 4, i);
            }
            break;
        case 5: //(1, 0)
            for(int i = 1;i <= 9;i++)
            {
                go(1, 0, i);

                if(r_sum[1] >= 0 && c_sum[0] >= 2)
                    dfs(1, 2);
                else
                {
                    reset(1, 0, i);
                    break;
                }

                reset(1, 0, i);
            }
            break;
        case 6: //(1, 1)
            for(int i = 0;i <= 9;i++)
            {
                go(1, 1, i);

                if(r_sum[1] >= 2 && c_sum[1] >= 2 && suma >= 0)
                    dfs(2, 2);
                else
                {
                    reset(1, 1, i);
                    break;

                }

                reset(1, 1, i);
            }
            break;
        case 7: //(1, 2)
            kk = r_sum[1];
            if(kk > 9) break;
            go(1, 2, kk);

            if(isprime[tmpr[1]] && c_sum[2] >= 2)
                dfs(3, 0);

            reset(1, 2, kk);
            break;
        case 8: //(1, 3))
            kk = sumb;
            if(kk > 9) break;
            go(1, 3, kk);

            if(isprime[tmpb] && r_sum[1] >= 2 && c_sum[3] >= 2)
                dfs(1, 4);

            reset(1, 3, kk);
            break;
        case 9: //(1, 4)
            for(int i = 1;i <= 9;i += 2)
            {
                if(i == 5) 
                    continue;

                go(1, 4, i);

                if(r_sum[1] >= 1 && c_sum[4] >= 2)
                    dfs(2, 4);
                else
                {
                    reset(1, 4, i);
                    break;
                }

                reset(1, 4, i);
            }
            break;
        case 10: //(2, 0)
            kk = c_sum[0];
            if(kk > 9) break;

            go(2, 0, kk);
            if(isprime[tmpc[0]] && r_sum[2] >= 0)
                dfs(4, 2);


            reset(2, 0, kk);
            break;
        case 11:  //(2, 1)
            kk = c_sum[1];
            if(kk > 9) break;

            go(2, 1, kk);

            if(isprime[tmpc[1]] && r_sum[2] >= 0)
                dfs(2, 3);

            reset(2, 1, kk);
            break;
        case 12: //(2, 2)
            for(int i = 0;i <= 9;i++)
            {
                go(2, 2, i);

                if(r_sum[2] >= 2 && c_sum[2] >= 2 && suma >= 0)
                    dfs(3, 3);
                else 
                {
                    reset(2, 2, i);

                    break;
                }
                reset(2, 2, i);
            }
            break;
        case 13: //2, 3)
            kk = r_sum[2];
            if(kk > 9) break;
            if(kk != c_sum[3])
                break;

            go(2, 3, kk);

            if(isprime[tmpr[2]] && isprime[tmpc[3]])
                memcpy(ret[m++].nu, tmpr, sizeof(tmpr));

            reset(2, 3, kk);
            break;
        case 14: //(2, 4)
            for(int i = 1;i <= 9;i += 2)
            {
                if(i == 5) continue;

                go(2, 4, i);

                if(r_sum[2] >= 1 && c_sum[4] >= 1)
                    dfs(3, 4);
                else
                {
                    reset(2, 4, i);
                    break;
                }

                reset(2, 4, i);
            }
            break;

        case 15: //(3, 0)
            for(int i = 1;i <= 9;i++)
            {
                go(3, 0, i);

                if(r_sum[3] >= 0 && c_sum[0] >= 1)
                    dfs(3, 2);
                else
                {
                    reset(3, 0, i);
                    break;
                }
                reset(3, 0, i);
            }
            break;
        case 16: //(3, 1)
            for(int i = 0;i <= 9;i++)
            {
                go(3, 1, i);

                if(sumb >= 0 && r_sum[3] >= 2 && c_sum[1] >= 2)
                    dfs(1, 3);
                else
                {
                    reset(3, 1, i);
                    break;
                }

                reset(3, 1, i);
            }
            break;
        case 17: //(3, 2))
            kk = r_sum[3];
            if(kk > 9) break;
            go(3, 2, kk);

            if(isprime[tmpr[3]] && c_sum[2] >= 2)
                dfs(2, 0);

            reset(3, 2, kk);
            break;
        case 18: //(3,3)
            kk = suma;
            if(kk > 9) break;
            go(3, 3, kk);

            if(isprime[tmpa] && r_sum[3] >= 2 && c_sum[3] >= 2)
                dfs(0, 4);

            reset(3, 3, kk);
            break;
        case 19: //(3, 4)
            kk = c_sum[4];
            if(kk > 9) break;
            go(3, 4, kk);

            if(isprime[tmpc[4]] && r_sum[3] >= 1)
                dfs(1, 0);
            reset(3, 4, kk);

            break;
        case 20: //(4, 0)
            for(int i = 1;i <= 9;i+=2)
            {
                if(i == 5)
                    continue;

                go(4, 0, i);

                if(sumb >= 0 && r_sum[4] >= 3 && c_sum[0] >= 3)
                    dfs(3, 1);
                else
                {
                    reset(4, 0, i);
                    break;
                }
                reset(4, 0, i);
            }
            break;
        case 21: //(4, 1)
            for(int i = 1;i <= 9;i += 2)
            {
                if(i == 5) continue;

                go(4, 1, i);

                if(r_sum[4] >= 1 && c_sum[1] >= 1)
                    dfs(4, 3);
                else
                {
                    reset(4, 1, i);
                    break;
                }

                reset(4, 1, i);
            }
            break;
        case 22: //(4, 2
            for(int i = 1;i <= 9;i += 2)
            {
                if(i == 5) continue;

                go(4, 2, i);

                if(r_sum[4] >= 2 && c_sum[2] >= 1)
                    dfs(0, 2);
                else
                {
                    reset(4, 2, i);
                    break;
                }

                reset(4, 2, i);
            }



            break;
        case 23: // (4, 3))
            kk = r_sum[4];
            if(kk > 9) break;
            go(4,3,kk);

            if(isprime[tmpr[4]] && c_sum[3] >= 1)
                dfs(0, 1);

            reset(4,3,kk);
            break;
        case 24: // (4, 4))
            for(int i = 1;i <= 9;i+=2)
            {
                if(i == 5) continue;

                go(4, 4, i);

                if(suma >= 0 && r_sum[4] >= 4 && c_sum[4] >= 4)
                    dfs(1, 1);
                else 
                {
                    reset(4, 4, i);
                    break;
                }

                reset(4, 4, i);
            }
            break;
    }

}
int main()
{
#ifdef HOME
    freopen("prime3.in", "r", stdin);
     freopen("prime3.out", "w", stdout);
#endif
    cin>>N>>M;
    prime_list();

    for(int i = 0;i < 10;i++)
    {
        int k = 1;
        for(int j = 4;j >= 0;j--, k *= 10)
            f[i][j] = i * k;
    }

    for(int i = 0;i < 5;i++)
        c_sum[i] = r_sum[i] = N;

    suma = N;
    sumb = N;
    tmpa = 0;
    tmpb = 0;

    go(0, 0, M);
    dfs(4, 4);

    sort(ret, ret+m, _cmp);
    if(m == 0)
        cout<<"NONE"<<endl;
    else
    {
        for(int i = 0;i < m;i++)
        {
            if(i > 0)
                printf("\n");

            for(int j = 0;j < 5;j++)
            {
                printf("%d\n", ret[i].nu[j]);
            }
        }
    }


    return 0;
}

