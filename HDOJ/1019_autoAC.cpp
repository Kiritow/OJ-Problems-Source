#include "stdio.h"
__int64 s[1000];
__int64 hcf(__int64 a,__int64 b)
{
    __int64 r=0;
    while(b!=0)
    {
       r=a%b;
       a=b;
       b=r;
    }
    return(a);
} 
__int64 lcd(__int64 u,__int64 v,__int64 h)
{
    return(u*v/h);
}
int main(int argc, char* argv[])
{
 int n,m,i;
 while(scanf("%d",&n)==1)
 {
  while(n--)
  {
   scanf("%d",&m);
   for(i=0;i<=m-1;i++)
    scanf("%I64d",&s[i]);
   for(i=0;i<=m-2;i++)
   { 
    s[i+1]=lcd(s[i],s[i+1],hcf(s[i],s[i+1]));
   }
   printf("%I64d\n",s[m-1]);
  }
 }
 return 0;
}
