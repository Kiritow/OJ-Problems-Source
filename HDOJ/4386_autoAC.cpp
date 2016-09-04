#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
      int t;
      int a,b,c,d,max,count=0;
      double p,ans;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            if(a>b) max=a;
            else max=b;
            if(max<b) max=b;
            if(max<c) max=c;
            if(max<d) max=d;
            if(max-(a+b+c+d-max)>=0)
            {
                  printf("Case %d: -1\n",++count);
                  continue;
            }
            p=(a+b+c+d)*1.0/2;
            ans=sqrt((p-a)*(p-b)*(p-c)*(p-d));
            printf("Case %d: %.6lf\n",++count,ans);
      }
}
