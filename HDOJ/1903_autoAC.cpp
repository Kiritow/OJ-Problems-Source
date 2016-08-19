#include<iostream>
#include<math.h>
using namespace std;
int const MAX =0x3f3f3f3f;
double dp[2][366];
double exchange[366];
double commissionRate = 0.97;
int mask =100;
int main()
{
    int days=0;
    while(scanf("%d",&days) && days !=0 )
    {
        memset(dp,-MAX,sizeof(dp));
        dp[0][1]=100000.0;
        for(int i=1;i<=days;i++ )
            scanf("%lf",&exchange[i]);
        dp[1][1] = (dp[0][1]/exchange[1])*commissionRate;
        for(int i=2;i<=days;i++)
        {
            if(dp[0][i-1] > dp[1][i-1]*exchange[i]*commissionRate)
                dp[0][i] = (int)dp[0][i-1]+0.0;
            else
                dp[0][i] =(int)(dp[1][i-1]*exchange[i]*commissionRate)+0.0;
            if(dp[1][i-1] > (dp[0][i-1]/exchange[i])*commissionRate)
                dp[1][i] = (int)(dp[1][i-1])+0.0;
            else
                dp[1][i] =(int)((dp[0][i-1]/exchange[i])*commissionRate)+0.0;
        }
        printf("%.2lf\n",dp[0][days]/100);  
    }
    return 0;
}
