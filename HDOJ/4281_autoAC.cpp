#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define inf 1<<30
struct Point{
    int x,y;
}point[17];
int n,m,ans,val[17],dp1[1<<17];
int dp[1<<17][17],best[1<<17];
int Ok[1<<17];
int dist[17][17];
int Get_Dist(int i,int j)
{
    return ceil(sqrt(double(point[i].x-point[j].x)*(point[i].x-point[j].x)+double(point[i].y-point[j].y)*(point[i].y-point[j].y)));
}
int Judge(int state)
{
    int sum=0;
    for(int i=0;i<n;i++){
        if(state&(1<<i))sum+=val[i];
    }
    return sum<=m;
}
int Solve()
{
    fill(dp1,dp1+(1<<n),inf);
    dp1[0]=0;
    for(int state=0;state<(1<<n);state++){
        if(Ok[state]){
            for(int i=0;i<(1<<n);i++){
                if((state&i)==0&&dp1[i]!=inf){
                    dp1[state|i]=min(dp1[state|i],dp1[i]+1);
                }
            }
        }
    }
    return dp1[(1<<n)-1];
}
int TSP()
{
    fill(best,best+(1<<n),inf);
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<n;j++)dp[i][j]=inf;
    dp[1][0]=0;
    for(int state=0;state<(1<<n);state++){
        if(Ok[state]){
            for(int i=0;i<n;i++)if(state&(1<<i)){
                if(dp[state][i]==inf)continue;
                best[state]=min(best[state],dp[state][i]+dist[i][0]);
                for(int j=0;j<n;j++)if(!(state&(1<<j))){
                    dp[state|(1<<j)][j]=min(dp[state|(1<<j)][j],dp[state][i]+dist[i][j]);
                }
            }
        }
    }
    for(int state=0;state<(1<<n);state++){
        if(state&1){
            for(int substate=state&(state-1);substate;substate=state&(substate-1)){
                best[state]=min(best[state],best[substate]+best[(state^substate)|1]);
            }
        }
    }
    return best[(1<<n)-1];
}
int main()
{
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++)scanf("%d%d",&point[i].x,&point[i].y);
        for(int i=0;i<n;i++)scanf("%d",&val[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)dist[i][j]=Get_Dist(i,j);
        for(int s=0;s<(1<<n);s++){
            Ok[s]=Judge(s);
        }
        ans=Solve();
        if(ans==inf){
            puts("-1 -1");
            continue;
        }
        printf("%d %d\n",ans,TSP());
    }
    return 0;
}
