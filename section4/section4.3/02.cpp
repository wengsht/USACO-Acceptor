
/*
ID: wengsht1
LANG: C++
TASK: buylow
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define HOME 

const int size = 101; //第一位(s[0])标记有效位数，最后一位标记符号位
const int CI = 10000; //数组每位考虑乘法只能设那么大
int  s1[size],s2[size],s3[size],s4[size],s5[size],s6[size];   // s1 op s2 = s3 s1 % s2 = s4   
															  //!! 实际上乘法时size不可能全用，想少bug把size调大就可以了
                                                              // s5/s6用于除法中暂存数据
char ss[size+1];      //接收输入
int d[4] = { 1,10,100,1000 };

bool _less( int s1[],int s2[] )   //减法、除法比较时用
{  
    if( s1[0] != s2[0] ) return s1[0] < s2[0];
    for( int i = s1[0];i >= 1;i-- )
    {
        if( s1[i] != s2[i] ) return s1[i] < s2[i] ;
    }
    return false;
}
bool nolarger( int s1[],int s2[] )
{
    if( s1[0] != s2[0] ) return s1[0] < s2[0];
    for( int i = s1[0];i >= 1;i-- )
    {
        if( s1[i] != s2[i] ) return s1[i] < s2[i] ;
    }
    return true;
}
void Left_move( int s[] )          //左移s = s * 10000
{
	if( s[s[0]] == 0 ) return ;
	int l = ++s[0];
	for( ;l > 1;l-- ) s[l] = s[l-1];
	s[1] = 0;
}
void AtoI( int s[],char *ss )      //将ss 格式为int[]
{
	memset( s,0,sizeof(s)*size ); s[0] = 1; 
	int l = strlen( ss );
	if( ss[0] == '-' )  //处理下输入的负数，
		                //只在* /中利用，+ - 法就不用了吧= = 挺容易在主函数中处理的
	{
		s[size-1] = 1;
		for( int i = 0;i < l-1;i++ ) ss[i] = ss[i+1]; 
		l--;
	}
	int j = 0; //CI为,满进
	for( int i = l-1;i >= 0;i-- )
	{
		s[s[0]] = s[s[0]] + (ss[i]-'0') * d[j++];
		if( j > 3 && i > 0) { j = 0;s[0]++; } 
	}
}
void outputf( int s[] )   //格式化输出
{
	if( s[size-1] ) cout<<'-'; 
	int i = s[0];
	cout<<s[i];
	for( i--;i >= 1;i-- ) cout<<setfill( '0' )<<setw(4)<<s[i];  //非最高位要补齐
}

void add( int s1[],int s2[],int s3[] )  //s1 + s2 = s3
{
	memset( s3,0,sizeof(int)*size );
	
	int i = 1;
	while( i <= s1[0] || i <= s2[0] ) 
	{
		s3[i] += ( s1[i] + s2[i] );
		if( s3[i++] >= CI )
		{
			s3[i]++;
			s3[i-1] -= CI;
		}
	}
	s3[0] = s3[i] > 0 ? i:i-1;
}
void addto( int s1[],int s2[] )  //s1 += s2
{
	int i = 1;
	while( i <= s1[0] || i <= s2[0] ) 
	{
		s1[i] +=  s2[i] ;
		if( s1[i++] >= CI )
		{
			s1[i]++;
			s1[i-1] -= CI;
		}
	}
	s1[0] = s1[i] > 0 ? i:i-1;
}


struct BigNum
{
    int nums[size];
}dp[5005];

#define MX 100000
int N, M, K;
int mx = 0;
unsigned int s[5005];

int binary[5005];

vector<int> lens[5005];
int ret;

int _find(int l, int h, int t)
{
    int ans = h + 1;

    while(l <= h)
    {
        int mid = l + (h-l) / 2;

        if(binary[mid] <= t)
        {
            ans = mid;

            h = mid - 1;
        }
        else 
            l = mid + 1;
    }
    return ans;
}
int main()
{
#ifdef HOME
    freopen("buylow.in", "r", stdin);
    freopen("buylow.out", "w", stdout);
#endif
    AtoI(s1, "1");
    cin>>N;

    for(int i = 0;i < N;i++)
        cin>>s[i];

    binary[1] = s[0];
    lens[1].push_back(0);
    AtoI(dp[0].nums, "1");
    ret = 1;

    for(int i = 1;i < N;i++)
    {
        int p = _find(1, ret, s[i]);

        bool ok = false;
        if(s[i] > binary[p])
            binary[p] = s[i];

        if(ret < p) ret = p;

        if(p == 1) 
        {
            AtoI(dp[i].nums, "1");
        }

        for(int j = 0;j < lens[p-1].size();j++)
        {
            if(s[lens[p-1][j]] > s[i])
            {
                addto(dp[i].nums, dp[lens[p-1][j]].nums);
            }
        }
        for(int j = 0;j < lens[p].size();j++)
        {
            if(s[lens[p][j]] == s[i])
            {
                memcpy(dp[lens[p][j]].nums, dp[i].nums, sizeof(dp[i].nums));

                ok = true;

                break;
            }
        }
        if(!ok) lens[p].push_back(i);

    }
    BigNum ans;
    AtoI(ans.nums, "0");
    for(int i = 0;i < lens[ret].size();i++)
    {
        addto(ans.nums, dp[lens[ret][i]].nums);
    }
    cout<<ret<<" ";
    outputf(ans.nums);
    cout<<endl;

    return 0;
}

