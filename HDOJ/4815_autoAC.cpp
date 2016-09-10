#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int dp[40100],po[50];
long long need,all;
int main()
{
    int n,i,j,t,sum;
    double p;
    scanf("%d",&t);
    while(t--)
    {
        need=sum=all=0;
        scanf("%d%lf",&n,&p);
        for(i=0;i<n;i++)
            scanf("%d",&po[i]),sum+=po[i];
        memset(dp,0,sizeof dp);
        dp[0]=1,all=1LL<<n;
        for(i=0;i<n;i++)
            for(j=sum;j>=po[i];j--)
                if(dp[j-po[i]])
                    dp[j]+=dp[j-po[i]];
       need=ceil(all*p);
       for(i=0,all=0;i<=sum;i++)
       {
           all+=dp[i];
           if(all>=need)
           {
               printf("%d\n",i);
               break;
           }
       }
    }
    return 0;
}
