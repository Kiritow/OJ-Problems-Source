#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
struct Edge
{
 int l,r,w;
 bool operator<(const Edge &b)const
 {
 return w>b.w;
 }
};
Edge p[100005];
int set[105];
int m;
int map[105][105],w[105];
int find(int x)
{
 if(x==set[x])return x;
 return set[x]=find(set[x]);
}
int main()
{
 int T;
 scanf("%d",&T);
 while(T--)
 {
 scanf("%d",&m);
 memset(map,0,sizeof(map));
 for(int i=0;i<m;i++)
 {
 int j,t,k;
 scanf("%d",&j);
 scanf("%d%d",&w[j],&t);
 while(t--)
 {
 scanf("%d",&k);
 map[j][k]=map[k][j]=1;
 }
 }
 Edge tmp;
 int tot=0,sum=0;
 for(int i=0;i<m;i++)
 for(int j=i+1;j<m;j++)
 if(map[i][j])
 {
 tmp.l=i;
 tmp.r=j;
 tmp.w=(w[i]+w[j]);
 p[tot++]=tmp;
 sum+=w[i]+w[j];
 }
 sort(p,p+tot);
 for(int i=0;i<m;i++)set[i]=i;
 int cnt=0,ret=0;
 for(int i=0;i<tot;i++)
 {
 int l=find(p[i].l);
 int r=find(p[i].r);
 if(l==r)continue;
 set[l]=r;
 ret+=p[i].w;
 }
 printf("%d\n",sum-ret);
 }
}
