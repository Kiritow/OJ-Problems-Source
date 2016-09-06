#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define MAXN 2222
#define MAXM 2222222
struct Edge{
    int v,next;
    ll cap;
}edge[MAXM];
int head[MAXN];
int pre[MAXN];
int cur[MAXN];
int level[MAXN];
int gap[MAXN];
int NV,NE,n,m,vs,vt;
void Insert(int u,int v,ll cap,ll cc=0){
    edge[NE].v=v;edge[NE].cap=cap;
    edge[NE].next=head[u];head[u]=NE++;
    edge[NE].v=u;edge[NE].cap=cc;
    edge[NE].next=head[v];head[v]=NE++;
}
ll SAP(int vs,int vt){
    memset(pre,-1,sizeof(pre));
    memset(level,0,sizeof(level));
    memset(gap,0,sizeof(gap));
    for(int i=0;i<=NV;i++)cur[i]=head[i];
    int u=pre[vs]=vs;
    ll aug=-1,maxflow=0;
    gap[0]=NV;
    while(level[vs]<NV){
loop:
        for(int &i=cur[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            if(edge[i].cap&&level[u]==level[v]+1){
                aug==-1?aug=edge[i].cap:aug=min(aug,edge[i].cap);
                pre[v]=u;
                u=v;
                if(v==vt){
                    maxflow+=aug;
                    for(u=pre[u];v!=vs;v=u,u=pre[u]){
                        edge[cur[u]].cap-=aug;
                        edge[cur[u]^1].cap+=aug;
                    }
                    aug=-1;
                }
                goto loop;
            }
        }
        int minlevel=NV;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            if(edge[i].cap&&minlevel>level[v]){
                cur[u]=i;
                minlevel=level[v];
            }
        }
        if(--gap[level[u]]==0)break;
        level[u]=minlevel+1;
        gap[level[u]]++;
        u=pre[u];
    }
    return maxflow;
}
int main(){
    int _case,u,v,w,flag,t=1;
    scanf("%d",&_case);
    while(_case--){
        scanf("%d%d",&n,&m);
        vs=0,vt=n-1,NV=n,NE=0;
        memset(head,-1,sizeof(head));
        for(int i=1;i<=m;i++){
            scanf("%d%d%d%d",&u,&v,&w,&flag);
            Insert(u,v,(ll)w*MAXM+1);
            if(flag)Insert(v,u,(ll)w*MAXM+1);
        }
        ll ans=SAP(vs,vt);
        printf("Case %d: %d\n",t++,ans%MAXM);
    }
    return 0;
}
