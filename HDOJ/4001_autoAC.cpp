#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct block
{
    int x,y,z,d;
}b[1005];
long long dp[1005];
int n;
bool cmp(block a,block b)
{
    if(a.x!=b.x)return a.x<b.x;
    if(a.y!=b.y)return a.y<b.y;
    return a.d>b.d;
}
void DP()
{
    long long ans=b[0].z;
    for(int i=0;i<n;i++)
    {
        dp[i]=b[i].z;
        ans=max(ans,dp[i]);
    }
    for(int i=1;i<n;i++)
    {
        if(b[i].d==0)
        {
            for(int j=0;j<i;j++)
            {
                if(b[j].x<=b[i].x&&b[j].y<=b[i].y)
                    dp[i]=max(dp[i],dp[j]+b[i].z);
            }
        }
        if(b[i].d==1)
        {
            for(int j=0;j<i;j++)
            {
                if(b[j].x<=b[i].x&&b[i].y>=b[j].y&&(b[i].y*b[j].y||b[i].x>b[j].x))
                    dp[i]=max(dp[i],dp[j]+b[i].z);
            }
        }
        if(b[i].d==2)
        {
            for(int j=0;j<i;j++)
            {
                if(b[i].x>b[j].x&&b[i].y>b[j].y)
                {
                    dp[i]=max(dp[i],dp[j]+b[i].z);
                }
            }
        }
        ans=max(ans,dp[i]);  
    }
    cout<<ans<<'\n';
}
int main()
{
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&b[i].x,&b[i].y,&b[i].z,&b[i].d);
            if(b[i].x<b[i].y)
                swap(b[i].x,b[i].y);
        }
        sort(b,b+n,cmp);
        DP();
    }
    return 0;
}
