#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
int p[5005];
int main()
{
    int m,n,t,k,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&m);
        for(i=1;i<=5001;i++)
        {
            p[i]=1;
        }
        n=m;
        while(n>3)
        {
            k=0;n=0;
            for(i=1;i<=m;i++)
            {
                if(p[i])
                {
                k=k+1;
                if(k%2==0)
                    p[i]=0;
                n=n+p[i];
                }
            }
            k=0;
            if(n<=3)
                break;
            else
                n=0;
            for(i=1;i<=m;i++)
            {
                if(p[i])
                {
                    k=k+1;
                    if(k%3==0)
                        p[i]=0;
                }
                n=n+p[i];
            }
        }
        for(i=1;i<=m;i++)
        {
            if(p[i])
            {
               if(i==1)
                   printf("%d",i);
               else
                   printf(" %d",i);
            }
        }
       printf("\n");
    }
    return 0;
}
