#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 111111
#pragma comment(linker,"/STACk:10240000,10240000")
struct Edge{
    int v,next;
}edge[MAXN*4];
int n,m,cnt,NE,BridgeNum;
int head[MAXN];
int parent[MAXN];
int isbridge[MAXN];
int low[MAXN],dfn[MAXN];
bool mark[MAXN];
void Insert(int u,int v)
{
    edge[NE].v=v;
    edge[NE].next=head[u];
    head[u]=NE++;
}
void Tarjan(int u,int father)
{
    int flag=0;
    low[u]=dfn[u]=++cnt;
    mark[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(v==father&&!flag){ flag=1;continue; }
        if(dfn[v]==0){
            parent[v]=u;
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                isbridge[v]=1;
                BridgeNum++;
            }
        }else if(mark[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
}
void LCA(int u,int v)
{
    while(dfn[u]>dfn[v]){
        if(isbridge[u]){
            BridgeNum--;
            isbridge[u]=0;
        }
        u=parent[u];
    }
    while(dfn[v]>dfn[u]){
        if(isbridge[v]){
            BridgeNum--;
            isbridge[v]=0;
        }
        v=parent[v];
    }
    while(u!=v){
        if(isbridge[u]){ BridgeNum--;isbridge[u]=0; }
        if(isbridge[v]){ BridgeNum--;isbridge[v]=0; }
        u=parent[u],v=parent[v];
    }
}
int main()
{
    int u,v,Q,_case=1;
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0)break;
        BridgeNum=NE=cnt=0;
        memset(head,-1,sizeof(head));
        while(m--){
            scanf("%d%d",&u,&v);
            Insert(u,v);
            Insert(v,u);
        }
        memset(isbridge,0,sizeof(isbridge));
        memset(dfn,0,sizeof(dfn));
        memset(mark,false,sizeof(mark));
        for(int i=1;i<=n+1;i++)parent[i]=i;
        Tarjan(1,-1);
        printf("Case %d:\n",_case++);
        scanf("%d",&Q);
        while(Q--){
            scanf("%d%d",&u,&v);
            LCA(u,v);
            printf("%d\n",BridgeNum);
        }
        printf("\n");
    }
    return 0;
}
