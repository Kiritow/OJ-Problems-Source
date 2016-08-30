#include<iostream>
#include<cstring>
#include<stack>
#include<cstdio>
#define INF 0x7ffffff
#define mm(x) memset(x,0,sizeof(x))
using namespace std;
const int N=50000+9;
const int M=100000+9;
stack<int>s;
struct node
{
    int to,next;
    int w;
}G[M];
struct edge
{
    int u,v,w;
}NG[M];
int indegree[N];
int instack[N],paint[N],col,index,dfn[N],low[N];
int head[N],cnt,Ncnt;
class tarjan
{
    public:
        int MIN(int a,int b)
        {
            if(a<b) return a;
            return b;
        }
        void Init()
        {
            while(!s.empty()) s.pop();
            mm(instack);
            mm(paint);
            mm(dfn);
            mm(low);
            mm(indegree);
            index=1;
            col=0;
            memset(head,-1,sizeof(head));
            cnt=0;
            Ncnt=0;
        }
        void add(int a,int b,int c)
        {
            G[cnt].to=b;
            G[cnt].w=c;
            G[cnt].next=head[a];
            head[a]=cnt++;
        }
        void Nadd(int a,int b,int c)
        {
            NG[Ncnt].u=a;
            NG[Ncnt].v=b;
            NG[Ncnt++].w=c;
        }
        void Tarjan(int u)
        {
            dfn[u]=low[u]=index++;
            instack[u]=1;
            s.push(u);
            for(int i=head[u];i+1;i=G[i].next)
            {
                int v=G[i].to;
                if(!dfn[v])
                {
                    Tarjan(v);
                    low[u]=MIN(low[u],low[v]);
                }
                else if(instack[v])
                {
                    low[u]=MIN(low[u],dfn[v]);
                }
            }
            if(low[u]==dfn[u])
            {
                int k=s.top();
                while(k!=u)
                {
                    s.pop();
                    paint[k]=col;
                    instack[k]=0;
                    k=s.top();
                }
                s.pop();
                paint[u]=col;
                instack[u]=0;
                col++;
            }
        }
        void build_NG(int n)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=head[i];j+1;j=G[j].next)
                {
                    int u=i,v=G[j].to;
                    if(paint[u]!=paint[v])
                    {
                        Nadd(paint[u],paint[v],G[j].w);
                    }
                }
            }
        }
}pre_deal;
__int64 directed_mst(int root,int nv,int ne)
{
    __int64 res=0;
    int in[N],pre[N];
    int id[N],vis[N];
    while(true)
    { 
        for(int i=0;i<nv;i++)
        {
            in[i]=INF;
        }
        for(int i=0;i<ne;i++)
        {
            int u=NG[i].u;
            int v=NG[i].v;
            if(NG[i].w<in[v]&&u!=v)
            {
                pre[v]=u;
                in[v]=NG[i].w;
            }
        }
        for(int i=0;i<nv;i++)
        {
            if(i==root) continue;
            if(in[i]==INF) return -1;
        }
        int cntnode=0;
        in[root]=0;
        memset(id,-1,sizeof(id));
        memset(vis,-1,sizeof(vis));
        for(int i=0;i<nv;i++)
        {
            int v=i;
            res+=in[i];
            while(vis[v]!=i&&id[v]==-1&&v!=root)
            {
                vis[v]=i;
                v=pre[v];
            }
            if(id[v]==-1&&v!=root)
            {
                for(int u=pre[v];u!=v;u=pre[u])
                {
                    id[u]=cntnode;
                }
                id[v]=cntnode++;
            }
        } 
        if(cntnode==0) break;
        for(int i=0;i<nv;i++)
        {
            if(id[i]==-1) 
            {
                id[i]=cntnode++;
            }
        }
        for(int i=0;i<ne;i++)
        {
            int v=NG[i].v;
            NG[i].u=id[NG[i].u];
            NG[i].v=id[NG[i].v];
            if(NG[i].u!=NG[i].v)
            {
                NG[i].w-=in[v];
            }
        } 
        nv=cntnode;
        root=id[root];
    }
    return res;
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int root;
        pre_deal.Init();
        while(m--)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            indegree[b]++;
            pre_deal.add(a,b,c);
        }
        for(int i=0;i<n;i++)
        {
            if(!dfn[i])
            pre_deal.Tarjan(i);
        }
        int nv=col--;
        pre_deal.build_NG(n);
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                root=i;
                break;
            }
        }
        __int64 ans=directed_mst(paint[root],nv,Ncnt);
        printf("%I64d\n",ans);
    }
    return 0;
}
