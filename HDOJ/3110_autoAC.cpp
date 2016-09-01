#include<iostream>
using namespace std;
int dp[1010][1010], price[1010],need[1010];
int main()
{
    int week,basecost,cell,storecost,i,j,k,min,mini;
    while(cin>>week)
    {
        if(week==0)
            break;
        cin>>basecost>>storecost>>cell;
        for(i=1;i<=week;i++)
            cin>>price[i]>>need[i];
        for(j=0;j<=cell;j++)
        {
            dp[1][j]=(j+need[1])*price[1]+basecost+j*storecost;
            if(need[1]==0)
                         dp[1][0]=0;  
        }
        for(i=2;i<=week;i++)
            for(j=0;j<=cell;j++)
            {
                min=10000000;
                for(k=0;k<=cell;k++)
                {
                    if(k<=j+need[i])
                    {
                        if(j==k-need[i])
                            mini=dp[i-1][k]+j*storecost;
                        else mini=dp[i-1][k]+basecost+(j-k+need[i])*price[i]+j*storecost;
                        if(mini<min)
                            min=mini;
                    }
                }
                dp[i][j]=min;
            }
        min=dp[week][0];
        for(i=1;i<=cell;i++)
            if(dp[week][i]<min)
                min=dp[week][i];
        cout<<min<<endl;
    }
    return 0;
}
