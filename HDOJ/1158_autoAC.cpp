#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int dp[15][99999];
int main()
{
    int n,i,j,salary,hire,fire,num[15],Min,Max,k,a,b;
    while(~scanf("%d",&n),n)
    {
        scanf("%d%d%d",&hire,&salary,&fire);
        Min=99999;
        Max=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            if(num[i]<Min) Min=num[i];
            if(num[i]>Max) Max=num[i];
        }
        for(i=0;i<=n;i++)
        for(j=Min;j<=Max;j++)
        {if(i==0)dp[i][j]=0;else dp[i][j]=546548;}
        for(i=1;i<=n;i++)
        {
            for(j=num[i];j<=Max;j++)
            {
                if(i==1)
                {
                    dp[i][j]=dp[i-1][j]+j*(hire+salary);
                }
                else
                {
                    for(k=num[i-1];k<=Max;k++)
                    {
                        a=dp[i-1][k];
                        b=j*salary;
                        if(j>=k)
                        {
                            dp[i][j]=min(dp[i][j],a+(j-k)*hire+b);
                        }
                        else 
                        {
                            dp[i][j]=min(dp[i][j],a+(k-j)*fire+b);
                        }
                    }
                }
            }    
        }
        a=546548;
        for(i=num[n];i<=Max;i++)
        if(dp[n][i]<a) a=dp[n][i];
        printf("%d\n",a);
    }
    return 0;
}
