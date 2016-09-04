#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=100005;
vector<int>vt[maxn];
int bit[2*maxn];
int que[2*maxn];
int st[maxn];
int sd[maxn];
int f[maxn];
int n, rt, num;
void dfs(int u, int fa)
{
    que[++num]=u;
    for(int i=0; i<vt[u].size(); i++)
    {
        int v=vt[u][i];
        if(v==fa) continue;
        dfs(v,u);
    }
    que[++num]=u;
}
int lowbit(int x)
{
    return x&(-x);
}
void cal(int x, int val)
{
    while(x<=num)
    {
        bit[x]+=val;
        x+=lowbit(x);
    }
}
int getsum(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=bit[x];
        x-=lowbit(x);
    }
    return ans;
}
int main()
{
    while(~scanf("%d%d",&n,&rt),n+rt)
    {
        for(int i=0; i<=n; i++)
            vt[i].clear();
        for(int i=1; i<n; i++)
        {
            int x, y;
            scanf("%d%d",&x,&y);
            vt[x].push_back(y);
            vt[y].push_back(x);
        }
        fill(st+1,st+1+n,0);
        num=0;
        dfs(rt,-1);
        for(int i=1; i<=num; i++)
        {
            if(!st[que[i]]) st[que[i]]=i;
            else sd[que[i]]=i;
        }
        memset(bit,0,sizeof(bit));
        for(int i=1; i<=num; i++)
            cal(i,1);
        for(int i=n; i>=1; i--)
        {
            f[i]=(getsum(sd[i]-1)-getsum(st[i]))/2;
            cal(st[i],-1);
            cal(sd[i],-1);
        }
        printf("%d",f[1]);
        for(int i=2; i<=n; i++)
            printf(" %d",f[i]);
        puts("");
    }
    return 0;
}
