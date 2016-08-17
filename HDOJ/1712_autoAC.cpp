#include<stdio.h>
#include<string.h>
int max(int x,int y)
{
    if(x>=y)
        return x;
    return y;
}
int main()
{
    int m,n,i,j,k,d[105],a[105][105];
    while(scanf("%d%d",&n,&m)==2)
    {
        if(m==0&&n==0)    break;
        memset(d,0,sizeof(d));
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        for(i=1;i<=n;i++)
            for(j=m;j>=1;j--)
            {
                for(k=1;k<=j;k++)
                    d[j]=max(d[j],d[j-k]+a[i][k]);
            }
        printf("%d\n",d[m]);
    }
    return 0;
}
