#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m;
int map[85][85],sum[85],vis[5010];
int has[3]={0,2,0};
struct edge
{
    int from,to,len;
}ans[5010];
int solve(int len,int num)
{
    int tmp=len%3;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j&&!map[i][j]&&!map[j][i])
            {
                if(j>i)
                {
                    if((sum[j]-sum[i]+3)%3==tmp)
                    {
                        map[i][j]=1;
                        ans[num].from=i;
                        ans[num].to=j;
                        ans[num].len=len;
                        return 1;
                    }
                }
                else
                {
                    if((sum[i]-sum[j]+3+tmp)%3==0)
                    {
                        map[i][j]=1;
                        ans[num].from=i;
                        ans[num].to=j;
                        ans[num].len=len;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
int main()
{
    int ncase,T=0;
    scanf("%d",&ncase);
    while(ncase--)
    {
        memset(vis,0,sizeof(vis));
        memset(map,0,sizeof(map));
        memset(sum,0,sizeof(sum));
        scanf("%d%d",&n,&m);
        sum[1]=0;
        for(int i=1;i<n;i++)
        {
            ans[i].from=i;
            ans[i].to=i+1;
            ans[i].len=i;
            vis[i]=1;
            map[ans[i].from][ans[i].to]=1;
            if(i!=1)
            sum[i]=(sum[i-1]+i-1)%3;
        }
        ans[n].from=n;
        ans[n].to=1;
        map[n][1]=1;
        ans[n].len=n+has[n%3];
        vis[ans[n].len]=1;
        sum[n]=(sum[n-1]+n-1)%3;
        int num=n,tru=1;
        for(int i=1;i<=m;i++)
        {
            if(!vis[i])
            {
                tru=solve(i,++num);
                if(!tru)
                break;
            }
        }
        printf("Case #%d:\n",++T);
        if(!tru)
        {
            printf("-1\n");
            continue;
        }
        for(int i=1;i<=m;i++)
        {
            printf("%d %d %d\n",ans[i].from,ans[i].to,ans[i].len);
        }
    }
    return 0;
}
