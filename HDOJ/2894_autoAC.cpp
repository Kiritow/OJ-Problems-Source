#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
bool fg,d[1<<15],vis[1<<15];
int tot,k;
void read()
{
    memset(vis,0,sizeof vis);
    fg=false;
    tot=1<<k;
}
bool check()
{
    int i=1,j=tot+1;
    for(;i<=k-1;i++,j++)
    {
        if(d[i]!=d[j]) return false;
    }
    fg=true;
    for(i=1;i<=tot;i++) printf("%d",d[i]);
}
void dfs(int step,int num)
{
    if(fg) return;
    if(step==tot)
    {
        check();
        return;
    }
    for(int i=0;i<tot;i++)
    {
        if(!vis[i])
        {
            int sk;
            if((num>>(k-1))==1) sk=num-(1<<(k-1));
            else sk=num;
            if(sk==(i>>1))
            {
                d[step+k]=i&1;
                vis[i]=true;
                dfs(step+1,i);
                vis[i]=false;
            }
        }
    }
}
void go()
{
    printf("%d ",tot);
    for(int i=1;i<=k;i++) d[i]=0;
    vis[0]=true;
    dfs(1,0);
    printf("\n");
}
int main()
{
    while(scanf("%d",&k)!=EOF)
    {
        read();
        go();
    }
    return 0;
}
