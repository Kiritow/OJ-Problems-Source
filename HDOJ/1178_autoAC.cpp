#include<stdio.h>
#include<math.h>
int main()
{
     int n,i,k;
     double s;
     while(scanf("%d",&n),n)
     {
          s=1.0*(n+1)*n/6.0*(n+2);
          k=0;
          while(s>=10)
          {
              s=s/10;
              k++;
        } 
        printf("%.2lfE%d\n",s,k);
     }
     return 0;
}
