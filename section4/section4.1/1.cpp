
/*
ID: wengsht1
LANG: C++
TASK: cryptcow
*/
#include <iostream>
#include <memory.h>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 100;
const int MOD = 131071;
const int LEN = 47;
const string plaintext = "Begin the Escape execution at the Break of Dawn";

ifstream fin("cryptcow.in");
ofstream fout("cryptcow.out");

bool visited[MOD+1];

inline bool ELFHash(string s, int length){
    unsigned long h=0,g;
    for (int i=0; i<length; i++){
        h=(h<<4)+s[i];
        g=h&0xf0000000l;
        if(g){
            h^=g>>24;
        }
        h&=~g;
    }

    h = h%MOD;

    if(visited[h])
        return true;
    else{
        visited[h] = true;
        return false;
    }
}

void dfs(string s, int num){

    if(plaintext == s){
        fout<<1<<" "<<num<<endl;
        exit(0);
    }

    int length = s.length();

    if(ELFHash(s, length)) return ;

    
    int cnt=0, c_cnt=0, o_cnt=0, w_cnt=0;
    int c[MAX], o[MAX], w[MAX], label[MAX];
    memset(c, 0, sizeof(c));
    memset(o, 0, sizeof(o));
    memset(w, 0, sizeof(w));
    memset(label, 0, sizeof(label));

    int i,j,k;
    label[cnt++] = -1;
    for(i = 0; i<length; ++i){
        if(s[i] == 'C'){

            c[c_cnt++] = i;
            label[cnt++] = i;

        }else if(s[i] == 'O'){

            o[o_cnt++] = i;
            label[cnt++] = i;

        }else if(s[i] == 'W'){

            w[w_cnt++] = i;
            label[cnt++] = i;
        }
    }
    label[cnt++] = length;

    if(c_cnt!=o_cnt || o_cnt!=w_cnt)
        return;


    for(i=0; i<cnt-1; ++i){
        if(label[i]+1 < label[i+1]){
            string sub = s.substr(label[i]+1, label[i+1]-label[i]-1);
            if(plaintext.find(sub)==string::npos)
                return;
        }
    }

    for(i=0; i<o_cnt; ++i){
        for(j=0; j<c_cnt; ++j){
            for(k=w_cnt-1; k>=0; --k){
                if(c[j]<o[i] && o[i]<w[k]){
                    string t1 = s.substr(0, c[j]);
                    string t2 = s.substr(o[i]+1, w[k]-o[i]-1);
                    string t3 = s.substr(c[j]+1, o[i]-c[j]-1);
                    string t4 = s.substr(w[k]+1, length-w[k]);
                    string t = t1+t2+t3+t4;
                    dfs(t, num+1);
                }
            }
        }
    }
}

int main(){

    string s;

    getline(fin, s);

    int length = s.length();

    if( (length-LEN)%3 !=0 ){
        fout<<"0 0"<<endl;
        return 0;
    }

    dfs(s,0);

    fout<<"0 0"<<endl;

    return 0;
}
