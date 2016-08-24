#include<stdio.h>
int main()
{
    int max,min,n,i,x,t,a[10001],sum1,sum2,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        max=0;
        min=10001;
        s=0;
               for(i=0;i<n;i++)
               {
                scanf("%d",&a[i]);
                if(a[i]>max)
                max=a[i];
                if(a[i]<min)
                min=a[i];
                if(a[i]>=n&&a[i]<0)s=1;
               }
               if(s==1||n==1&&max==0){ printf("Impossible!\n"); continue;}
               sum1=sum2=0;
               if(max==min+1){
                  for(i=0;i<n;i++){
                    if(max==a[i])sum1++;
                    else sum2++;
                  }
                  if(sum2==max)printf("%d\n",max);
                  else  printf("Impossible!\n");
               }
               else if(max==min)
               {    if(max==0)printf("0\n");
                    else {
                    if(max==n-1)printf("%d\n",n);
                    else printf("Impossible!\n");   }
               }
               else
               printf("Impossible!\n");
    }
}
