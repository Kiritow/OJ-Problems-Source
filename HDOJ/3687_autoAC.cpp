#include "stdio.h"
#include "string.h"
#include "iostream"
#include "algorithm"
using namespace std;
int inf=0x3f3f3f3f;
int Fabs(int a)
{
    if (a<0) return -a; else return a;
}
int Min(int a,int b)
{
    if (a<b) return a;
    else return b;
}
struct node
{
    int num;
    int x[210];
}mark[210];
int main()
{
    int n,m,i,j,k,sum,ans;
    int dp[210][210];
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if (n==0 && m==0) break;
        memset(mark,0,sizeof(mark));
        for (i=1;i<=n*n;i++)
        {
            scanf("%d%d",&j,&k);
            mark[j].num++;
            mark[j].x[mark[j].num]=k;
        }
        for (i=1;i<=n;i++)
            sort(mark[i].x+1,mark[i].x+1+n);
        memset(dp,0,sizeof(dp));
        for (i=1;i<=n;i++)
            for (j=1;j<=m-n+1;j++)
                for (k=1;k<=n;k++)
                    dp[i][j]+=Fabs(mark[i].x[k]-j-k+1);
        ans=inf;
        for (j=1;j<=m-n+1;j++)
        {
            sum=0;
            for (i=1;i<=n;i++)
                sum+=dp[i][j];
            ans=Min(sum,ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
