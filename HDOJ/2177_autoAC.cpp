#include<stdio.h>
#include<math.h>
int main()
 {
     int n,m,j,k;
     double i;
     while(scanf("%d%d",&n,&m)&&n&&m)
     {
         k=m-n;i=(1+sqrt(5))/2;
         j=k*i;
         if(n==j)
             printf( "0\n" );         
         else 
         {
             printf( "1\n" ); 
             if(n>j)
              printf("%d %d\n",j,j+k );
             for(k=0;k*i<=n;k++)
             if(int(k*i)==n-k)
             printf("%d %d\n",n-k,n);
              for(k=0;k*i<=m;k++)
             if((int(k*i+k)==m)&&(m-k<n))
             printf("%d %d\n",m-k,m);
             for(k=0;k*i<=n+1;k++)
             if((int(k*i)==n)&&(n+k<m))
             printf("%d %d\n",n,n+k);
        }
     }
     return 0;
 }
