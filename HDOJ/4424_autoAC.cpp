#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 200200
typedef long long LL;
int parent[MAXN];
LL sum[MAXN];
int cnt[MAXN];
struct Edge{
   int u,v,w;
}edge[MAXN];
int n;
void Initiate()
{
   memset(sum,0,(n+2)*sizeof(sum[0]));
   for(int i=0;i<=n;i++){
      parent[i]=i;
      cnt[i]=1;
   }
}
int Find(int x)
{
   if(x==parent[x])
      return x;
   parent[x]=Find(parent[x]);
   return parent[x];
}
void Union(int r1,int r2,LL w)
{
   parent[r1]=r2;
   cnt[r2]+=cnt[r1];
   sum[r2]+=w;
}
int cmp(const Edge &p,const Edge &q)
{
   return p.w>q.w;
}
int main()
{
   while(~scanf("%d",&n))
   {
      Initiate();
      for(int i=0;i<n-1;i++){
         scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
      }
      sort(edge,edge+n-1,cmp);
      for(int i=0;i<n-1;i++){
         int r1=Find(edge[i].u);
         int r2=Find(edge[i].v);
         LL w=(LL)edge[i].w;
         LL tmp1=cnt[r2]*w+sum[r1];
         LL tmp2=cnt[r1]*w+sum[r2];
         if(tmp1>tmp2){
            Union(r2,r1,tmp1-sum[r1]);
         }else
            Union(r1,r2,tmp2-sum[r2]);
      }
      printf("%I64d\n",sum[Find(1)]);
   }
   return 0;
}
