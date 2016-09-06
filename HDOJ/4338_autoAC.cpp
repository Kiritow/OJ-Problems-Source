#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
const int N=200005;
#define Log 22
struct Edge
{
    int v;
    Edge *nxt;
}memo[N*10],*cur,*h_bef[N],*h_aft[N];
void addEdge(int u,int v,Edge* head[])
{
    cur->v=v; cur->nxt=head[u];
    head[u]=cur++;
}
int bnum,bn[N];
vector<int> block[N];
bool iscut[N];
bool vis[N];
stack<int> stk;
int dfn[N],low[N],son_root,idx;
int lab[N],id[N],son[N],fa[N];
int dp[N][Log],dep[N];
void tarjan(int pt_u,int pt_pre)
{
    stack<int> stk_tar;
    stk_tar.push(pt_u);    fa[pt_u]=pt_pre;
    while(stk_tar.size())
    {
        int u=stk_tar.top();
        int pre=fa[u];
        if(dfn[u]==0) dfn[u]=low[u]=++idx,stk.push(u);
        Edge* it;
        for(it=h_bef[u];it;it=it->nxt)
        {
            int v=it->v;
            if(v==pre) continue;
            if(fa[v]==-1)
            {
                fa[v]=u;  stk_tar.push(v);
                h_bef[u]=it;
                break;
            }
            else
            {
                if(fa[v]==u)
                {
                    low[u]=min(low[u],low[v]);
                    if(dfn[u]<=low[v])
                    {
                        if(pre==-1) son_root++;
                        else iscut[u]=1;
                        while(1)
                        {
                            int top=stk.top(); stk.pop();
                            block[bnum].push_back(top);
                            if(top==v) break;
                        }
                        block[bnum].push_back(u);
                        bnum++;
                    }
                }
                else low[u]=min(low[u],dfn[v]);
            }
        }
        if(it==NULL) stk_tar.pop();
    }
}
void dfs(int u,int pre,int cnt,int iid)
{
    dep[u]=dep[ dp[u][0] ]+1;
    for(int i=1;i<Log;i++) dp[u][i]= dp[ dp[u][i-1] ][ i-1 ];
    id[u]=iid;    son[u]=cnt+bn[u];
    for(Edge* it=h_aft[u];it;it=it->nxt)
    {
        int v=it->v;
        if(v!=pre)
        {
            dp[v][0]=u;
            dfs(v,u,son[u],iid);
        }
    }
}
int lca(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    for(int st=(1<<(Log-1)),i=Log-1;i>=0;st>>=1,i--)
    {
        if(st<=dep[u]-dep[v])
        {
            u=dp[u][i];
        }
    }
    if(u==v) return u;
    for(int i=Log-1;i>=0;i--)
    {
        if(dp[u][i]!=dp[v][i])
        {
            u=dp[u][i];
            v=dp[v][i];
        }
    }
    return dp[u][0];
}
void init()
{
    cur=memo;
    memset(h_bef,0,sizeof(h_bef));
    memset(h_aft,0,sizeof(h_aft));
    memset(dp,0,sizeof(dp));
    bnum=0; idx=0;    son_root=0;
    while(stk.size()) stk.pop();
    for(int i=0;i<N;i++)
    {
        block[i].clear();
        dfn[i]=0;    low[i]=0;    lab[i]=-1;
        id[i]=i;    iscut[i]=0;    bn[i]=0;
        son[i]=0;    dep[i]=0;      vis[i]=0;
        fa[i]=-1;
    }
}
int main()
{
    int n,m,Q,t_cnt=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i=0;i<m;i++)
        {
            int u,v; scanf("%d%d",&u,&v);
            addEdge(u,v,h_bef);
            addEdge(v,u,h_bef);
        }
        for(int i=0;i<n;i++) if(dfn[i]==0)
        {
            son_root=0;
            tarjan(i,-2);
            if(son_root>1) iscut[i]=1;
        }
        int k=0;
        for(int i=0;i<n;i++) if(iscut[i])
        {
            lab[i]=k; bn[k]=1; k++;
        }
        for(int i=0;i<bnum;i++)
        {
            for(int j=0;j<(int)block[i].size();j++)
            {
                int u=block[i][j];
                if(iscut[u])
                {
                    addEdge(lab[u],k,h_aft);
                    addEdge(k,lab[u],h_aft);
                }
                else lab[u]=k;
            }
            bn[k]=(int)block[i].size();
            k++;
        }
        for(int i=0;i<k;i++) if(dep[i]==0) dfs(i,-1,0,i);
        scanf("%d",&Q);
        printf("Case #%d:\n",++t_cnt);
        while(Q--)
        {
            int s,t; scanf("%d%d",&s,&t);
            if(s==t) printf("%d\n",n-1);
            else if(lab[s]==-1||lab[t]==-1||id[lab[s]]!=id[lab[t]]) printf("%d\n",n);
            else
            {
                s=lab[s]; t=lab[t];
                int parent=lca(s,t);
                int cnt=son[s]+son[t]-2*son[parent]+bn[parent];
                int len=dep[s]+dep[t]-2*dep[parent];
                int ans=cnt-len;
                printf("%d\n",n-ans);
            }
        }
        puts("");
    }
    return 0;
}
