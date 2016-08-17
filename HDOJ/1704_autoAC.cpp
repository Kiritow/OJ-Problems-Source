#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define M 505
int a[M][M],n;
void dfs(int x,int y)
{
  int i,j;
  for(i=1;i<=n;i++)
  {
    if(a[i][x]==1)
    {
      a[i][y]=1;
      for(j=1;j<=n;j++)
      {
        if(a[y][j]==1)
            a[i][j]=1;
      }
    }
  }
}
int main()
{
   int m,t,x,y,i,j,sum;
   scanf("%d",&t);
   while(t--)
   {
      sum=0;
      memset(a,0,sizeof(a));
      scanf("%d%d",&n,&m);
      for(i=1;i<=n;i++)
        a[i][i]=1;
      while(m--)
      {
        scanf("%d%d",&x,&y);
        a[x][y]=1;
        dfs(x,y);
      }
      for(i=1;i<=n;i++)
      {
        for(j=1;j<=n;j++)
        {
          if(a[i][j]==1)
            sum++;
        }
      }
      sum=n*(n+1)/2-sum;
      printf("%d\n",sum);
   }
   return 0;
}
