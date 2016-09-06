#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct node{
       __int64 a;
       __int64 b;
       __int64 c;
       int temp;
       }m[10002];
__int64 cmp(node x,node y)
{  
    if((x.c==y.c)&&((x.a-x.b)*(y.a-y.b)<=0))
    return x.a>y.a;
    if(x.c==y.c)
    return x.temp<y.temp;
    return x.c>y.c;
}
int main()
{    
 int t,n,i,j;
 scanf("%d",&t);
 while(t--)
 {
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  scanf("%I64d%I64d",&m[i].a,&m[i].b);
  m[i].c=m[i].a+m[i].b;
  m[i].temp=i;
     }
  sort(m,m+n,cmp);
  for(i=0;i<n;i++)
  {
  if(m[i].a>m[i].b)
  printf("%I64d+%I64d=[>%I64d]\n",m[i].a,m[i].b,m[i].c);
  else if(m[i].a==m[i].b)
  printf("%I64d+%I64d=[=%I64d]\n",m[i].a,m[i].b,m[i].c);
  else 
  printf("%I64d+%I64d=[<%I64d]\n",m[i].a,m[i].b,m[i].c);
     }
     printf("\n");
 }
 return 0;
}
