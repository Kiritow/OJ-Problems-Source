#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <limits>
using namespace std;
typedef long long LL;
const int MAXN=20;
const int INF = numeric_limits<int>::max();
int dp[1<<MAXN][MAXN];
int dis[MAXN][MAXN];
int main()
{
    int T,n,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)dis[i][j]=INF;
        for(int i=0,x,y,w;i<m;i++){
            scanf("%d%d%d",&x,&y,&w);
            --x;--y;
            dis[x][y]=dis[y][x]=min(dis[x][y],w);
        }
        if(n==1){
            puts("0");
            continue;
        }
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                {
                    if(dis[i][k]!=INF&&dis[k][j]!=INF)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
        --n;
        int tot=(1<<n);
        for(int s=0;s<tot;s++){
            for(int i=0;i<n;i++){
                if(s&(1<<i)){
                    if(s==(1<<i))dp[s][i]=dis[0][i+1];
                    else {
                        dp[s][i]=INF;
                        for(int j=0;j<n;j++){
                            if(i!=j&&(s&(1<<j))){
                                dp[s][i]=min(dp[s][i],dp[s^(1<<i)][j]+dis[i+1][j+1]);
                            }
                        }
                    }
                }
            }
        }
        int ans=INF;
        for(int i=0;i<n;i++)ans=min(ans,dp[tot-1][i]+dis[0][i+1]);
        printf("%d\n",ans);
    }
    return 0;
}
