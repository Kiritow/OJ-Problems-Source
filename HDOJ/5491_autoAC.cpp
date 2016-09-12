#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
#include <vector>
#include <sstream>
#include <queue>
#include <typeinfo>
#include <fstream>
#include <map>
#include <stack>
typedef long long ll;
using namespace std;
#define sspeed ios_base::sync_with_stdio(0);cin.tie(0)
#define maxn 300006
#define mod 1000000007
#define eps 1e-9
#define e exp(1.0)
#define PI acos(-1)
const double EP  = 1E-10 ;
int Num;
const ll inf=999999999;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int get(ll x)
{
    int c =0 ; 
    while (x >0)
    {
        if((x &1) ==1) 
            c++; ; 
        x >>=1 ; 
    }
    return c ;
}
ll change(ll x,int num)
{
    for(int i=0;i<132;i++)
    {
        if((x&(1LL<<i))==0)
        {
            x|=(1LL<<i);
            num--;
        }
        if(num==0)
            break;
    }
    return x;
}
ll change2(ll x,int K,int s1,ll P)
{
    int l =0;
    for(int i=0;i<132;i++)
    {
        if((x&(1LL<<i))==0)
        {
            x|=(1LL<<i);
            l = i;
            break;
        }
    }
    int num = K+1;
    for(int i = l-1;i>=0;i--)
    {
        x-=(1LL<<i);
        num--;
        if(num==s1)
            break;
    }
    if(x>P*2)return P;
    return x;
}
int main()
{
    int t;scanf("%d",&t);
    for(int cas = 1;cas <= t;cas ++)
    {
        ll a=read(),s1=read(),s2=read();
        ll ans = a+1;
        printf("Case #%d: ",cas);
        int len = get(ans);
        if(len<=s2&&len>=s1)
        {
            printf("%I64d\n",ans);
            continue;
        }
        if(len<s1)
        {
            printf("%I64d\n",change(ans,s1-len));
            continue;
        }
        if(len>s2)
        {
            while(len>s2)
            {
                ans = change2(ans,len,s1,a);
                len = get(ans);
            }
            printf("%I64d\n",ans);
        }
    }
}
