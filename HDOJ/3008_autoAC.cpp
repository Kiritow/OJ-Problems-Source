#include<iostream>
#include<algorithm>
using namespace std;
#define inf 110
int dp[inf][inf];
#define Max(a,b) a>b?a:b
struct node
{
    int ai,bi;
}b[inf];
int cmp(struct node a,struct node b){return a.ai<b.ai;}
int main()
{
    int n,p,t,i,j;
    while(cin>>n>>t>>p)
    {
        if(n==0&&t==0&&p==0)
            break;
        memset(b,0,sizeof(b));
        for(i=1;i<=n;i++)
            scanf("%d%d",&b[i].ai,&b[i].bi);
        sort(b+1,b+n+1,cmp);
        b[0].ai=0;
        b[0].bi=1;
        b[n+1].bi=b[n+1].ai=100;
        memset(dp,0,sizeof(dp));
        int T=(100+p-1)/p;
        int k;
        for(i=1;i<=T;i++)
        {
            for(j=0;j<=100;j++)
            {
                int max=0;
                for(k=0;k<=n;k++)
                {
                    if(b[k].ai+j>100)
                        break;
                    max=Max(max,dp[i-1][j+b[k].ai]+b[k].bi);
                }
                dp[i][j]=max;
            }
            for(j=99;j>100-t;j--)
            dp[i][100]=Max(dp[i][j],dp[i][100]);
            for(j=100-t;j>=0;j--)
            dp[i][j+t]=Max(dp[i][j],dp[i][j+t]);
        }
     for(i=1;i<=T;i++)
     {
         for(j=0;j<=100;j++)
         if(dp[i][j]>=100)
             break;
         if(j<=100)
         {printf("%d\n",i);break;}
     }
     if(i>T)printf("My god\n");
    }
    return 0;
}
