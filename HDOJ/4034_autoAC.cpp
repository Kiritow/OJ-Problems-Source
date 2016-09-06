#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<memory.h>
using namespace std;
int map[110][110];
int visit[110][110];
int n;
int dist[110][110];
void floyd() {
        int i,j,k;
            for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            for(k=1;k<=n;k++)
            {
                if(j!=i&&i!=k&&dist[j][k]>=dist[j][i]+dist[i][k])
                {
                    visit[j][k]=1;
                    dist[j][k]=dist[j][i]+dist[i][k];
                 }
            }
}
int main()
{
    int t;
    int count=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(map,0,sizeof(map));
        memset(dist,0,sizeof(dist));
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {scanf("%d",&dist[i][j]);
         map[i][j]=dist[i][j];}
         memset(visit,0,sizeof(visit));
         floyd();
         int ans=0;
         bool flag=true;
         for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
         {
            if(visit[i][j]==1&&dist[i][j]==map[i][j])
            {
                ans++;
            }
            if(dist[i][j]<map[i][j])
            {
                flag=false;
            }
         }
         int m=n*(n-1)-ans;
         if(!flag||m<n-1)
         printf("Case %d: impossible\n",count++);
         else
        printf("Case %d: %d\n",count++,m);
    }
}
