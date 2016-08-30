#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define inf 0x3f3f3f3f
int State[12];
int visited[60000][12];
int dp[60000][12];
int map[12][12];
int n,m;
void Initiate()
{
    State[0]=1;
    for(int i=1;i<=10;i++)
        State[i]=State[i-1]*3;
    for(int i=0;i<=State[10];i++){
        int tmp=i;
        for(int j=0;j<=10;j++){
            visited[i][j]=tmp%3;
            tmp/=3;
        }
    }
}
int main()
{
    Initiate();
    int u,v,w,ans;
    while(~scanf("%d%d",&n,&m)){
        memset(dp,inf,sizeof(dp));
        memset(map,inf,sizeof(map));
        for(int i=0;i<n;i++)dp[State[i]][i]=0;
        while(m--){
            scanf("%d%d%d",&u,&v,&w);
            u--,v--;
            map[u][v]=map[v][u]=min(map[u][v],w);
        }
        ans=inf;
        for(int i=0;i<State[n];i++){
            bool flag=true;
            for(int j=0;j<n;j++){
                if(visited[i][j]==0)flag=false;
                if(dp[i][j]==inf)continue;
                for(int k=0;k<n;k++)if(j!=k){
                    if(visited[i][k]>=2)continue;
                    if(map[j][k]==inf)continue;
                    dp[i+State[k]][k]=min(dp[i+State[k]][k],dp[i][j]+map[j][k]);
                }
            }
            if(flag){
                for(int j=0;j<n;j++){
                    ans=min(ans,dp[i][j]);
                }
            }
        }
        if(ans==inf)ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
