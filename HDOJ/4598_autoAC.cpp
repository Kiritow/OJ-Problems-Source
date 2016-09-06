#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<climits>
#include<map>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define repf(i,n,m) for(int i=(n); i<=(m); ++i)
#define repd(i,n,m) for(int i=(n); i>=(m); --i) 
#define ll long long
#define arc(a) ((a)*(a))
#define inf 10000000
#define exp 0.000001
#define N 305
#define T 400
int cont[N];
struct node
{
    int y,w,pre;
};
node a[N*N];
int pre[N];
int color[N];
bool vis[N];
int dp[N];
char s[N][N];
int n,len;
bool dfs(int x)
{
    color[x]=0;
    queue<int>q; q.push(x);
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        rep(i,n)
            if(s[x][i]=='1')
                if(color[i]==-1)
                    color[i]=color[x]^1,q.push(i);
                else if(color[i]==color[x])
                    return false;
    }
    return true;
}
void init()
{
    memset(color,-1,sizeof(color));
    len=1;
    memset(pre,-1,sizeof(pre));
    rep(i,n) dp[i]=inf;
    memset(cont,0,sizeof(cont));
    memset(vis,false,sizeof(vis));
}
void addpage(int s,int t,int w)
{
    a[len].y=t;
    a[len].w=w;
    a[len].pre=pre[s];
    pre[s]=len++;
}
bool spfa()
{
     queue<int>q;
     q.push(0);
     vis[0]=true; dp[0]=0;
     while(!q.empty())
     {
         int x=q.front(); q.pop(); vis[x]=false;
         for(int i=pre[x]; i!=-1; i=a[i].pre)
         {
             int y=a[i].y;
             if(dp[x]+a[i].w<dp[y])
             {
                 dp[y]=dp[x]+a[i].w;
                 if(vis[y]==false)
                 {
                     q.push(y);
                     vis[y]=true;
                     cont[y]++;
                     if(cont[y]>n)
                         return false;
                 }
             }
         }
     }
     return true;
}
bool solve()
{
    init();
    rep(i,n)
        if(color[i]==-1) 
            if(!dfs(i))
                return false;
    rep(i,n)
        repf(j,i+1,n-1)
        {
            if(s[i][j]=='0')
                if(color[i]==0)
                    addpage(j,i,T-1);
                else
                    addpage(i,j,T-1);
            else
                if(color[i]==0)
                    addpage(i,j,-T);
                else addpage(j,i,-T);
        }
    return spfa();
}
int main()
{ 
   int test;
   scanf("%d",&test);
   while(test--)
   {
       scanf("%d",&n);
       rep(i,n) scanf("%s",s[i]);
       if(solve())
           printf("Yes\n");
       else 
           printf("No\n");
   }
   return 0;
}
