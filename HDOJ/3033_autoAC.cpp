#include<stdio.h>
#include<string.h>
int dp[15][10010];
int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
int main()
{
    int i,j,n,m;
    int k,T,num[15],v[15][151],c[15][150];
    while(scanf("%d%d%d",&n,&m,&T)!=EOF)
    {
        memset(v,0,sizeof(v));
        memset(c,0,sizeof(c));
        memset(num,0,sizeof(num));
        memset(dp,-1,sizeof(dp));
        memset(dp[0],0,sizeof(dp[0]));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&j);
            num[j]++;
            scanf("%d%d",&c[j][num[j]],&v[j][num[j]]);
        }
        for(i=1;i<=T;i++)
        {
            for(k=1;k<=num[i];k++)
            for(j=m;j>=c[i][k];j--) 
            {
                if(dp[i][j-c[i][k]]!=-1)
                dp[i][j]=max(dp[i][j],dp[i][j-c[i][k]]+v[i][k]);
            if(dp[i-1][j-c[i][k]]!=-1)
                dp[i][j]=max(dp[i][j],dp[i-1][j-c[i][k]]+v[i][k]);
            }
        }
        if(dp[T][m]<0)
        printf("Impossible\n");
        else
        printf("%d\n",dp[T][m]); 
    }
    return 0;
}
