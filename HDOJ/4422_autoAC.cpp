#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int main()
{
    int n,num[11];
    int i,l,j,k;
    int flag;
    int temp;
    int ans;
    while(scanf("%d",&n)!=-1)
    {
        for(i=0;i<n;i++)    scanf("%d",&num[i]);
        if(n<=3)    {printf("1024\n");continue;}
        if(n==4)
        {
            flag=0;
            for(i=0;i<4;i++)
            {
                temp=0;
                for(l=0;l<4;l++)
                {
                    if(i==l)    continue;
                    temp+=num[l];
                }
                if(temp%1024==0)    flag=1;
                if(flag)    break;
            }
            if(flag)    {printf("1024\n");continue;}
            else
            {
                ans=0;
                for(i=0;i<4;i++)
                for(l=0;l<4;l++)
                {
                    if(i==l)    continue;
                    temp=num[i]+num[l];
                    while(temp>1024)    temp-=1024;
                    ans=ans>temp?ans:temp;
                }
                printf("%d\n",ans);
                continue;
            }
        }
        else
        {
            flag=0;
            ans=0;
            for(i=0;i<5;i++)
            for(l=0;l<5;l++)
            for(j=0;j<5;j++)
            {
                if(i!=l && i!=j && l!=j)
                {
                    temp=num[i]+num[l]+num[j];
                    if(temp%1024==0)
                    {
                        temp=0;
                        for(k=0;k<5;k++)    if(k!=i && k!=l && k!=j)    temp+=num[k];
                        while(temp>1024)    temp-=1024;
                        ans=ans>temp?ans:temp;
                        flag=1;
                    }
                }
            }
            if(flag)    printf("%d\n",ans);
            else        printf("0\n");
        }
    }
    return 0;
}
