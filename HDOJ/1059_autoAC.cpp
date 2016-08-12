#include<stdio.h>
#include<limits.h>
#define maxn 444444//(1+2+3+4+5+6)*20000=420000
int bag[maxn]={0};
int main()
{
    int w[111],n[7],cnt=1;//2^15(>20000)*6=90
    while(scanf("%d%d%d%d%d%d",&n[1],&n[2],&n[3],&n[4],&n[5],&n[6])&&(n[1]||n[2]||n[3]||n[4]||n[5]||n[6]))
    {
        int i,j,k=1,sum=0;
        printf("Collection #%d:\n",cnt++);
        for(i=1;i<=6;i++)
        {
            int tmp=1;
            sum+=n[i]*i;
            while(n[i]>tmp)
            {
                w[k++]=tmp*i;
                n[i]-=tmp;
                tmp<<=1;
            }
            w[k++]=n[i]*i;
        }
        if(sum&1)
        {
            printf("Can't be divided.\n\n");
            continue;
        }
        sum/=2;
        for(i=1;i<=sum;i++)
            bag[i]=INT_MIN;
        for(i=1;i<k;i++)
        {
            for(j=sum;j>=w[i];j--)
            {
                if(bag[j]<bag[j-w[i]]+w[i])
                    bag[j]=bag[j-w[i]]+w[i];
            }
        }
        if(bag[sum]>=0)
            printf("Can be divided.\n\n");
        else
            printf("Can't be divided.\n\n");
    }
    return 0;
}
