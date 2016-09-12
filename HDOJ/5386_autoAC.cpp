#include "stdio.h"
#include "string.h"
struct Mark
{
    int x,y;
    char op;
}mark[510];
int a[110][110],ans[510];
int main()
{
    int t,n,m,i,cnt,j,k;
    char str[2];
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
        for (i=1;i<=m;i++)
        {
            scanf("%s%d%d",str,&mark[i].x,&mark[i].y);
            mark[i].op=str[0];
        }
        cnt=m;
        while (cnt!=0)
        {
            for (i=1;i<=m;i++)
                if (mark[i].x!=0)
                {
                    k=mark[i].x;
                    if (mark[i].op=='H')
                    {
                        for (j=1;j<=n;j++)
                            if (a[k][j]!=0 && a[k][j]!=mark[i].y) break;
                        if (j==n+1)
                        {
                            for (j=1;j<=n;j++)
                                a[k][j]=0;
                            mark[i].x=0;
                            ans[cnt--]=i;
                        }
                    }
                    else
                    {
                        for (j=1;j<=n;j++)
                            if (a[j][k]!=0 && a[j][k]!=mark[i].y) break;
                        if (j==n+1)
                        {
                            for (j=1;j<=n;j++)
                                a[j][k]=0;
                            mark[i].x=0;
                            ans[cnt--]=i;
                        }
                    }
                }
        }
        for (i=1;i<=m;i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
