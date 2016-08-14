#include<stdio.h>
#include<string.h>
int main ()
{
  int a[25],c1[5000],c2[5000];
  int i,j,k,n,m,t,s;
  scanf("%d",&t);
  while(t--)
  {
     scanf("%d",&n);
     for(m=0,i=1;i<=n;i++)
     {
         scanf("%d",&a[i]);
         m+=a[i];
     }       
      for(int ii=1;ii<=n;ii++)
       {
         memset(c1,0,sizeof(c1));
         memset(c2,0,sizeof(c2));
         c1[0]=1;
         for(i=1;i<=n;i++)
         {
            if(i==ii)continue;
            for(j=0;j<=m/2;j++)
            for(k=0;k+j<=m/2&&k<=a[i];k+=a[i])
            c2[k+j]+=c1[j];
            for(j=0;j<=m/2;j++)
            c1[j]=c2[j],c2[j]=0;
                }
               for(s=0,i=m/2-a[ii]+1;i<=m/2;i++)
               s+=c1[i];
               if(ii==1)
               printf("%d",s);
               else
               printf(" %d",s);
           }
           printf("\n");
       }
       return 0;
}
