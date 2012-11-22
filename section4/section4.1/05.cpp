/*
ID: wengsht1
LANG: C++
TASK: cryptcow
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

#define MX 1000007
int N, M, K;

char raws[] = "Begin the Escape execution at the Break of Dawn";
string a = raws;
char input[100];
int cnt[256];
int ret;

char d[] = "COW";
int len_input;
int len;

bool had[MX+10086];

bool find_sub(int i, int j)
{
    string b = input;
    string sub = b.substr(i, j-i+1);
    return a.find(sub) != string::npos;
}
inline bool ELFHash(char *s, int length){
    unsigned long h=0,g;
    for (int i=0; i<length; i++){
        h=(h<<4)+s[i];
        g=h&0xf0000000l;
        if(g){
            h^=g>>24;
        }
        h&=~g;
    }

    h = h%MX;
    if(h < 0) h += MX;

    if(had[h])
        return true;
    else{
        had[h] = true;
        return false;
    }
}
char tl[100] = "\0";
void product(int i, int j, int k)
{
    memset(tl, 0, sizeof(tl));
    strncpy(tl, input+j+1, k - j - 1);
    strncat(tl, input+i+1, j - i - 1);
    strncat(tl, input+k+1, len_input - k - 1);

    input[i] = '\0';
    strcat(input, tl);
}
string test;
bool go(int p)
{
    char tmp[100];
    int c[15], o[15], w[15];
    int label[100];
    int mc = 0, mo = 0, mw = 0;
    int m = 0;

    memset(tmp, 0, sizeof(tmp));
    if(ELFHash(input, strlen(input))) return false;

    label[m++] = -1;
    for(int i = 0;i < len_input;i++)
    {
        if(input[i] == 'C')
        {
            c[mc++] = i;
            label[m++] = i;
        }
        if(input[i] == 'O') 
        {
            o[mo++] = i;
            label[m++] = i;
        }
        if(input[i] == 'W')
        {
            w[mw++] = i;
            label[m++] = i;
        }
    }
    if(m > 1)
    {
        if(input[label[1]] != 'C' || input[label[m-1]] != 'W') 
            return false;
    }


    if(mo != mw || mc != mw) return false;
    
    label[m++] = len_input;
    for(int i = 0;i < m-1;i++)
    {
        if(label[i] + 1 < label[i+1])
        {
            if(!find_sub(label[i]+1, label[i+1]-1))
            {
                return false;
            }
        }
    }

    strcpy(tmp, input);
    for(int j = 0;j < mo;j++)
    {
        for(int i = 0;i < mc;i++)
        {
            for(int k = 0;k < mw;k++)
            {
                if(c[i] < o[j] && o[j] < w[k]);
                else continue;

                product(c[i], o[j], w[k]);
                len_input -= 3;

                if(p == ret - 1)
                {
                    if(strcmp(input, raws) == 0)
                        return true;
                }
                if(go(p+1)) return true;
                len_input += 3;
                strcpy(input, tmp);
            }
        }
    }
    return false;
}
int main()
{
#ifdef HOME
    freopen("cryptcow.in", "r", stdin);
    freopen("cryptcow.out", "w", stdout);
#endif
    len = strlen(raws);

    for(int i = 0;i < len;i++) cnt[(int)raws[i]] ++;
    scanf("%[^\n]s", input);
    len_input = strlen(input);

    ret = (len_input - len);
    if(ret % 3)
    {
        cout<<"0 0"<<endl;

        return 0;
    }
    ret /= 3;

    cnt['C'] += ret;
    cnt['O'] += ret;
    cnt['W'] += ret;

    bool ok = true;
    for(int i = 0;i < len_input;i++)
    {
        cnt[(int)input[i]] --;
        if(cnt[(int)input[i]] < 0)
        {
            ok = false;

            break;
        }
    }
    if(!ok)
        cout<<"0 0"<<endl;
    else if(strcmp(input, raws) == 0) 
        cout<<"1 0"<<endl;
    else if(go(0))
        cout<<1<<" "<<ret<<endl;
    else
        cout<<"0 0"<<endl;

    return 0;
}

