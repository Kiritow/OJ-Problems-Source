#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N=105;
const int inf=(1<<30);
int n,m;
double a[N];
bool mat[N][N];
bool vis[N];
int indgree[N];
void floyd()
{
    for(int k=1;k<=n;k++)
      for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          if(i!=j&&mat[i][k]&&mat[k][j])
          {
              mat[i][j]=true;
          }
}
void solve()
{
    floyd();
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        if(vis[i])
          continue;
        double sum1=0,sum2=0;
        vis[i]=true;
        sum1+=a[i];
        sum2+=indgree[i];
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&mat[i][j])
            {
                sum1+=a[j];
                sum2+=indgree[j];
                //vis[i]=true;
            }
        }
        if(sum2==0)
        {
            printf("%.3lf\n",sum1);
            continue;
        }
        double k=(sum1)/sum2;
        printf("%.3lf\n",k*indgree[i]);
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&mat[i][j])
            {
                printf("%.3lf\n",k*indgree[j]);
                vis[j]=true;
            }
        }
    }
    printf("\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(mat,0,sizeof(mat));
        memset(indgree,0,sizeof(indgree));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
          scanf("%lf",a+i);
        int u,v;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&u,&v);
            if(!mat[u][v])
            {
                mat[u][v]=mat[v][u]=true;
                indgree[u]++;
                indgree[v]++;
            }
        }
        solve();
    }
    return 0;
}
