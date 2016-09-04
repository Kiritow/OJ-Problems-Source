#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 55
#define MAXM 55*55
#define inf 1<<30
using namespace std;
 struct Edge{
     int v,cap,next;
 }edge[MAXM*11];
int map[MAXN][MAXN];
int head[MAXM];
int pre[MAXM];
int cur[MAXM];
int level[MAXM];
int gap[MAXM];
int vs,vt,NV,n,m,k,NE;
bool mark[MAXN][MAXN];
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
 void Insert(int u,int v,int cap,int cc=0){
     edge[NE].cap=cap;edge[NE].v=v;
     edge[NE].next=head[u];head[u]=NE++;
     edge[NE].cap=cc;edge[NE].v=u;
     edge[NE].next=head[v];head[v]=NE++;
 }
 int SAP(int vs,int vt){
     memset(level,0,sizeof(level));
     memset(pre,-1,sizeof(pre));
     memset(gap,0,sizeof(gap));
     for(int i=0;i<=NV;i++)cur[i]=head[i];
     int u=pre[vs]=vs;
     int maxflow=0,aug=-1;
     gap[0]=NV;
     while(level[vs]<NV){
 loop :
         for(int &i=cur[u];i!=-1;i=edge[i].next){
             int v=edge[i].v;
             if(edge[i].cap&&level[u]==level[v]+1){
                 aug==-1?(aug=edge[i].cap):(aug=min(aug,edge[i].cap));
                 pre[v]=u;
                 u=v;
                 if(v==vt){
                     maxflow+=aug;
                     for(u=pre[v];v!=vs;v=u,u=pre[u]){
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
         if((--gap[level[u]])==0)break;
         level[u]=minlevel+1;
         gap[level[u]]++;
         u=pre[u];
     }
     return maxflow;
 } 
int main(){
    int u,v,sum;
    while(~scanf("%d%d%d",&n,&m,&k)){
        vs=0,vt=n*m+1,NV=vt+1,sum=0,NE=0;
        memset(mark,false,sizeof(mark));
        memset(head,-1,sizeof(head));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&map[i][j]);
                sum+=map[i][j];
            }
        }
        for(int i=1;i<=k;i++){
            scanf("%d%d",&u,&v);
            mark[u][v]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((i+j)%2==1){
                    mark[i][j]?Insert(vs,(i-1)*m+j,inf):Insert(vs,(i-1)*m+j,map[i][j]);
                    for(int l=0;l<4;l++){
                        int xx=i+dir[l][0],yy=j+dir[l][1];
                        if(xx>=1&&xx<=n&&yy>=1&&yy<=m){
                            Insert((i-1)*m+j,(xx-1)*m+yy,(map[i][j]&map[xx][yy])*2);
                        }
                    }
                }else{
                    mark[i][j]?Insert((i-1)*m+j,vt,inf):Insert((i-1)*m+j,vt,map[i][j]);
                }
            }
        }
        printf("%d\n",sum-SAP(vs,vt));
    }
    return 0;
}
