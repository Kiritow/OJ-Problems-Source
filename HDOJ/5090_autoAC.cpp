#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 110 ;
bool con[maxn][maxn],vis[maxn];
int match[maxn],n,k,x;
void initial()
{
    memset(con,0,sizeof(con));
    memset(match,-1,sizeof(match));
}
void input()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
    {
         scanf("%d",&x);
         while(x<=n)
         {
              con[x][i]=1;
              x+=k;
         }
    }
}
bool dfs(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(!vis[i] && con[x][i])
        {
            vis[i]=1;
            if(match[i]==-1 || dfs(match[i]))
            {
                 match[i]=x;
                 return true;
            }
        }
    }
    return false;
}
void solve()
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
         memset(vis,0,sizeof(vis));
         if(dfs(i))  cnt++;
    }
    if(cnt==n)   printf("Jerry\n");
    else   printf("Tom\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        initial();
        input();
        solve();
    }
    return 0;
}
