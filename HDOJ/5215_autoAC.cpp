#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=200000+100;
struct Edge
{
    int v, nxt;
    Edge(int v=0, int nxt=0):v(v), nxt(nxt) {}
} edge[600010];
bool even, odd;
int n, m, head[maxn], color[maxn], tot, cnt, pre[maxn], bel[maxn];
void init()
{
    tot=even=odd=0;
    cnt=0;
    memset(color, 0, sizeof color);
    memset(head, -1, sizeof head);
    memset(bel, -1, sizeof bel);
}
void AddEdge(int u, int v)
{
    edge[tot]=Edge(v, head[u]);
    head[u]=tot++;
}
void dfs(int u, int fa)
{
    for(int i=head[u]; ~i; i=edge[i].nxt)
    {
        if((i^1)==fa)continue ;
        int v=edge[i].v;
        if(color[v]==color[u])    
        {
            odd=1;
            ++cnt;
            int x=v;
            while(!even)    
            {
                if(~bel[x])
                {
                    even=true;
                    break;
                }
                bel[x]=cnt;
                x=pre[x];
                if(x==u || x==-1)break;
            }
        }
        if(color[v]==3-color[u])    
            even=1;
        if(!color[v])
        {
            color[v]=3-color[u];
            pre[v]=u;
            dfs(v, i);
        }
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        init();
        while(m--)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            AddEdge(u, v);
            AddEdge(v, u);
        }
        for(int i=1; i<=n; i++)
            if(!color[i])
            {
                color[i]=1;
                pre[i]=-1;
                dfs(i, -1);
            }
        puts(odd?"YES":"NO");
        puts(even?"YES":"NO");
    }
    return 0;
}
