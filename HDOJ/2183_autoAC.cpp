#include<stdio.h>
#include<math.h>
int main()
{  int x,y,n,a[25][25],i,j;
   while(scanf("%d",&n)&&n!=0)
   { x=n/2+1;y=n/2;
     i=1;
     while(i<=n*n)
     {a[x][y]=i;
      if(i%n!=0)
      {x=x+1;y=y+1;}
      else 
       x=x+2;
      if(x>n-1)x=x-n;
      if(y>n-1)y=y-n;
      i++;
     }
     for(i=0;i<n;i++)
     {for(j=0;j<n;j++)
       printf("%4d",a[i][j]);
      printf("\n"); 
     } 
   }
   return 0;
}
