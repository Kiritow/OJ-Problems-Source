#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 101;
const double INF = 10000000000.0;
const int INF_INT =10000000;
int side[N][N];
int dis[N][N];
int vis[N][N];
int tmp[N][N];
double ans[N][N];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        memset(vis,-1,sizeof(vis));
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){ans[i][j]=INF;side[i][j]=INF_INT;}
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            side[u][v]=w;
            vis[u][v]=1;
        }
        for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)if(vis[i][k]!=-1){
            for(int j=1;j<=n;j++)if(vis[k][j]!=-1){
                if(vis[i][j]==-1)vis[i][j]=vis[i][k]+vis[k][j];
                else vis[i][j]=min(vis[i][j],vis[i][k]+vis[k][j]);
            }
        }
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=side[i][j];
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(vis[i][j]!=-1&&k>=vis[i][j]){
                ans[i][j]=min(ans[i][j],(double)dis[i][j]/k);
            }
            for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){tmp[i][j]=dis[i][j];dis[i][j]=INF_INT;}
            for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
                for(int h=1;h<=n;h++){
                    if(vis[i][h]==-1||k<vis[i][h])continue;
                    if(vis[h][j]==-1||k<vis[h][j])continue;
                    dis[i][j]=min(dis[i][j],tmp[i][h]+side[h][j]);
                }
            }
        }
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(vis[i][j]!=-1){
            for(int k=1;k<=n;k++)if(vis[i][k]!=-1&&vis[k][j]!=-1&&vis[k][k]!=-1){
                ans[i][j]=min(ans[i][j],ans[k][k]);
            }
        }
        for(int i=1;i<=n;i++){
            int j=1;
            if(vis[i][j]==-1)printf("NO");
            else printf("%.3lf",ans[i][j]);
            for(j=2;j<=n;j++){
                if(vis[i][j]==-1)printf(" NO");
                else printf(" %.3lf",ans[i][j]);
            }
            printf("\n");
        }
    }
}
