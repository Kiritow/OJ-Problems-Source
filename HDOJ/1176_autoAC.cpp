#include<stdio.h>
#include<string.h>
int a[100008][13];
int max(int a,int b,int c)
{
    if(a<b)
        a=b;
    if(a<c)
        a=c;
    return a;
}
int main()
{
     int i,j,n,x,t,fuck;
     while(scanf("%d",&n)==1&&n)
     {
         memset(a,0,sizeof(a));fuck=0;
         for(i=1;i<=n;i++)
         {
             scanf("%d%d",&x,&t);
             if(t>fuck)    fuck=t;
             a[t][x+1]++;
         }
         for(i=fuck-1;i>0;i--)
             for(j=1;j<=11;j++)
                 a[i][j]+=max(a[i+1][j],a[i+1][j-1],a[i+1][j+1]);
         printf("%d\n",max(a[1][5],a[1][6],a[1][7]));
     }
     return 0;
 }
