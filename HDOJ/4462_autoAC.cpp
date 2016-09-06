#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define MAXN 60
bool flag;
int n,m;
int x[20],y[20],r[20];
int map[MAXN][MAXN];
int node[MAXN],total;
void func()
{
  int L,R,T,D;
  memset(map,0,sizeof(map));
  for(int i=1;i<=m;i++)
    map[x[i]][y[i]]=1;
  for(int i=0;i<total;i++)
  {
    int k=node[i]; 
    L=(x[k]-r[k]>0?x[k]-r[k]:1);
    R=(x[k]+r[k]<=n?x[k]+r[k]:n);
    T=(y[k]-r[k]>0?y[k]-r[k]:1);
    D=(y[k]+r[k]<=n?y[k]+r[k]:n);
    for(int j=L;j<=R;j++)
      for(int l=T;l<=D;l++)
        if(abs(j-x[k])+abs(l-y[k])<=r[k])
          map[j][l]=1;
  }
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      if(!map[i][j]) return;
  flag=1;
}
void dfs(int sel,int cnt)
{
  if(sel==total)
    func();
  else
    for(int i=cnt;i<=m;i++)
    {
      node[sel]=i;
      dfs(sel+1,i+1);
    }
}
void solve()
{
  scanf("%d",&m);
  for(int i=1;i<=m;i++)
    scanf("%d%d",&x[i],&y[i]);
  for(int i=1;i<=m;i++)
    scanf("%d",&r[i]);
  flag=0;
  if(m>=n*n)
  {
    printf("0\n");
    return;
  }
  for(int i=1;i<=m;i++)
  {
    total=i;
    dfs(0,1);
    if(flag==1)
    {
      printf("%d\n",i);
      return;
    }
  }
  printf("-1\n");
}
int main()
{
  while(~scanf("%d",&n) && n)
    solve();
  return 0;
}
