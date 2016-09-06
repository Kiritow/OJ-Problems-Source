#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
#define MAXN 5555
struct Edge{
    int v,next;
}edge[MAXN*MAXN];
int n,m,NE;
int head[MAXN];
void Insert(int u,int v)
{
    edge[NE].v=v;
    edge[NE].next=head[u];
    head[u]=NE++;
}
int cnt,rt_son,block;
int low[MAXN],dfn[MAXN];
int blocks[MAXN];
bool mark[MAXN];
void Tarjan(int u,int vv)
{
    low[u]=dfn[u]=++cnt;
    mark[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(v==vv)continue;
        if(dfn[v]==0){
            Tarjan(v,vv);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
               blocks[u]++;
           }
        }else if(mark[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
}
int main()
{
    int u,v,ans;
    while(~scanf("%d%d",&n,&m)){
        NE=0;
        memset(head,-1,sizeof(head));
        while(m--){
            scanf("%d%d",&u,&v);
            Insert(u,v);
            Insert(v,u);
        }
        ans=0;
        for(int u=0;u<n;u++){
            memset(mark,false,sizeof(mark));
            memset(dfn,0,sizeof(dfn));
            fill(blocks,blocks+n,1);
            cnt=block=0;
            for(int v=0;v<n;v++)if(u!=v&&!mark[v]){
                block++;
                blocks[v]=0;
                Tarjan(v,u);
            }
            for(int v=0;v<n;v++)if(v!=u){
                ans=max(ans,block+blocks[v]-1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
