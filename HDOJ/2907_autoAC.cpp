#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct aa
{
   int x,y;
   int t;
}a1[105],a2[105];
bool camp(aa a,aa b)
{
   return a.y<b.y||a.y==b.y&&a.x<b.x;
}
bool fx(aa A,aa B,aa C)
{
   return (B.x-A.x)*(C.y-A.y)>(B.y-A.y)*(C.x-A.x);
}
int main ()
{
    int i,t,mt,n,s,tt,p,q;
    bool mark[105][105];
    scanf("%d",&tt);
    while(tt--)
    {
       scanf("%d%d%d",&p,&q,&n);
       memset(mark,0,sizeof(mark));
       for(i=1;i<n;i++)
       {
           mark[i][i+1]=1;
           mark[i+1][i]=1;
        }
        mark[1][n]=mark[n][1]=1;    
        for(i=1;i<=n;i++)
       {
          scanf("%d%d",&a1[i].x,&a1[i].y);
          a1[i].t=i;
       }   
         sort(a1+1,a1+n+1,camp);
         a2[1]=a1[1];
         for(t=1,i=2;i<=n;i++)
         {
            while(t!=1&&!fx(a2[t-1],a2[t],a1[i]))
            t--;
            a2[++t]=a1[i];
          }
         mt=t;
         a2[++t]=a1[n-1];
         for(i=n-2;i>=1;i--)
         {
            while(t!=mt&&!fx(a2[t-1],a2[t],a1[i]))
            t--;
            a2[++t]=a1[i];
          }
          for(s=0,t--,i=1;i<t;i++)
          if(!mark[a2[i].t][a2[i+1].t])
          s++;
          if(!mark[a2[1].t][a2[t].t])
          s++;
          int ans=-p*s+q*(t-s);
          if(ans>0)
          printf("%d\n",ans);
          else
          printf("0\n");         
   }
   return 0;
}
