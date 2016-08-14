#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int N,M;
bool vis[205];
int val[205];
int dp[205][205];
vector<int> map[205];
void dfs(int s)
{
    for(int i=1;i<=M;i++)dp[s][i] = val[s];
    vis[s]=1;
    for(int i=0;i<map[s].size();i++)
    {
        int t=map[s][i];
        if(vis[t])continue;
        dfs(t);
        int j,k;
        if(s==0)
        {    
            for(j=M;j>=0 ;j--)//m == 2
            for(k=1;k<=j ;k++)
            dp[s][j] = max(dp[s][j],dp[s][j-k]+dp[t][k]);
        }
        else
        {
            for(j=M;j>=1 ;j--)//m == 2
            for(k=1;k<j ;k++)
            dp[s][j] = max(dp[s][j],dp[s][j-k]+dp[t][k]);
        }
    }
}
int main()
{
    while(~scanf("%d%d",&N,&M),N+M)
    {
        for(int i=0;i<=N;i++) map[i].clear();
        for(int i=1;i<=N;i++)
        {
            int a,v;
            scanf("%d%d",&a,&v);
            map[a].push_back(i);
            val[i]=v;
        }
        memset(dp,0,sizeof dp);
        memset(vis,0,sizeof vis);    
        dfs(0);
        printf("%d\n",dp[0][M]);
    }
    return 0;
}
