#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define N 70
#define S 600
using namespace std;
int n,l,s,vis[N],fa[N];
vector<int>gra[N];
double dp[N][S];
void dfs(int d,int p)
{
    vis[d]=1;fa[d]=p;
    int len=gra[d].size();
    if(p!=-1&&len==1)
    {
        dp[d][0]=1;
        for(int i=1;i<=s;i++)dp[d][i]=0;
        return ;
    }
    for(int i=0;i<len;i++)
        if(!vis[gra[d][i]])dfs(gra[d][i],d);
    double sum[S]={0};
    for(int i=0;i<=s;i++)
    {
        if(i*2<=s)
        {
            dp[d][i]=1;
            for(int j=0;j<len;j++)
            {
                int e=gra[d][j];
                if(fa[e]!=d)continue;
                double tmp=0;
                for(int k=0;k<=min(l,i);k++)
                    for(int h=0;h<=i-k;h++)
                        tmp+=dp[e][h];
                tmp/=(l+1);
                dp[d][i]*=tmp;
            }
            if(i>0)dp[d][i]-=sum[i-1],sum[i]=dp[d][i]+sum[i-1];
            else sum[i]=dp[d][i];
        }
        else
        {
            int op=s-i;
            dp[d][i]=0;
            for(int j=0;j<len;j++)
            {
                int e=gra[d][j];
                if(fa[e]!=d)continue;
                double tmp1=0;
                for(int k=0;k<=min(l,op);k++)
                    for(int h=0;h<=op-k;h++)
                        tmp1+=dp[e][h];
                tmp1/=(l+1);
                double tmp2=0;
                for(int k=0;k<=min(l,i);k++)
                    tmp2+=dp[e][i-k];
                tmp2/=(l+1);
                dp[d][i]+=sum[op]*tmp2/tmp1;
            }
        }
    }
}
int main()
{
    int ncase;
    scanf("%d",&ncase);
    for(int u=1;u<=ncase;u++)
    {
        scanf("%d%d%d",&n,&l,&s);
        for(int i=1;i<=n;i++)gra[i].clear();
        for(int i=1;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            gra[a].push_back(b);
            gra[b].push_back(a);
        }
        memset(vis,0,sizeof(vis));
        dfs(1,-1);
        double ans=0;
        for(int i=0;i<=s;i++)ans+=dp[1][i];
        printf("Case %d: %.6lf\n",u,ans);
    }
}
