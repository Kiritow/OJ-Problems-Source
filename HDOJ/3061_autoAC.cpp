#include <stdio.h>
#include <string.h>
#define VM 10000
#define EM 120000
#define inf 0x3f3f3f3f
struct E
{
    int to,cap,nxt;
}edge[EM];
int head[VM],gap[VM],dist[VM],cur[VM],pre[VM];
int ep;
void addedge (int cu,int cv,int cw)
{
    edge[ep].to = cv;
    edge[ep].cap = cw;
    edge[ep].nxt = head[cu];
    head[cu] = ep;
    ep ++;
    edge[ep].to = cu;
    edge[ep].cap = 0;
    edge[ep].nxt = head[cv];
    head[cv] = ep;
    ep ++;
}
int min (int a ,int b)
{
   return a > b ? b : a;
}
int sap (int src,int des,int n)
{
    memset (dist,0,sizeof(dist));
    memset (gap,0,sizeof (dist));
    memcpy (cur,head,sizeof(dist));
    int res = 0;
    int u = pre[src] = src;
    int aug = inf;
    gap[0] = n;
    while (dist[src] < n)
    {
loop:
        for (int &i = cur[u];i != -1;i = edge[i].nxt)
        {
            int v = edge[i].to;
            if (edge[i].cap && dist[u] == dist[v] + 1)
            {
                aug = min (aug,edge[i].cap);
                pre[v] = u;
                u = v;
                if (v == des)
                {
                    res += aug;
                    for (u = pre[u];v != src;v = u,u = pre[u])
                    {
                        edge[cur[u]].cap -= aug;
                        edge[cur[u]^1].cap += aug;
                    }
                    aug = inf; //
                }
                goto loop;
            }
        }
        int mindist = n;  //
        for (int i = head[u];i != -1;i = edge[i].nxt)
        {
            int v = edge[i].to;
            if (edge[i].cap && mindist > dist[v])
            {
                cur[u] = i;
                mindist = dist[v];
            }
        }
        if ((--gap[dist[u]]) == 0)
            break;
        dist[u] = mindist + 1;
        gap[dist[u]] ++;
        u = pre[u];
    }
    return res;
}
int vis[VM];
void dfs(int u,int v)
{
    if(u==v) return ;
    vis[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].nxt)
    if(edge[i].cap>0&&!vis[edge[i].to])
    dfs(edge[i].to,v);
}
int main ()
{
    int n,m,u,v,p;
    int src,des;
    int sum;
    while (scanf("%d %d",&n,&m)!=EOF)
    {
        ep = 0;
        sum=0;
        src = 0;
        des = n + 1;
        memset (head,-1,sizeof(head));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&p);
            if(p>0)
            {
                addedge(src,i,p);
                sum+=p;
            }
            else
            addedge(i,des,-p);
        }
        for (int i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v,inf);
        }
        int max_flow=sap(src,des,n + 2);;
        printf("%d\n",sum-max_flow);
    }
    return 0;
}
