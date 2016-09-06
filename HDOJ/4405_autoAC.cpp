#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int N=100005;
struct node
{
    int y,next;
};
bool vis[N];
node path[N];
int first[N],t;
double dp[N];
void add(int x,int y)
{
    path[t].y=y;
    path[t].next=first[x];
    first[x]=t++;
}
int main()
{
    double s;
    int n,m,v;
    while(cin>>n>>m)
    {
        if(m==0&&n==0) break;
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        memset(first,0,sizeof(first));
        int x,y;
        t=1;
        while(m--)
        {
            cin>>x>>y;
            add(y,x);
        }
        dp[n]=-1;
        for(int i=n; i>=0; i--)
        {
            if(!vis[i])
            {
                vis[i]=true;
                s=0;
                for(int k=1; k<=6; k++)
                    s+=dp[i+k];
                s/=6;
                dp[i]+=(s+1);
            }
            for(int k=first[i]; k; k=path[k].next)
            {
                v=path[k].y;
                dp[v]=dp[i];
                vis[v]=true;
            }
        }
        printf("%.4lf\n",dp[0]);
    }
    return 0;
}
