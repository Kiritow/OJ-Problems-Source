#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 110
#define M 10100
#define inf 10000000
using namespace std;
int n,k,dis[N],head[N],gap[N],f[N];  
int a[M*2];
struct Edge{
    int v,c,next;
}edge[M*2];
void init(){
    memset(head,-1,sizeof(head));
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    memset(f,0,sizeof(f));
    k=0;
}
void addedge(int u,int v,int c){
    edge[k].v=v;
    edge[k].c=c;
    edge[k].next=head[u];
    head[u]=k++;
    edge[k].v=u;
    edge[k].c=0;
    edge[k].next=head[v];
    head[v]=k++;
}
int dfs(int p,int s,int t,int limit){
    if(p==t)return limit;
    for(int i=head[p];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(dis[p]==(dis[v]+1) && edge[i].c>0){
            int c=dfs(v,s,t,min(limit,edge[i].c));
            if(c<0)return c;
            if(c>0){
                edge[i].c-=c;
                edge[i^1].c+=c;
                return c;
            }
        }
    }
    int tmp=n;
    for(int i=head[p];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(edge[i].c>0)
            tmp=min(tmp,dis[v]+1);
    }
    if(--gap[dis[p]]==0 || dis[s]>=n)return -1;
    ++gap[dis[p]=tmp];
    return 0;
}
int SAP(int s,int t){
    gap[s]=n;
    int cap=0,now=0;
    while(~(now=dfs(s,s,t,inf))) cap+=now;
    return cap;
}
void dfs1(int u){
    f[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(f[v]==0 && edge[i].c>0)
            dfs1(v);
    }
}
void dfs2(int u){
    f[u]=2;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(f[v]==0 && edge[i^1].c>0)
            dfs2(v);
    }
}
int main(){
    int t,T,i,j;
    int V,E;
    int u,v,c;
    int sap,ans;
    int a1,a2;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        init();
        scanf("%d %d",&V,&E);
        for(i=1;i<=E;i++){
            scanf("%d %d %d",&u,&v,&c);
            addedge(u,v,c);
        }
        n=V;
        ans=SAP(1,V);
        dfs1(1);
        dfs2(V);
        for(i=0;i<k;i++)
            a[i]=edge[i].c;
        a1=0,a2=0;
        for(i=2;i<V;i++){
            if(f[i]==1){
                for(j=0;j<k;j++)
                    edge[j].c=a[j];
                memset(dis,0,sizeof(dis));
                memset(gap,0,sizeof(gap));
                n=i;
                sap=SAP(1,i);
                a1=max(a1,sap);
            }
            if(f[i]==2){
                for(j=0;j<k;j++)
                    edge[j].c=a[j];
                memset(dis,0,sizeof(dis));
                memset(gap,0,sizeof(gap));
                n=V-i+1;
                sap=SAP(i,V);
                a2=max(a2,sap);
            }
        }
        printf("%d\n",ans+min(a1,a2));
    }
    return 0;
}
