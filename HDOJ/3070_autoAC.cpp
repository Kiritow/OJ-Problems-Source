#include<iostream>
#include<string.h>
using namespace std;
#define MAXN 150
#define MOD 20090829
__int64 dp[MAXN][MAXN],c[MAXN][MAXN];
__int64 a[MAXN];
__int64 b[MAXN];
int gcd(int x,int y)
{
    if (y==0) return x;
    else return gcd(y,x%y);
}
__int64 C(int k,int n)
{
    int i,j;
    if (c[k][n]!=0) return c[k][n];
    __int64 temp,ans;
    for(i=n-k+1;i<=n;i++) a[i]=i;
    for(i=1;i<=k;i++) b[i]=i;
    for(i=1;i<=k;i++)
      for(j=n-k+1;j<=n;j++)
            {
               temp=gcd(b[i],a[j]);
               b[i]/=temp;
               a[j]/=temp;
            }
        ans=1;
        for(i=n-k+1;i<=n;i++)
            ans=ans*a[i]%MOD;
        c[k][n]=ans;
        return ans;
}
int min(int x,int y)
{
    if (x<y) return x;
    else return y;
}
int main()
{
    int n,d,i,j,k;
    __int64 ans;
    memset(c,0,sizeof(c));
    while(scanf("%d %d",&n,&d)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(i=1;i<=n;i++)
            for(j=0;j<=n-2;j++)
                for(k=0;k<=min(j,d-1);k++)
                {
                    dp[i][j]=(dp[i][j]+dp[i-1][j-k]*C(k,n-2-(j-k)))%MOD;
                }
        ans=dp[n][n-2];
        printf("%I64d\n",ans);
    }
}
