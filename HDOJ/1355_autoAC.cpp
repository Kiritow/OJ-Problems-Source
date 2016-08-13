#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int abss(int x)
{
  if(x>0)
  return x;
  return -x;
}
struct aa
{
  int x,y,c;
}a[5000];
bool camp(aa x,aa y)
{
   return x.c>y.c;
}
int main ()
{
  int xx,yy,i,j,sum,maxt,t,q,w,ss;
  scanf("%d",&t);
  while(t--)
  {
      scanf("%d%d%d",&xx,&yy,&maxt);
      for(w=i=1;i<=xx;i++)
      for(j=1;j<=yy;j++)
      {
         scanf("%d",&q);
         a[w].x=i;
         a[w].y=j;
         a[w].c=q;
         w++;
      } 
      sort(a+1,a+w,camp);            
      for(ss=sum=0,i=1;i<w;i++)
      {
        if(i==1)
        sum+=a[1].x;
        else
        sum+=(abss(a[i].x-a[i-1].x)+abss(a[i].y-a[i-1].y));
        if(sum+a[i].x<=maxt-1)
        {
          ss+=a[i].c;
          sum++;
        }
        else
        break;
      }
      printf("%d\n",ss);
   }
   return 0;
}
