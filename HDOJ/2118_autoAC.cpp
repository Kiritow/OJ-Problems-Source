#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int energy[205][2105];
int f[205][2105];
int dx[4]={1,0,1,2};
int dy[4]={0,1,2,1};
int n,m,K;
void dp()
{
    int i,j,k;
    f[1][1]=energy[1][1];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=(i-1)*m+1;j++)if(f[i][j]-K>0)
        {
            for(k=0;k<4;k++)
            {
                int xx=i+dx[k];
                int yy=j+dy[k];
                if(yy<=(xx-1)*m+1&&(f[xx][yy]==-1||f[xx][yy]<f[i][j]-K+energy[xx][yy]))
                {
                    f[xx][yy]=f[i][j]-K+energy[xx][yy];
                }
            }
        }
    }
    int ans=-1;
    for(i=1;i<=(n-1)*m+1;i++)
    {
        if(f[n][i]>0&&(ans<0||ans>f[n][i]))ans=f[n][i];
    }
    if(ans>0)printf("%d\n",ans);
    else printf("what a pity mouse!!\n");
}
int main()
{
    int i,j;
    while(scanf("%d %d %d",&n,&m,&K)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=(i-1)*m+1;j++)
            {
                scanf("%d",&energy[i][j]);
                f[i][j]=-1;
            }
        }
        dp();
    }
    return 0;
}
