#include<stdio.h>
int main()
{
 int t,h1,m1,h2,m2,n,t1,dh,flag;
 char c;
 scanf("%d",&t);
 while(t--&&scanf("%d:%d-%d:%d",&h1,&m1,&h2,&m2))
 {
  flag=1;
  if(h1-12<0)flag=0;
  if(h2<h1)h2+=24;
  dh=h2-h1;
  t1=60*dh+m2-m1;
  if(t1<420||t1>480)flag=0;
  scanf("%d%*c",&n);
  if(n<8)flag=0;
  scanf("%c%*c",&c);
  if(c!='T')flag=0;
  scanf("%c%*c",&c);
  if(c!='T')flag=0;
  if(flag)printf("Health life,NeverGone you should keep doing!\n");
  else printf("NeverGone should pay attention to his health!\n");
 }
}
