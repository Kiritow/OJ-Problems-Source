#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
__int64 a,b,k,num,dp[20][25],d[20][25],C[20],r[20][25],A[20];
__int64 dfs(__int64 now,__int64 left)
{
    if(now<0) return 0;
    __int64 sum=0,i,j,ii;
    for(i=0;i<A[now];i++)
        r[now][(left*10+i)%k]++;
    for(j=0;j<k;j++)
    {
        for(i=0;i<10;i++)
            r[now][(j*10+i)%k]+=r[now+1][j];
        ii=r[now+1][j];
        if(!j&&ii>0) ii--;
        sum+=ii*dp[now][((k-j)%k+k)%k];
    }
    if(now!=num)
        sum+=d[now][((k-left)%k+k)%k];
    sum+=dfs(now-1,(left*10+A[now])%k);
    return sum;
}
void dfs2()
{
    __int64 i,j,now;
    memset(C,0,sizeof(C));
    C[0]=1%k;
    for(i=1;i<18;i++)
        C[i]=(C[i-1]*10)%k;
    for(i=0;i<=A[0];i++)
        d[0][i%k]++;
    for(now=1;now<=num;now++)
    {
        for(j=0;j<k;j++)
        {
            d[now][(A[now]*C[now]+j)%k]+=d[now-1][j];
            for(i=0;i<A[now];i++)
                d[now][(i*C[now]+j)%k]+=dp[now-1][j];
        }
    }
}
__int64 Cal(__int64 a)
{
    __int64 i=0;
    while(a)
    {
        A[i++]=a%10;
        a/=10;
    }
    num=i-1;
    memset(d,0,sizeof(d));
    memset(r,0,sizeof(r));
    dfs2();
    return dfs(num,0);
}
int main()
{
    __int64 i,j,ii;
    while(scanf("%I64d%I64d%I64d",&a,&b,&k)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(i=0;i<10;i++)
            dp[0][i%k]++;
        for(i=1;i<18;i++)
            for(ii=0;ii<k;ii++)
                for(j=0;j<=9;j++)
                    dp[i][(ii*10+j)%k]+=dp[i-1][ii];
        printf("%I64d\n",Cal(b)-Cal(a-1));
    }
    return 0;
}
