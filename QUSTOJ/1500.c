#include <stdio.h>
void prt_byINT(int inc)
{
    inc++;
    int    a[40][40];                 
    int    i,j;                    
    for(i=1;i<inc;i++)           
    {
        a[i][1]=1;
        a[i][i]=1;
    }
    for(i=1;i<inc;i++)
       for(j=2;j<i;j++)
            a[i][j]=a[i-1][j-1]+a[i-1][j];
    for(i=1;i<inc;i++)
    {
        for(j=1;j<=i;j++)
        {
              printf("%d",a[i][j]);
              if(j!=i) printf(" ");
        }
        printf("\n");   
    }
}
int main()
{
    int a;
    while(scanf("%d",&a)==1)
    {
        prt_byINT(a);
        printf("\n");
    }
    return 0;
}
