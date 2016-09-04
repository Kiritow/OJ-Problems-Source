#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXM 555555
#define MAXN 2222
struct Edge{
    int v,cap,next;
}edge[MAXM];
int pre[MAXN];
int cur[MAXN];
int head[MAXN];
int level[MAXN];
int gap[MAXN];
int n,m;
int NV,NE;
int SAP(int vs,int vt){
    memset(pre,-1,sizeof(pre));
    memset(level,0,sizeof(level));
    memset(gap,0,sizeof(gap));
    for(int i=0;i<=NV;i++)cur[i]=head[i];
    int u=pre[vs]=vs,maxflow=0,aug=-1;
    gap[0]=NV;
    while(level[vs]<NV){
loop:
        for(int &i=cur[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            if(edge[i].cap&&level[u]==level[v]+1){
                aug==-1?aug=edge[i].cap:(aug=min(aug,edge[i].cap));
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
        gap[level[u]]--;
        if(gap[level[u]]==0)break;
        level[u]=minlevel+1;
        gap[level[u]]++;
        u=pre[u];
    }
    return maxflow;
}
void Insert(int u,int v,int cap,int cc=0){
    edge[NE].cap=cap;edge[NE].v=v;
    edge[NE].next=head[u];head[u]=NE++;
    edge[NE].cap=cc;edge[NE].v=u;
    edge[NE].next=head[v];head[v]=NE++;
}
int main(){
    int _case,t=1,vs,vt,st,ed,p,dmax,sum;
    scanf("%d",&_case);
    while(_case--){
        scanf("%d%d",&n,&m);
        memset(head,-1,sizeof(head));
        NE=0,dmax=0,vs=0,sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&p,&st,&ed);
            dmax=max(dmax,ed);
            sum+=p;
            Insert(vs,i,p);
            for(int j=st;j<=ed;j++){
                Insert(i,n+j,1);
            }
        }
        vt=n+dmax+1;
        for(int i=1;i<=dmax;i++){
            Insert(n+i,vt,m);
        }
        NV=vt+1;
        printf("Case %d: ",t++);
        if(sum==SAP(vs,vt)){
            puts("Yes");
        }else 
            puts("No");
        puts("");
    }
    return 0;
}
