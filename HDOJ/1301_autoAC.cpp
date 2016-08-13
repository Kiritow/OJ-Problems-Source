#include <stdio.h>
#include <string.h>
#define inf 0x6fffff
int dis[105];
int map[105][105];
int vis[105];
int sum,n;
void prim()
{
    int i,j,k,min;
    for(i=1;i<=n;i++)
        dis[i]=map[1][i];
    vis[1]=1;
    for(i=1;i<=n;i++)
    {
        min=inf;
        for(j=1;j<=n;j++)
        {
            if(vis[j]==0 &&dis[j]<min)
            {
                min=dis[j];
                k=j;
            }
        }
        if(min==inf)
            break;
        vis[k]=1;
        sum+=min;
        for(j=1;j<=n;j++)
        {
            if(vis[j]==0 &&dis[j]>map[k][j])
                dis[j]=map[k][j];
        }
    }
}
int main()
{
    int i,j,a,l;
    char b[22],b1[22];
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                map[i][j]=inf;
            for(i=1;i<=n-1;i++)
            {
                scanf("%s",b);
                scanf("%d",&a);
                for(j=1;j<=a;j++)
                {
                    scanf("%s",b1);
                    scanf("%d",&l);
                    map[b[0]-'A'+1][b1[0]-'A'+1]=map[b1[0]-'A'+1][b[0]-'A'+1]=l;
                }
                getchar();
            }
            memset(vis,0,sizeof(vis));
            sum=0;
            prim();
            printf("%d\n",sum);
    }
    return 0;
}
