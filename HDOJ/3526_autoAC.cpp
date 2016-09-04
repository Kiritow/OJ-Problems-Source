#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
const int N=5005;
const int M=1000001;
const int inf=1<<30;
int cnt,n,m,s,t;
int head[N];
int NN;
struct Edge
{
 int v,next,w;
}edge[M];
void addedge(int u,int v,int w)
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
int sap()
{
 int pre[N],cur[N],dis[N],gap[N];
 int flow=0,aug=inf,u;
 bool flag;
 for(int i=1;i<=NN;i++)
 {
  cur[i]=head[i];
  gap[i]=dis[i]=0;
 }
 gap[s]=NN;
 u=pre[s]=s;
 while(dis[s]<NN)
 {
  flag=0;
  for(int &j=cur[u];j!=-1;j=edge[j].next)
  {
   int v=edge[j].v;
   if(edge[j].w>0&&dis[u]==dis[v]+1)
   {
    flag=1;
    if(edge[j].w<aug) aug=edge[j].w;
    pre[v]=u;
    u=v;
    if(u==t)
    {
     flow+=aug;
     while(u!=s)
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
  if(flag)
   continue;
  int mindis=NN;
  for(int j=head[u];j!=-1;j=edge[j].next)
  {
   int v=edge[j].v;
   if(edge[j].w>0&&dis[v]<mindis)
            {
              mindis=dis[v];
              cur[u]=j;
            }
  }
  if((--gap[dis[u]])==0)
   break;
  gap[dis[u]=mindis+1]++;
  u=pre[u];
 }
 return flow;
}
int main()
{
    int A[501],B[501];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        s=0;t=n+1; NN=n+2;
        for(int i=1;i<=n;i++)
        scanf("%d",&A[i]);
        for(int i=1;i<=n;i++)
        scanf("%d",&B[i]);
        for(int i=1;i<=n;i++)
        {
         addedge(0,i,A[i]);
         addedge(i,t,B[i]);
        }
        for(int i=1;i<=m;i++)
        {
          int a,b,c;
          scanf("%d%d%d",&a,&b,&c);
          addedge(a,b,c);
          addedge(b,a,c);
        }
        printf("%d\n",sap());
    }
}
