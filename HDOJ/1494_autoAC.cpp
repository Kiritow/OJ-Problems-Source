#include <iostream>
#include <stdio.h>
#include <algorithm> 
using namespace std; 
int dp[11000][16],a[110],b[110];
inline void fun(int &x,int y)
{
    if(x == 0)x=y;
    else x=min(x,y);
}
int main()
{
    int len,n,i,j,k,ans;
    while(~scanf("%d %d",&len,&n))
    {
        for(i=1;i<=len;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1;i<=len;i++)
        {
            scanf("%d",&b[i]);
        }
        memset(dp,0,sizeof(dp));
        dp[1][1]=a[1];
        for(i=0;i<n;i++)
        {
            for(j=1;j<=len;j++)
            {
                if(i == 0 && j == 1)continue;
                for(k=0;k<15;k++)
                {
                    if(dp[i*len+j-1][k])
                    {
                        if(k>=5 && k<14)
                        {
                            fun(dp[i*len+j][k+1],dp[i*len+j-1][k]+a[j]);
                            fun(dp[i*len+j][k-5],dp[i*len+j-1][k]+b[j]);
                        }
                        else if(k == 14)
                        {
                            fun(dp[i*len+j][10],dp[i*len+j-1][k]+a[j]);
                            fun(dp[i*len+j][k-5],dp[i*len+j-1][k]+b[j]);
                        }
                        else 
                        {
                            fun(dp[i*len+j][k+1],dp[i*len+j-1][k]+a[j]);
                        }
                    }
                }
            }
        }
        ans=99999999;
        for(i=0;i<15;i++)
        {
            if(dp[n*len][i] && dp[n*len][i]<ans)ans=dp[n*len][i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
