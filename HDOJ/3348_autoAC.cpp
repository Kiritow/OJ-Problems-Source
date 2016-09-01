#include<iostream>
#include<stdio.h>
using namespace std;
int coin[5]={1,5,10,50,100};
int main()
{
    int p,a[5];
    int total_case,iii;
    scanf("%d",&total_case);
    for(iii=0;iii<total_case;iii++)
    {
        scanf("%d%d%d%d%d%d",&p,&a[0],&a[1],&a[2],&a[3],&a[4]);
        int ssum=0,i,n1=0; 
        for(i=4;i>=0;i--)
        {
            if((p-ssum)/coin[i]<a[i])
            {
                n1+=(p-ssum)/coin[i];
                ssum+=((p-ssum)/coin[i])*coin[i];
            }
            else
            {
                n1+=a[i];
                ssum+=a[i]*coin[i];
            }
        }
        int sum=0,n2=0;
        for(i=0;i<5;i++)
        {
            int aa=a[i];
            if((p-sum)/coin[i]<a[i])
            {
              n2+=(p-sum)/coin[i];
              sum+=((p-sum)/coin[i])*coin[i];
              a[i]=(p-sum)/coin[i];
            }
            else
            {
               n2+=a[i];
               sum+=a[i]*coin[i];
            }
            if(p-sum<coin[i]&&p-sum!=0&&aa-a[i]>0)
            {
               int j;
               for(j=i-1;j>=0;j--)
               {  
                   if((coin[i]-(p-sum))/coin[j]>a[j])
                   {
                       n2-=a[j];
                       sum-=coin[j]*a[j];
                   }
                   else
                   {
                       n2-=(coin[i]-(p-sum))/coin[j];
                       sum-=((coin[i]-(p-sum))/coin[j])*coin[j];
                   }
               }
               n2++;
               sum+=coin[i];
               break;
            }
        }
        if(sum==p&&ssum==p)
        printf("%d %d\n",n1,n2);
        else
        printf("-1 -1\n");
    }
}
