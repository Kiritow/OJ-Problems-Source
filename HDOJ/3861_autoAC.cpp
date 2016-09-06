#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=55555;
int  dfn[maxn], low[maxn], stack[maxn], belong[maxn], visit[maxn], match[maxn];
bool instack[maxn];
int top, scnt, Index, n, m, T;
vector<int>vt[maxn];
struct Node
{
    int u, v;
}f[2*maxn];
void Init_tarjan()
{
    top=scnt=Index=0;
    for(int i=1; i<=n; i++) dfn[i]=low[i]=instack[i]=0;
}
void tarjan(int u)
{
    stack[++top]=u;
    dfn[u]=low[u]=++Index;
    instack[u]=1;
    for(int i=0; i<vt[u].size(); i++)
    {
        int v=vt[u][i];
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u])
    {
        int v;
        scnt++;
        do
        {
            v=stack[top--];
            instack[v]=0;
            belong[v]=scnt;
        }
        while(u!=v);
    }
}
bool find(int u)
{
    for(int i=0; i<vt[u].size(); i++)
    {
        int v=vt[u][i];
        if(!visit[v])
        {
            visit[v]=1;
            if(match[v]==-1||find(match[v]))
            {
                match[v]=u;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    int cnt=0;
    memset(match,-1,sizeof(match));
    for(int i=1; i<=scnt; i++)
    {
        for(int j=1; j<=scnt; j++) visit[j]=0;
        if(find(i)) cnt++;
    }
    return cnt;
}
int main()
{
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        for(int i=0; i<=n; i++) vt[i].clear();
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&f[i].u,&f[i].v);
            vt[f[i].u].push_back(f[i].v);
        }
        Init_tarjan();
        for(int i=1; i<=n; i++)
            if(!dfn[i]) tarjan(i);
        for(int i=0; i<=n; i++) vt[i].clear();
        for(int i=0; i<m; i++)
        {
            int u=belong[f[i].u], v=belong[f[i].v];
            if(u==v) continue;
            vt[u].push_back(v);
        }
        int ans=hungary();
        cout << scnt-ans <<endl;
    }
    return 0;
}
