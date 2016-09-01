#include<iostream>
#include<string.h>
#include<algorithm>
#define N 55
#define M 10000
#define inf 0x7fffffff
using namespace std;
int cnt[N][2],dis[N][2];
bool h[N][2];
int NE,head[N];
int n,m;
struct node{
    int next,v,w;
    node(){};
    node(int a,int b,int c){
        next=a;v=b;w=c;
    }
}E[M];
void init(){
    NE=0;
    memset(head,-1,sizeof(head));
}
void insert(int u,int v,int w){
    E[NE]=node(head[u],v,w);
    head[u]=NE++;
}
void dijkstra(int beg,int end){
    for(int i=0;i<=n;i++){
        dis[i][0]=dis[i][1]=inf;
        cnt[i][0]=cnt[i][1]=0;
    }
    memset(h,0,sizeof(h));
    dis[beg][0]=0;
    cnt[beg][0]=1;
    while(true){
        int u,flag;
        int Min=inf;
        for(int i=0;i<n;i++){
            if(!h[i][0]&&dis[i][0]<Min){
                Min=dis[i][0];
                u=i;flag=0;
            }
            else if(!h[i][1]&&dis[i][1]<Min){
                Min=dis[i][1];
                u=i;flag=1;
            }
        }
        if(u==end&&flag==1) break;
        if(Min==inf) break;
        h[u][flag]=1;
        for(int i=head[u];i!=-1;i=E[i].next){
            int v=E[i].v;
            int w=dis[u][flag]+E[i].w;
            if(dis[v][0]>w){
                if(dis[v][0]!=inf){
                    dis[v][1]=dis[v][0];
                    cnt[v][1]=cnt[v][0];
                }
                dis[v][0]=w;
                cnt[v][0]=cnt[u][flag];
            }
            else if(dis[v][0]==w)
                cnt[v][0]+=cnt[u][flag];
            else if(dis[v][1]>w){
                dis[v][1]=w;
                cnt[v][1]=cnt[u][flag];
            }
            else if(dis[v][1]==w)
                cnt[v][1]+=cnt[u][flag];
        }
    }
    printf("%d %d\n",dis[end][1],cnt[end][1]);
}
int main(void){
    int s,t;
    while(~scanf("%d%d%d%d",&n,&m,&s,&t)){
        init();
        while(m--){
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            insert(x,y,w);
        }
        dijkstra(s,t);
    }
}
