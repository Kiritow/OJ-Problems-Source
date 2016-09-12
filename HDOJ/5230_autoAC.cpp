#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MOD 998244353
using namespace std;
int Now[101005][2],Next[101005][2],s[101005];
void add(int &x,int y)
{
  if (y>MOD) y-=MOD;
  x+=y;
  if (x>MOD) x-=MOD;
} 
int main()
{
  int i,j,T,c,n,l,r;
  memset(s,0,sizeof(s));
  Next[1][1]=1;
  for (i=1;i<=450;i++)
  {
    for (j=1;j<=100000;j++) 
    {
      Now[j][0]=Next[j][0]; Next[j][0]=0;
      Now[j][1]=Next[j][1]; Next[j][1]=0;
    }
    for (j=i;j<=100000;j++)
    {
      add(Now[j+i][0],Now[j][0]+Now[j][1]);
      add(Next[j+1][1],Now[j][0]);
    }
    for (j=1;j<=100000;j++) add(s[j],Now[j][0]+Now[j][1]);
  }
  s[0]=1;
  for (i=1;i<=100000;i++) add(s[i],s[i-1]);
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d%d%d%d",&n,&c,&l,&r);
    l-=c; r-=c; c=s[r];
    if (l!=0) c=s[r]-s[l-1];
    if (c<0) c+=MOD;
    printf("%d\n",c);
  }
  return 0;
}
