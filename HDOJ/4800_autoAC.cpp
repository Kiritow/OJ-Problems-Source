#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 10005
int m,n;
int ai[N];
double dp[200][N],rate[200][200];
bool vis[200][N];
double search(int team,int lo)
{
    if(lo>m-1||team<0||team>n)
        return 1;
    if(vis[team][lo]==true)
        return dp[team][lo];
    else
    {
        double t=search(team,lo+1);
        if(team!=ai[lo])
        {
            double t2=search(ai[lo],lo+1);
            if(t2>t)
                t=t2;
        }
        vis[team][lo]=true;
        dp[team][lo]=rate[team][ai[lo]]*t;
        return dp[team][lo];
    }
}
int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        n=n*(n-1)*(n-2);
        n/=6;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
            {
                scanf("%lf",&rate[i][j]);
            }
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%d",&ai[i]);
        memset(vis,false,sizeof(vis));
        for(i=0;i<n;i++)
        {
            dp[i][m-1]=rate[i][ai[m-1]];
            vis[i][m-1]=true;
        }
        double _max=0;
        for(i=0;i<n;i++)
        {
            _max=max(_max,search(i,0));
        }
        printf("%.6lf\n",_max);
    }
    return 0;
}
