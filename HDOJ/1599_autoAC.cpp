#include<stdio.h>
#include<string.h>
int map[300][300];
int dist[300][300];
int n,m;
int ans;
void floyd()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dist[i][j]=map[i][j];
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j&&j!=k&&k!=i&&dist[i][j]!=2000000000&&map[j][k]!=2000000000&&map[k][i]!=2000000000&&ans>dist[i][j]+map[j][k]+map[k][i])
                {
                    ans=dist[i][j]+map[j][k]+map[k][i];
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][k]!=2000000000&&dist[k][j]!=2000000000&&dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    return;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i!=j)
                {
                    map[i][j]=2000000000;
                }
                else
                {
                    map[i][j]=0;
                }
            }
        }
        while(m--)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(a!=b&&map[a][b]>c)
            {
                map[a][b]=c;
                map[b][a]=c;
            }
        }
        ans=2000000000;
        floyd();
        if(ans==2000000000)
        {
            printf("It's impossible.\n");
        }
        else
        {
            printf("%d\n",ans);
        }
    }
    return 0;
}
