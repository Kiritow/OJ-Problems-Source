#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int head[100050];
int N,G;
int c[100050],v[100050],dp[505][10005];
struct NODE
{
    int to,next;
}edge[300000];
void dfs(int x,int V)
{
    int i,j,k,to;
    for(i=head[x];i!=-1;i=edge[i].next)
    {
        to=edge[i].to;
        if(head[to] == -1)
        {
            for(j=V;j>=c[to];j--)
            {
                dp[x][j]=max(dp[x][j],dp[x][j-c[to]]+v[to]);
            }
        }
        else
        {
            if(V >= c[to])
            {
                for(j=0;j<=V-c[to];j++) dp[to][j]=dp[x][j];
                dfs(to,V-c[to]);
                for(j=V;j>=c[to];j--)
                {
                    dp[x][j]=max(dp[x][j],dp[to][j-c[to]]+v[to]);
                }
            }
        }
    }
}
int main()
{
    while(~scanf("%d %d",&N,&G))
    {
        int i,j,k;
        memset(head,-1,sizeof(head));
        memset(dp,0,sizeof(dp));
        for(i=1;i<=N;i++)
        {
            scanf("%d %d %d",&c[i],&v[i],&j);
            if(i == j) edge[i].to=i,edge[i].next=head[0],head[0]=i;
            else edge[i].to=i,edge[i].next=head[j],head[j]=i;
        }
        c[0]=v[0]=0;
        dfs(0,G);
        int ans=0;
        printf("%d\n",dp[0][G]);
    }
}
