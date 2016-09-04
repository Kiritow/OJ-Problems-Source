#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
#define N 16
#define M 1<<16
#define MS 1000000009
#define LL long long
using namespace std;
int n,goal;
string str[N];
LL da[N];
int gra[N][N],mark[N];
int slen[N];
int dp[M][N];
LL ans;
void ini(void)
{
    goal=(1<<n)-1;
    for(int i=0;i<n;i++)
        str[i].clear();
    for(int i=0;i<n;i++)
    {
        LL k=da[i];
        while(k)
        {
            str[i].push_back((k&1)+'0');
            k=k>>1;
        }
        int j=str[i].size();
        string tempstr;
        while(j--)
            tempstr.push_back(str[i][j]);
        str[i]=tempstr;
    }
    sort(str,str+n);
    for(int i=0;i<n;i++)
        slen[i]=str[i].size();
    memset(mark,0,sizeof(mark));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i!=j&&slen[i]>slen[j])
                for(int k1=0;k1<slen[i]-slen[j]+1;k1++)
                {
                    int flag=0;
                    for(int k2=0;k2<slen[j];k2++)
                        if(str[i][k1+k2]!=str[j][k2])
                        {
                            flag=1;
                            break;
                        }
                    if(flag==0)
                    {
                        if(!mark[j])
                        {
                            mark[j]=1;
                            goal-=(1<<j);
                        }
                        break;
                    }
                }
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(!mark[i]&&!mark[j]&&str[i]==str[j])
                mark[j]=1,goal-=(1<<j);
    memset(gra,0,sizeof(gra));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(!mark[i]&&!mark[j]&&i!=j)
                for(int k=0;k<slen[i];k++)
                {
                    int flag=0;
                    for(int u=0;u+k<slen[i];u++)
                        if(str[i][k+u]!=str[j][u])
                        {
                            flag=1;
                            break;
                        }
                    if(!flag)
                    {
                        gra[i][j]=slen[i]-k;
                        break;
                    }
                }
}
void dfs(int s,int p)
{
    if(~dp[s][p])return ;
    if(s==(1<<p))
    {
        dp[s][p]=slen[p];
        return ;
    }
    int minn=0x3f3f3f3f;
    int t=s-(1<<p);
    for(int i=0;i<n;i++)
        if(!mark[i]&&i!=p&&(s&(1<<i)))
        {
            dfs(t,i);
            minn=min(minn,dp[t][i]-gra[p][i]);
        }
    dp[s][p]=minn+slen[p];
}
void rans(int s,int p,int e)
{
    for(int i=e;i<slen[p];i++)
        ans=(ans*2+str[p][i]-'0')%MS;
    if(s==(1<<p))return ;
    int t=s-(1<<p);
    int k=-1;
    string a;
    for(int i=0;i<n;i++)
        if(!mark[i]&&(s&(1<<i))&&dp[t][i]-gra[p][i]+slen[p]==dp[s][p])
        {
            string b(str[i],gra[p][i],slen[p]-gra[p][i]);
            if(k==-1||a>b)
                a=b,k=i;
        }
    rans(t,k,gra[p][k]);
}
void re(void)
{
    for(int i=0;i<n;i++)
        scanf("%lld",&da[i]);
}
void run(void)
{
    ini();
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
        if(!mark[i])
            dfs(goal,i);
    int p,minn=0x3f3f3f3f;
    for(int i=0;i<n;i++)
        if(!mark[i]&&dp[goal][i]<minn)
            p=i,minn=dp[goal][i];
    ans=0;
    rans(goal,p,0);
    printf("%lld\n",ans);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        re();
        run();
    }
    return 0;
}
