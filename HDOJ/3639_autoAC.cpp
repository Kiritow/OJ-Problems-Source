#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int N=5006;
stack <int> s;
vector <int> adj[N], arc[N], com[N], ans;
int n, m, t, ind, T, sum;
int dfn[N], low[N], id[N], in[N];
bool vs[N];
void tarjan(int u)
{
    dfn[u]=low[u]=T++;
    s.push(u), vs[u]=1;
    int len=(int)adj[u].size();
    for(int i=0; i<len; i++)
    {
        int v=adj[u][i];
        if(dfn[v]==-1)
        {
            tarjan(v);
            if(low[u]>low[v]) low[u]=low[v];
        }
        else if(vs[v] && low[u]>dfn[v]) low[u]=dfn[v];
    }
    if(low[u]==dfn[u])
    {
        for(int v; 1; )
        {
            v=s.top();
            s.pop(), vs[v]=0;
            id[v]=ind, com[ind].push_back(v);
            if(v==u) break;
        }
        ind++;
    }
}
void DFS(int u)
{
    vs[u]=1;
    int len=(int)arc[u].size();
    sum+=(int)com[u].size(); 
    for(int i=0; i<len; i++)
    {
        int v=arc[u][i];
        if(vs[v]) continue;
        DFS(v);
    }
}
int main()
{
    scanf("%d", &t);
    for(int ca=1; ca<=t; ca++)
    {
        scanf("%d%d", &n, &m);
        for(int i=0; i<n; i++) adj[i].clear();
        for(int i=0, a, b; i<m; i++)
        {
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
        }
        for(int i=0; i<n; i++) vs[i]=0, dfn[i]=-1, com[i].clear();
        ind=T=0;
        while(!s.empty()) s.pop();
        for(int i=0; i<n; i++) if(dfn[i]==-1) tarjan(i);
        for(int i=0; i<ind; i++) arc[i].clear(), in[i]=0, dfn[i]=0;
        for(int i=0; i<n; i++)
        {
            int len=(int)adj[i].size();
            for(int j=0; j<len; j++)
            {
                int v=id[adj[i][j]];
                int u=id[i];
                if(u!=v) arc[v].push_back(u), in[u]++;
            }
        }
        for(int i=0; i<ind; i++)
        {
            if(in[i]!=0) continue;
            for(int j=0; j<ind; j++) vs[j]=0;
            sum=0;
            DFS(i);
            dfn[i]=sum;
        }
        int Max=-0x3fffffff;
        for(int i=0; i<ind; i++)
            if(Max<dfn[i]) Max=dfn[i];
        ans.clear();
        for(int i=0; i<ind; i++)
        {
            if(dfn[i]!=Max) continue;
            int len=(int)com[i].size();
            for(int j=0; j<len; j++) ans.push_back(com[i][j]);
        }
        sort(ans.begin(), ans.end());
        int len=(int)ans.size();
        printf("Case %d: %d\n", ca, Max-1);
        for(int i=0; i<len; i++)
        {
            printf("%d", ans[i]);
            if(i==len-1) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
