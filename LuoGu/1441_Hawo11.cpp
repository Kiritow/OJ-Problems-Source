#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int N=20+2;
const int M=2000+5;
int n,m,w[N],dp[M],flag[N],top,ans=0,tot;
void work01()
{
    memset(dp,0,sizeof(dp));
    dp[1]=1;tot=0;top=1;
    for (int i=1;i<=n;i++)
    {
        if (flag[i]==1) continue;
        for (int j=top;j>=0;j--)
        if (dp[j]&&!dp[j+w[i]]) dp[j+w[i]]=1,tot++;
        top+=w[i];
    }//滚动 
    ans=max(ans,tot);
}
void dfs(int u,int now)
{
    if (now>m) return ;
    if (u==n+1) {if (now==m) work01();return ;}
    dfs(u+1,now);
    flag[u]=1;
    dfs(u+1,now+1);
    flag[u]=0; 
} 
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    scanf("%d",&w[i]);
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}
/*
3 1
1 2 2
*/
