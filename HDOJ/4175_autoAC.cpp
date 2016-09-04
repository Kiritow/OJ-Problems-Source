#include <iostream>
#include <string.h>
#include <cstdio>
#include <math.h>
using namespace std;
struct point
{
    int pos,value;
}pp[27][1010];
int dp[27][1010];
int main()
{
    int numcase;
    scanf("%d",&numcase);
    for(int k = 1;k <= numcase;++k)
    {
        int numl,numc,len,i,j,p;
        memset(dp,0,sizeof(dp));
        scanf("%d%d%d",&numl,&numc,&len);
        for(i = 1;i <= numl;++i)
        {
            for(j = 1;j <= numc;++j)
            {
                scanf("%d%d",&pp[i][j].pos,&pp[i][j].value);
            }
        }
       int mmin = 200000000;
       for(i = 1;i <= numl;++i)
       {
           for(j = 1;j <= numc;++j)
           {
               mmin = 200000000;
               for(p = 1;p <= numc;++p)
               {
                   dp[i][j] = dp[i-1][p] + abs(pp[i][j].pos - pp[i-1][p].pos) + pp[i][j].value;
                   if(dp[i][j] < mmin)
                   {
                       mmin = dp[i][j];
                   }
               }
               dp[i][j] = mmin;
             }
       }
       mmin = 200000000;
       for( i = 1;i <= numc;++i)
       {
           dp[numl][i] = dp[numl][i] + abs(len - pp[numl][i].pos);
           if(dp[numl][i] < mmin)
           {
               mmin = dp[numl][i];
           }
       }
       printf("%d\n",mmin);
    }
    return 0;
}
