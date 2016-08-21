#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
const int maxn = 1002;
const int maxm = 500002;
struct node
{
    int u,v,w,d;
    bool operator < (const node &other) const
    {
        return w > other.w;
    }
}edge[maxm];
int father[maxn];
bool vis[maxn];
int m,n;
int find(int u)
{
    return (u == father[u]) ? father[u] : (father[u] = find(father[u]));
}
void read()
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++) father[i] = i;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d %d",&edge[i].u,&edge[i].v,&edge[i].d,&edge[i].w);
    }
    sort(edge , edge + m);
    return;
}
void solve()
{
    int sum = 0;
    for(int i=0;i<m;i++)
    {
        int x = find(edge[i].u);
        int y = find(edge[i].v);
        if(vis[x] && vis[y]) continue;
        if(edge[i].d == 1 && vis[x]) continue;
        sum += edge[i].w;
        if(edge[i].d == 1) vis[x] = true;
        else
        {
            if(x == y) vis[x] = true;
            else if(vis[x]) vis[y] = true;
            else if(vis[y]) vis[x] = true;
            else father[y] = x;
        }
    }
    printf("%d\n",sum);
    return;
}
int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        read();
        solve();
    }
    return 0;
}
