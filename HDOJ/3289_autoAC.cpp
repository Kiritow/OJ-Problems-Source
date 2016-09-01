#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAXN = 100010;
int spos[MAXN],epos[MAXN],sum[MAXN],w[MAXN];
int n,f[MAXN],index;
bool vis[MAXN];
struct edge
{
    int u,v,w;
    edge(int a=0,int b=0,int c=0):u(a),v(b),w(c){}
    bool friend operator<(const edge a,const edge b)
    {
        return a.w<b.w;
    }
};
priority_queue<edge> Q;
vector<int> g[MAXN];
void init()
{
    for(int i=0;i<=n;i++)
    {
        f[i]=i;
        w[i]=sum[i]=0;
        g[i].clear();
    }
}
int find(int x)
{
    if(x==f[x])
        return f[x];
    f[x]=find(f[x]);
    return f[x];
}
void Union(int x,int y)
{
    int a=find(x);
    int b=find(y);
    if(a==b) return ;
    f[a]=b;
    g[x].push_back(y);
    g[y].push_back(x);
}
void Kruskal()
{
    while(!Q.empty())
    {
        Union(Q.top().u,Q.top().v);
        Q.pop();
    }
}
int lowbit(int x)
{
    return x&(-x);
}
void modify(int x,int add)
{
    while(x<=n)
    {
        sum[x]+=add;
        x+=lowbit(x);
    }
}
int get_sum(int x)
{
    int ret=0;
    while(x!=0)
    {
        ret+=sum[x];
        x-=lowbit(x);
    }
    return ret;
}
void dfs(int u)
{
    spos[u]=index;
    vis[u]=true;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!vis[v])
        {
            index++;
            dfs(v);
        }
    }
    epos[u]=index;
}
int main()
{
    int m,k,a,b,c;
    char str[5];
    while(scanf("%d %d",&n,&m)==2)
    {
        init();
        while(m--)
        {
            scanf("%d %d %d",&a,&b,&c);
            Q.push(edge(a,b,c));
        }
        Kruskal();
        index=1;
        memset(vis,false,sizeof(vis));
        dfs(1);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s",str);
            if(str[0]=='G')
            {
                scanf("%d %d",&a,&c);
                modify(spos[a],c);
                w[a]+=c;
            }
            else if(str[0]=='C')
            {
                scanf("%d",&a);
                modify(spos[a],-w[a]);
                w[a]=0;
            }
            else {
                scanf("%d",&a);
                int ans=get_sum(epos[a])-get_sum(spos[a]-1);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
