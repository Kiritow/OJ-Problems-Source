#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
double dis[21][21],dp[1<<21];
int n,fx,fy,mac;
struct node
{
    int x,y;
}nd[21];
double DIS(double x,double y,double xx,double yy)
{
    return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}
bool cmp(node a,node b)
{
    return DIS(a.x,a.y,fx,fy)<DIS(b.x,b.y,fx,fy);
}
double DP(int sta)
{
    if(dp[sta]!=0x7fffffff)
        return dp[sta];
    if(sta==0) {dp[0]=0.0;}
    else
    {
        int tem=sta,i=0;
        for(i=0;i<20;i++)
        {
            if((1<<i)&sta)break;
        }
        for(int j=i+1;j<2*n;j++)
        {
            if((sta&(1<<j))==0)continue;
            dp[sta]=min(DP(sta-(1<<j)-(1<<i))+dis[i][j],dp[sta]);
        }
    }
    return dp[sta];
}
int main()
{
    int c,ca=0;
    scanf("%d",&c);
    while(c--)
    {
        ca++;
        scanf("%d%d",&fx,&fy);
        scanf("%d",&n);
        for(int i=0;i<2*n;i++)
        {
            scanf("%d%d",&nd[i].x,&nd[i].y);
        }
        sort(nd,nd+2*n,cmp);
        for(int i=0;i<2*n;i++)
            for(int j=i+1;j<2*n;j++)
            {
                dis[i][j]=DIS(nd[i].x,nd[i].y,fx,fy)+DIS(nd[i].x*1.0,nd[i].y*1.0,nd[j].x*1.0,nd[j].y*1.0);
            }
            printf("Case #%d: ",ca);
            for(int i=0;i<(1<<2*n);i++)
                dp[i]=0x7fffffff;
            printf("%.2f\n",DP((1<<(2*n))-1));
    }
}
