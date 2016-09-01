#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,x[210],y[210],d[210],rx[210],ry[210];
struct heap
{
  int t1,t2;
  bool cmp(const int &u,const int &v)
  { return t1*x[u]+t2*y[u]>t1*x[v]+t2*y[v]; }
  int n,h[210],e[210];
  void del(int i)
  {
    e[h[i]]=0;
    if (i==n)
    { n--; return; }
    h[i]=h[n--]; e[h[i]]=i;
    down(i); up(i);
  }
  void build(void)
  {
    for(int i=(n>>1);i>=1;i--)
      down(i);
  }
  void up(int i)
  {
    int t,j;
    while(i>1)
    {
      j=(i>>1);
      if (cmp(h[i],h[j]))
      { 
        t=h[i]; h[i]=h[j]; h[j]=t;
        e[h[i]]=i; e[h[j]]=j;
      }
      else break;
      i=j;
    }
  }
  void down(int i)
  {
    int t,j;
    while((j=(i<<1))<=n)
    {
      if (j<n&&cmp(h[j+1],h[j])) j++;
      if (cmp(h[j],h[i]))
      { 
        t=h[i]; h[i]=h[j]; h[j]=t;
        e[h[i]]=i; e[h[j]]=j;
      }
      else break;
      i=j;
    }
  }
}h1,h2,h3,h4;
int main(void)
{
  int u,c,i,l1,r1,l2,r2;
  scanf("%d",&c);
  for(u=1;u<=c;u++)
  {
    scanf("%d",&n);
    h1.n=h2.n=h3.n=h4.n=n;
    for(i=1;i<=n;i++)
    {
      scanf("%d%d%d",x+i,y+i,d+i);
      h1.h[i]=h1.e[i]=i;
      h2.h[i]=h2.e[i]=i;
      h3.h[i]=h3.e[i]=i;
      h4.h[i]=h4.e[i]=i;
    }
    h1.t1=1; h1.t2=1;
    h2.t1=-1; h2.t2=1;
    h3.t1=-1; h3.t2=-1;
    h4.t1=1; h4.t2=-1;
    h1.build();
    h2.build();
    h3.build();
    h4.build();
    for(i=n;i>=1;i--)
    {
      l1=x[h1.h[1]]+y[h1.h[1]]-d[i];
      r1=x[h3.h[1]]+y[h3.h[1]]+d[i];
      l2=-x[h2.h[1]]+y[h2.h[1]]-d[i];
      r2=-x[h4.h[1]]+y[h4.h[1]]+d[i];
      if (i<n)
      {
        r1=min(r1,rx[i+1]+ry[i+1]+d[i+1]-d[i]);
        l1=max(l1,rx[i+1]+ry[i+1]-d[i+1]+d[i]);
        r2=min(r2,-rx[i+1]+ry[i+1]+d[i+1]-d[i]);
        l2=max(l2,-rx[i+1]+ry[i+1]-d[i+1]+d[i]);
      }
      if ((l1+l2)%2!=0)
        if (l1<r1)
          l1++;
        else l2++;
      rx[i]=(l1-l2)/2;
      ry[i]=(l1+l2)/2;
      h1.del(h1.e[i]);
      h2.del(h2.e[i]);
      h3.del(h3.e[i]);
      h4.del(h4.e[i]);
    }
    printf("Case %d:\n",u);
    for(i=1;i<=n;i++)
      printf("%d %d\n",rx[i],ry[i]);
  }
  return 0;
}
