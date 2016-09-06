#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
#define MAXN 1111
int n,m,N,cnt;
bool map[MAXN][MAXN];
bool mark[MAXN];
int ly[MAXN];
int lx[MAXN];
int dfs(int u,int m)
{
    for(int v=1;v<=m;v++){
        if(map[u][v]&&!mark[v]){
            mark[v]=true;
            if(ly[v]==-1||dfs(ly[v],m)){
                ly[v]=u;
                lx[u]=v;
                return 1;
            }
        }
    }
    return 0;
}
int MaxMatch(int n,int m)
{
    memset(ly,-1,sizeof(ly));
    memset(lx,-1,sizeof(lx));
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(mark,false,sizeof(mark));
        ans+=dfs(i,m);
    }
    return ans;
}
vector<vector<int> >g;
vector<vector<int> >ans;
int dfn[MAXN],low[MAXN];
int color[MAXN],_count;
stack<int>S;
void Tarjan(int u)
{
    low[u]=dfn[u]=++cnt;
    mark[u]=true;
    S.push(u);
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(dfn[v]==0){
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(mark[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        _count++;
        int x;
        do{
            x=S.top();
            S.pop();
            mark[x]=false;
            color[x]=_count;
        }while(x!=u);
    }
}
int main()
{
    int _case,k,x,t=1;
    scanf("%d",&_case);
    while(_case--){
        scanf("%d%d",&n,&m);
        memset(map,false,sizeof(map));
        for(int i=1;i<=n;i++){
            scanf("%d",&k);
            while(k--){
                scanf("%d",&x);
                map[i][x]=true;
            }
        }
        cnt=MaxMatch(n,m);
        N=n+m-cnt;
        for(int i=n+1;i<=N;i++)
            for(int j=1;j<=N;j++)
                map[i][j]=true;
        for(int i=m+1;i<=N;i++)
            for(int j=1;j<=N;j++)
                map[j][i]=true;
        MaxMatch(N,N);
        g.clear();
        g.resize(N+2);
        ans.clear();
        ans.resize(N+2);
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(lx[i]!=j&&map[i][j]){
                    g[lx[i]].push_back(j);
                }
            }
        }
        memset(dfn,0,sizeof(dfn));
        memset(mark,false,sizeof(mark));
        _count=cnt=0;
        for(int i=1;i<=N;i++)
            if(dfn[i]==0)Tarjan(i);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(map[i][j]&&color[lx[i]]==color[j]){
                    ans[i].push_back(j);
                }
            }
        }
        printf("Case #%d:\n",t++);
        for(int i=1;i<=n;i++){
            printf("%d",(int)ans[i].size());
            for(int j=0;j<ans[i].size();j++){
                printf(" %d",ans[i][j]);
            }
            puts("");
        }
    }
    return 0;
}
