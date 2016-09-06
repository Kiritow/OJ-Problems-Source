#include <cstdio>
#include <cstring>
const int maxN=255;
const int maxn=550;
const int inf=1<<25;
const int s=0;
int L , W , N , P;
struct edge{
       int v,next,w;
}edge[maxn*maxn];
int head[maxn],cnt;//for sap 
void addedge(int u, int v, int w)
{
     edge[cnt].v=v;
     edge[cnt].w=w;
     edge[cnt].next=head[u];
     head[u]=cnt++;
     edge[cnt].v=u;
     edge[cnt].w=0;
     edge[cnt].next=head[v];
     head[v]=cnt++;
}
int sap(int t)
{
    int pre[maxn],cur[maxn],dis[maxn],gap[maxn];
    int flow=0 , aug=inf ,u;
    bool flag;
    for (int i=0 ; i<=t ; ++i)
    {
        cur[i]=head[i];
        gap[i]=dis[i]=0;
    }
    gap[s]=t+1;
    u=pre[s]=s;
    while (dis[s]<=t)
    {
          flag=0 ; 
          for (int &j=cur[u] ; ~j ; j=edge[j].next)
          {
              int v=edge[j].v;
              if (edge[j].w>0 && dis[u]==dis[v]+1)
              {
                   flag=1;
                   if(edge[j].w<aug)aug=edge[j].w;
                   pre[v]=u;
                   u=v;
                   if (u==t)
                   {
                       flow+=aug;
                       while (u!=s)
                       {
                             u=pre[u];
                             edge[cur[u]].w-=aug;
                             edge[cur[u]^1].w+=aug;
                       }
                       aug=inf;    
                   }  
                   break;        
              }
          }
          if (flag)continue ;
          int mindis=t+1;
          for (int j=head[u]; ~j ; j=edge[j].next)
          {
              int v=edge[j].v;
              if (edge[j].w>0 && dis[v]<mindis)
              {
                 mindis=dis[v];
                 cur[u]=j;
              }
          }
          if(--gap[dis[u]]==0)break;
          gap[dis[u]=mindis+1]++;
          u=pre[u];
    }
    return flow;
}
int x[maxN],y[maxN],r[maxN],p[maxN];//for build graph
bool intersect (int a,int b)
{
     int dis=(x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
     if(dis<=((r[a]+r[b])*(r[a]+r[b])))return true ;
     else return false ;
}
void build_graph()
{
     int n=2*N;
     for (int i=1 ; i<=N ; ++i)
     {
         addedge (i,i+N,p[i]);
         if(y[i]<=r[i])addedge(0,i,inf);
         if(y[i]+r[i]>=W)addedge(i+N,n+1,inf);
         for (int j=i+1 ; j<=N ; ++j)//
         if(intersect(i,j))addedge(i+N,j,inf),addedge(j+N,i,inf);
     }
}
void init ()
{
     memset (head , -1 , sizeof(head));
     cnt=0;
}
int main ()
{
    while (~scanf("%d%d%d%d",&L,&W,&N,&P))
    {
          init();
          for (int i=1 ; i<=N ; ++i)
           scanf("%d %d %d %d",x+i,y+i,r+i,p+i);
          build_graph();
          int ans=P-sap(2*N+1);
          if(ans<0)printf("Our hero has been killed\n");
          else printf("%d\n",ans);
    }
    return 0;
}
