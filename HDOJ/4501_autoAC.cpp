#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[2][105][105][10];
int val[105];
int c1[105];
int c2[105];
int main()
{
    int n,v1,v2,k;
    while(scanf("%d%d%d%d",&n,&v1,&v2,&k)!=EOF)
    {
        int i;
        for(i=1;i<=n;i++)
            scanf("%d%d%d",&c1[i],&c2[i],&val[i]);
        memset(dp,0,sizeof(dp));
        int now=0;
        for(i=1;i<=n;i++)
        {
            now=now^1;
            for(int j=0;j<=v1;j++)
            {
                for(int l1=0;l1<=v2;l1++)
                {
                    for(int l2=0;l2<=k;l2++)
                    {
                        dp[now][j][l1][l2]=dp[now^1][j][l1][l2];
                        if(j>=c1[i]&&dp[now][j][l1][l2]<dp[now^1][j-c1[i]][l1][l2]+val[i])
                            dp[now][j][l1][l2]=dp[now^1][j-c1[i]][l1][l2]+val[i];
                        if(l1>=c2[i]&&dp[now][j][l1][l2]<dp[now^1][j][l1-c2[i]][l2]+val[i])
                            dp[now][j][l1][l2]=dp[now^1][j][l1-c2[i]][l2]+val[i];
                        if(l2>=1&&dp[now][j][l1][l2]<dp[now^1][j][l1][l2-1]+val[i])
                            dp[now][j][l1][l2]=dp[now^1][j][l1][l2-1]+val[i];
                    }
                }
            }
        }
        printf("%d\n",dp[now][v1][v2][k]);
    }
}
