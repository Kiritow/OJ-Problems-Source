#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
    int x,y;
}nd[16];
long long dp[1<<16][16];
int n,m,gp[6][6],pos,gd[6][6],mp[6][6];
int gcd(int x,int y)
{
     if (y == 0)
        return x;
    return gcd(y, x % y);
}
bool ok(int x,int y,int sta)
{
    int x1=nd[x].x,x2=nd[y].x,y1=nd[x].y,y2=nd[y].y;
    int dx=x2-x1;
    int dy=y2-y1;
    int c=gd[abs(dx)][abs(dy)];
    dx=dx/c;dy=dy/c;
    for(int i=0;i<=5;i++)
    {
        x1+=dx;y1+=dy;
        if(gp[x1][y1]==1)
            return false;
        else if(x1==x2&&y1==y2)
            return true;
        else if(gp[x1][y1]==0&&(sta&(1<<(mp[x1][y1])))==0)
            return false;
    }
    return false;
}
long long DP(int st,int k)
{
    if(dp[st][k]!=-1)return dp[st][k];
    if(st==(1<<k)) dp[st][k]=1;
    else
    {
        dp[st][k]=0;
        for(int j=0;j<pos;j++)
        {
            if(((1<<j)&st)==0||j==k)continue;
            if(ok(j,k,st)==0)continue;
            dp[st][k]+=DP(st-(1<<k),j);    
        }
    }
        return dp[st][k];
}
void work()
{
    long long ans=0;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<pos;i++)
          DP((1<<pos)-1,i);
    for(int i=0;i<pos;i++)
    {
            ans+=dp[(1<<pos)-1][i];
    }
    cout<<ans<<'\n';
}
void init()
{
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
            gd[i][j]=gcd(i,j);
}
int main()
{
    init();
    while(scanf("%d%d",&n,&m)!=EOF)
    {    
        pos=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                scanf("%d",&gp[i][j]);
                if(gp[i][j]==0)
                {
                    nd[pos].x=i;
                    nd[pos++].y=j;
                    mp[i][j]=pos-1;
                }
            }
            work();
    }
    return 0;
}
