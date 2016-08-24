#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct ss
{
 char a[100];
 int r,x,y,flag;
}s[10000];
int main()
{
 int t,n,i,k1,k2,k3,max;
 scanf("%d",&t);
 while(t--&&scanf("%d",&n))
 {
  for(i=0;i<n;i++)
  {
   scanf("%s %d.%d.%d",s[i].a,&s[i].r,&s[i].x,&s[i].y);
      if(s[i].x&1) s[i].flag=0;
      else s[i].flag=1;
  }
  max=0;
  for(i=0;i<n;i++)
  {
   if(s[i].flag&&s[i].r>max){max=s[i].r;}
  }
  k1=max;max=0;
  for(i=0;i<n;i++)
  {
   if(s[i].flag&&s[i].r==k1&&max<s[i].x){max=s[i].x;}
  }
  k2=max;max=0;
  for(i=0;i<n;i++)
  {
  if(s[i].r==k1&&s[i].x==k2&&s[i].y>max){k3=i;max=s[i].y;}
  }
  printf("The latest distribution Samuel will choose is %s.\n",s[k3].a);
 }
 return 0;
}
