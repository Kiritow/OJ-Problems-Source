#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define INF 2000000000
int q[4*(1<<17)][2];
int maxQ=4*(1<<17)-3;
int front,rear,n,m;
int mat[20][20];
int dp[1<<17],f[1<<17],dist[1<<17][18],vis[1<<17][18];
int main ()
{
    int T;scanf("%d",&T);
    for(int kk=1;kk<=T;++kk)
    {
        scanf("%d%d",&n,&m);
        memset(dist,127,sizeof(dist));
        memset(dp,127,sizeof(dp));
        memset(vis,0,sizeof(vis));
        memset(mat,127,sizeof(mat));
        front=rear=0;
        int u,v,s;
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d%d",&u,&v,&s);
            u--;v--;
            if(mat[u][v]>s)
                mat[u][v]=mat[v][u]=s;
        }
        dist[0][0]=0;
        q[++rear][0]=0;q[rear][1]=0;
        vis[0][0]=1;
        while(front!=rear)
        {
            if(++front==maxQ) front=0;
            int u_sta=q[front][0],u=q[front][1];
            vis[u_sta][u]=0;
            for(int i=0;i<n;++i)
            {
                int v_sta=u_sta|(1<<i);
                if(dist[v_sta][i]>dist[u_sta][u]+mat[u][i])
                {
                    dist[v_sta][i]=dist[u_sta][u]+mat[u][i];
                    if(!vis[v_sta][i])
                    {
                        if(++rear==maxQ) rear=0;
                        vis[v_sta][i]=1;
                        q[rear][0]=v_sta;q[rear][1]=i;
                    }
                }
            }
        }
        for(int i=0;i<(1<<n);++i)
            for(int j=0;j<n;++j)
            dp[i>>1]=min(dp[i>>1],dist[i][j]);
        int tot_sta=1<<n-1;
        for(int i=0;i<tot_sta;++i)
            f[i]=dp[i];
        for(int k=1;k<=2;++k)
        {
            for(int i=tot_sta-1;i;--i)
                for(u=i;u;u=(--u)&i)
            {
                v=i^u;
                if(dp[i]>max(dp[u],f[v]))
                {
                    if(i==224 && max(dp[u],f[v])==5)
                        cout<<"dd";
                    dp[i]=max(dp[u],f[v]);
                }
            }
        }
        int query;scanf("%d",&query);
        int sta=0;
        while(query--)
        {
            scanf("%d",&u);
            sta|=1<<u-2;
        }
        int ans=INF;
        for(int i=0;i<tot_sta;++i)
            if((i&sta)==sta)
        {
            ans=min(ans,dp[i]);
        }
        if(ans>=INF)
            printf("Case %d: -1\n",kk);
        else printf("Case %d: %d\n",kk,ans);
    }
    return 0;
}
