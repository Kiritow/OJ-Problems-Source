#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int ma[105][105],tar[105][105],tmp[105][105];
int n,m;
void init()
{
  for (int i=1;i<=n;i++)
  {
    for (int j=1;j<=m;j++)
      scanf("%d",&ma[i][j]);
  }
  for (int i=1;i<=n;i++)
  {
    for (int j=1;j<=m;j++)
      scanf("%d",&tar[i][j]);
  }
}
void cpy(int c)
{
  for (int i=1;i<=m;i++)
  {
    for (int j=1;j<=n;j++)
    {
      tmp[j][i]=ma[j][i];
    }
  }
}
void change_col(int a,int b)
{
  for (int i=1;i<=n;i++)
  {
    int temp=tmp[i][a];
    tmp[i][a]=tmp[i][b];
    tmp[i][b]=temp;
  }
}
void change_row(int c)
{
  for (int i=1;i<=m;i++)
    tmp[c][i]^=1;
}
bool ok(int a,int b)
{
  for (int i=1;i<=n;i++)
  {
    if (tar[i][a]!=tmp[i][b])
      return false;
  }
  return true;
}
int main()
{
  while (scanf("%d%d",&n,&m))
  {
    if (n==-1) break;
    init();
    bool ans=0;
    for (int i=1;i<=m;i++)
    {
      cpy(i);
      change_col(1,i);
      for (int j=1;j<=n;j++)
      {
        if (tmp[j][1]!=tar[j][1])
          change_row(j);
      }
      for (int j=2;j<=m;j++)
      {
        for (int k=j;k<=m;k++)
        {
          ans=ok(j,k);
          if (ans)
          {
            change_col(j,k);
            break;
          }
        }
      }
      if (ans) break;
    }
    if (ans) puts("Yes");
    else
      puts("No");
  }
  return 0;
}
