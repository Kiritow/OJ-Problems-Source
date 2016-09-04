#include<iostream>
#include<cmath>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<ctime>
#include<bitset>
#define eps 1e-6
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define ll __int64
#define LL long long
#define lson l,m,(rt<<1)
#define rson m+1,r,(rt<<1)|1
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
#define Maxn 55
#define m 30
#define M 1000000003
int sa[Maxn],n,k,num;
ll sum[m+5];
ll dp[Maxn][Maxn],bina[m+5];
void init()
{
    bina[0]=1;
    for(int i=1;i<=m;i++)
        bina[i]=bina[i-1]*2;
}
int Sum1(ll tmp)
{
    int res=0;
    for(int i=1;i<=n;i++)
        if(sa[i]&tmp)
            res++;
    return res;
}
ll left(int a,int b) 
{
    if(!b)
        return 1; 
    else
        return (sa[a]&(bina[b]-1))+1; 
}
ll Cal(int pos,int num,int s,int need)
{
    if(s==0)
    {
        if((num&1)!=need) 
            return 0;
        else
        {
            if(pos==0) 
                return 1;
            else  
                return sum[pos-1];
        }
    }
    dp[0][0]=1; 
    for(int i=1;i<=n;i++)
        for(int j=0;j<num;j++)
        {
            dp[i][j]=0;
            if(bina[pos]&sa[i]) 
            {
                if(i==s)
                    dp[i][j]=dp[i-1][j]%M;
                else if(i>s) 
                    dp[i][j]=(dp[i-1][j]*bina[pos])%M; 
            }
            else 
                dp[i][j]=(dp[i-1][j]*left(i,pos))%M; 
            if(bina[pos]&sa[i]) 
            {
                if(i!=s)
                {
                    if(j)
                        dp[i][j]=(dp[i][j]+dp[i-1][j-1]*left(i,pos))%M;
                }
            }
        }
    ll res=0;
    for(int i=0;i<num;i++)
        if((i&1)==need) 
            res=(res+dp[n][i])%M;
    return res;
}
int main()
{
    init();
    while(~scanf("%d%d",&n,&k))
    {
        if(n+k==0)
            break;
        for(int i=1;i<=n;i++)
            scanf("%d",&sa[i]);
        memset(sum,0,sizeof(sum));
        for(int pos=0;pos<=m;pos++) 
        {
            ll tmp=bina[pos];
            num=Sum1(tmp);
            int need;
            if(k&tmp)
                need=1;
            else
                need=0;
            for(int i=0;i<=n;i++)
                if(!i||(tmp&sa[i]))
                    sum[pos]=(sum[pos]+Cal(pos,num,i,need))%M;
        }
        printf("%I64d\n",sum[m]);
    }
   return 0;
}
