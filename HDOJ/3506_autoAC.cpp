#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxx=2002;
int dp[maxx][maxx],mark[maxx][maxx],sum[maxx][maxx];
int data[maxx];
int min(int a,int b){
    return a<b?a:b;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&data[i]);
            data[i+n]=data[i];
        }
        memset(sum,0,sizeof(sum));
        for (int i=1;i<2*n;i++)
        {
            dp[i][i]=0;
            mark[i][i]=i;
            for (int j=i;j<=n+i;j++)
            {
                sum[i][j]=sum[i][j-1]+data[j];
            }
        }
        for (int st=2;st<=n;st++)
        {
            for (int i=1;i+st<=2*n+1;i++)
            {
                int j=i+st-1;
                dp[i][j]=99999999;
                for (int k=mark[i][j-1];k<=mark[i+1][j];k++)
                {
                    int temp=dp[i][k]+dp[k+1][j]+sum[i][j];
                    if (dp[i][j]>temp)
                    {
                        dp[i][j]=temp;
                        mark[i][j]=k;
                    }
                }
            }
        }
        int ans=9999999;
        for (int i=1;i<=n;i++)
        {
            ans=min(ans,dp[i][i+n-1]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
