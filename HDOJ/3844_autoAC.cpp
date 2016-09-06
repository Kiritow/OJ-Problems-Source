#pragma comment(linker, "/STACK:102400000,102400000")  
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<stack>
const int maxn=1e5+1000;
const int maxm=maxn*2;
using namespace std;
struct Edge
{
    int u;
    int v;
    Edge(){}
    Edge(int su,int sv)
    {
        u=su;
        v=sv;
    }
};
int e,n,m,nxt[maxm],head[maxn],pnt[maxm],dfn[maxn],low[maxn],iscut[maxn],bccno[maxn],dfs_clock,bcc_cnt;
vector<int> bcc[maxn];
stack<Edge> s;
int dfs(int u,int fa)
{
    low[u]=dfn[u]=++dfs_clock;
    int child=0;
    for(int i=head[u];i!=-1;i=nxt[i])
    {
        if(!dfn[pnt[i]])
        {
            s.push(Edge(u,pnt[i]));
            child++;
            low[u]=min(low[u],dfs(pnt[i],u));
            if(dfn[u]<=low[pnt[i]])
            {
                iscut[u]=true;
                bcc_cnt++;
                bcc[bcc_cnt].clear();
                for(;;)
                {
                    Edge x=s.top();
                    s.pop();
                    if(bccno[x.u]!=bcc_cnt)
                    {
                        bcc[bcc_cnt].push_back(x.u);
                        bccno[x.u]=bcc_cnt;
                    }
                    if(bccno[x.v]!=bcc_cnt)
                    {
                        bcc[bcc_cnt].push_back(x.v);
                        bccno[x.v]=bcc_cnt;
                    }
                    if(x.u==u&&x.v==pnt[i])
                        break;
                }
            }
        }
        else if(dfn[pnt[i]]<dfn[u]&&pnt[i]!=fa)
        {
            s.push(Edge(u,pnt[i]));
            low[u]=min(low[u],dfn[pnt[i]]);
        }
    }
    if(fa<0&&child==1)
        iscut[u]=0;
    return low[u];
}
void AddEdge(int u,int v)
{
    pnt[e]=v;nxt[e]=head[u];head[u]=e++;
    pnt[e]=u;nxt[e]=head[v];head[v]=e++;
}
void find_bcc(int n)
{
    memset(dfn,0,sizeof(dfn));
    memset(iscut,0,sizeof(iscut));
    memset(bccno,0,sizeof(bccno));
    dfs_clock=bcc_cnt=0;
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            dfs(i,-1);
}
void solve()
{
    find_bcc(n);
    long long ans1=0,ans2=1;
    for(int i=1;i<=bcc_cnt;i++)
    {
        int cut_cnt=0;
        for(int j=0;j<bcc[i].size();j++)
            if(iscut[bcc[i][j]])
                cut_cnt++;
        if(cut_cnt==1)
        {
            ans1++;
            ans2*=(long long)(bcc[i].size()-cut_cnt);
        }
    }
    if(bcc_cnt==1)
    {
        ans1=2;
        ans2=bcc[1].size()*(bcc[1].size()-1)/2;
    }
    printf("%I64d %I64d\n",ans1,ans2);
}
int main()
{
    int cas=1;
    while(scanf("%d",&m)&&m)
    {
        e=n=0;
        memset(head,-1,sizeof(head));
        while(!s.empty())
            s.pop();
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            n=max(n,u);
            n=max(n,v);
            AddEdge(u,v);
        }
        printf("Case %d: ",cas++);
        solve();
    } 
    return 0;
}
