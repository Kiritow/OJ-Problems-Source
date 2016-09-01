#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn=2001;
int n,m,root,sum,NE=0,vis[maxn],head[maxn];
struct node
{
    int u,v,w,next;
} Edge[maxn];
void addEdge(int u,int v,int w)
{
    Edge[NE].u=u,Edge[NE].v=v,Edge[NE].w=w,Edge[NE].next=head[u];
    head[u]=NE++;
}
void dfs(int u,int fa)
{
    int i,j;
    for(i=head[u];i!=-1;i=Edge[i].next)
    {
        int v=Edge[i].v;
        if(v==fa)continue;
        dfs(v,u);
        if(vis[v])
        {
             sum+=Edge[i].w;
             vis[u]=1;
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,j,a,b,c;
        sum=NE=0;
        memset(vis,0,sizeof(vis));
        memset(head,-1,sizeof(head));
        for(i=1; i<=m; i++)
        {
            scanf("%d",&root);
            vis[root]=1;
        }
        for(i=1; i<n; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            addEdge(a,b,c);
            addEdge(b,a,c);
        }
        dfs(root,-1);
        cout<<sum<<endl;
    }
    return 0;
}
