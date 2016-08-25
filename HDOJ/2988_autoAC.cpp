#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 200010
struct node{
  int u,v,w;
}edge[maxn];
int parent[maxn];
int n,m,ans,sum;
int cmp(const node &p,const node &q){
    return p.w<q.w;
}
int Find(int x){
 int i;
 for(i=x;parent[i]>=0;i=parent[i])
 ;
 while(i!=x){
  int tmp=parent[x];
  parent[x]=i;
  x=tmp;
 }
 return i;
}
void Union(int x,int y){
 int r1=Find(x),r2=Find(y);
 if(r1==r2) return;
 if(parent[r1]<parent[r2]){
  parent[r1]+=parent[r2];
  parent[r2]=r1;
 }else {
       parent[r2]+=parent[r1];
       parent[r1]=r2;
    }
}
int Kruskal(){
   int s=0;
    for(int i=0;i<m;i++){
       int u=edge[i].u,v=edge[i].v,w=edge[i].w;
       if(Find(u)!=Find(v)){
          s+=w;
          Union(u,v);
       }
    }
    return s;
 }
int main(){
 while(~scanf("%d %d",&n,&m)&&m+n){
   memset(parent,-1,sizeof(parent));
   ans=0;
   for(int i=0;i<m;i++){
    scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].w);
    ans+=edge[i].w;
   }
   sort(edge,edge+m,cmp);
   sum=Kruskal();
   printf("%d\n",ans-sum);
 }
 return 0;
}
