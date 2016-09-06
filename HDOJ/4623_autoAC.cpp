#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int prime[]={2,3,5,7,11,13,17,19,23};
const int np=9;
int state[30];
int g[300][300];
int vi[300];
int num[30];
int base[30];
short dp[19][2000000];
bool ok[29];
int n,m,ns,st;
void ini()
{
    scanf("%d%d",&n,&m);
    memset(g,0,sizeof(g));
    memset(vi,0,sizeof(vi));
    memset(num,0,sizeof(num));
    ns=0;
    state[++ns]=0;
    num[ns]=1;
    for(int i=2;i<=n;i++)
    {
        st=0;
        if(ok[i])
        {
            num[1]++;
            continue;
        }
        for(int j=0;j<np;j++)
        {
            if(i%prime[j]==0)
            {
                st|=(1<<j);
            }
        }
        if(!vi[st])
        {
            state[++ns]=st;
            num[ns]=1;
            vi[st]=ns;
        }
        else
        {
            num[vi[st]]++;
        }
    }
    for(int i=1;i<=ns;i++)
    {
        for(int j=1;j<=ns;j++)
        {
            if((state[i]&state[j])==0)
                g[i][j]=1;
        }
    }
    base[1]=1;
    st=0;
    for(int i=1;i<=ns;i++)
    {
        base[i+1]=base[i]*(num[i]+1);
        st+=base[i]*num[i];
    }
}
int getnum(int i,int x)
{
    int res=(x%base[i+1])/(base[i]);
    return res;
}
int getstate(int i,int num)
{
    return num*base[i];
}
void dfs(int t,int x)
{
    if(t==0)
    {
        dp[x][0]=1;
        return ;
    }
    if(dp[x][t]!=-1)
        return;
    dp[x][t]=0;
    for(int i=1;i<=ns;i++)
    {
        if(g[x][i]&&getnum(i,t)>=1)
        {
            dfs(t-base[i],i);
            dp[x][t]=((int)dp[x][t]+dp[i][t-base[i]])%m;
        }
    }
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    memset(ok,0,sizeof(ok));
    ok[17]=1;
    ok[19]=1;
    ok[23]=1;
    while(T--)
    {
        ini();
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=1;i<=ns;i++)
        {
            dfs(st-base[i],i);
            ans=((int)ans+dp[i][st-base[i]])%m;
        }
        for(int i=1;i<=ns;i++)
        {
            while(num[i]>1)
            {
                ans=((int)ans*num[i])%m;
                num[i]--;
            }
        }
        printf("%d\n",ans);
    }
}
