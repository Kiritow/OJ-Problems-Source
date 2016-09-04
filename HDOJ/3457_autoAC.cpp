#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Max(a,b) a>b?a:b
using namespace std;
int n;
int dp[1111],map[1111][1111];
struct node
{
    int x1,x2,y1,y2;
}s[1111];
int dfs(int x)
{
    int i,j,k,l;
    if(dp[x])return dp[x];    
    for(i=0;i<n;i++)
    if(map[x][i])
    {
        dp[x]=Max(dp[x],dfs(i)+1);    
    }
    dp[x]=Max(dp[x],1);    
    return dp[x];
}
int main (void)
{
    int i,j,k,l,x1,x2,y1,y2,sum;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            s[i].x1=x1;
            s[i].x2=x2;
            s[i].y1=y1;
            s[i].y2=y2;
        }
        memset(map,0,sizeof(map));
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)    
        for(j=0;j<n;j++)
        {
            if(s[i].x2<s[j].x1&&s[i].y2<s[j].y1)
            {
                map[i][j]=1;
            }
        }
        sum=0;
        for(i=0;i<n;i++)    
        {
            sum=Max(sum,dfs(i));
        }
        printf("%d\n",sum);
    }
    return 0;
}
