#include<stdio.h>
#include<string.h>
#define MAXN 1000000+100
struct aa
{
   int a,b,next;
}D[MAXN];
int list[MAXN],tot;
int mkdfs[210];
int mkgx[210];
int mkmp[210][210];
void add(int a,int b)
{
   D[++tot].a=a;
   D[tot].b=b;
   D[tot].next=list[a];
   list[a]=tot;
}
int dfs(int a)
{
  for(int k=list[a];k;k=D[k].next)
  {
     int to=D[k].b;
     if(mkdfs[to])  continue;
     mkdfs[to]=1;
     if(mkgx[to]==-1||dfs(mkgx[to]))
     {
        mkgx[to]=a;
        return 1;
      }
    }
    return 0;
}
int main ()
{
  int G,B,n,i,j,k,t=1,a,b,ans;
  while(~scanf("%d%d%d",&G,&B,&k)&&G+B+k)
  {
      for(i=1;i<=200;i++)
      for(j=1;j<=200;j++)
      mkmp[i][j]=1;   
      for(i=1;i<=k;i++)
      {
         scanf("%d%d",&a,&b);
         mkmp[a][b]=0;
      }
      memset(list,0,sizeof(list));
      tot=0;
      for(i=1;i<=G;i++)
      for(j=1;j<=B;j++)
      {
         if(mkmp[i][j])
         add(i,j);
       }
       memset(mkgx,255,sizeof(mkgx));
       ans=0;
       for(i=1;i<=G;i++)
       {
          memset(mkdfs,0,sizeof(mkgx));
          ans+=dfs(i);
        }
        printf("Case %d: %d\n",t++,G+B-ans);
     }
     return 0;
}
