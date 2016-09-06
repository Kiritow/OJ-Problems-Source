#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
 int p,n,i,k=0;
 double Mx,My,SDx,SDy,SE,rxy,a[10002],b[10002];
 while(scanf("%d%d",&p,&n)!=EOF)
 {
  double sum=0,sx=0,sy=0,Sx=0,Sy=0,s=0,t,SD=0,ka,kb;
  if(p==1)
  {
   for(i = 0 ; i < n ; i ++ )
   {
    scanf("%lf",&a[i]);
    sum+=a[i];
   }
   Mx = sum/n;
   for( i = 0 ; i < n ; i ++ )
   s += ((a[i]-Mx)*(a[i]-Mx));
   SDx = sqrt(s/n);
   printf("%.2lf",(a[0]-Mx)/SDx);
   for(i=1;i<n;i++)
   printf(" %.2lf",(a[i]-Mx)/SDx);
   printf("\n");
  }
  else if(p==2)
  {
   for( i = 0 ; i <= n ; i ++ )
   {
    scanf("%lf",&a[i]);
    if(i!=0)
    sum+=a[i];
   }
   Mx=sum/n;
   for( i = 1 ; i <= n ; i ++ )
   s+=((a[i]-Mx)*(a[i]-Mx));
   SDx=sqrt(s/(n-1));
   SE=SDx/sqrt(n);
   t=(Mx-a[0])/SE;
   printf("%.2lf\n",t);
  }
  else
  {
   for( i = 0 ; i < n ; i ++ )
   {
    scanf("%lf",&a[i]);
    sx += a[i];
   }
   for( i = 0 ; i < n ; i ++ )
   {
    scanf("%lf",&b[i]);
    sy += b[i];
   }
   Mx = sx/n;
   for( i = 0 ; i < n ; i ++ )
   Sx += ((a[i]-Mx)*(a[i]-Mx));
   SDx = sqrt(Sx/n);
   My = sy/n;
   for( i = 0 ; i < n ; i ++ )
   Sy += ((b[i]-My)*(b[i]-My));
   SDy = sqrt(Sy/n);
   for( i = 0 ; i < n ; i ++)
   {
    SD += ((a[i]-Mx)*(b[i]-My));
   }
   rxy = SD/(n*SDx*SDy);
   kb = rxy*SDy/SDx;
   ka = My-kb*Mx;
   if(p==3)
   {
      printf("%.2lf\n",rxy);
   }
   else
   {
       printf("%.2lf %.2lf\n",ka,kb);
   }
  }
 }
 return 0;
}
