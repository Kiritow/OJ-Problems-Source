#include<stdio.h>
int main()
{
    while(1)
    {
        __int64 dp[105][105]={0};__int64 l;
        int n,m,i,j,k,a[105];
        scanf("%d %d",&n,&m);
        if(n==0&&m==0)
            return 0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++)
        {
            dp[i][1]=1;
        }
        for(i=2;i<=n;i++)
        {
            for(j=2;j<=m;j++)
            {
                for(k=1;k<i;k++)
                {
                    if(a[i]>a[k])
                    {
                        dp[i][j]+=dp[k][j-1];
                    }
                }
            }
        }
        l=0;
        for(i=m;i<=n;i++)
        {
            l+=dp[i][m];
        }
        printf("%I64d\n",l);
    }
    return 0;
}
