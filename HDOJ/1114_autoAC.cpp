#include<stdio.h>
#define maxn 2222222
int bag[11111]={0},p[555],w[555];
int main()
{
    int t,e,f,n,realw,i,j;
    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            scanf("%d %d",&e,&f);
            realw=f-e;
            scanf("%d",&n);
            for(i=1;i<=n;i++)
                scanf("%d %d",&p[i],&w[i]);
            for(i=1;i<=realw;i++)
                bag[i]=maxn;
            for(i=1;i<=n;i++)
            {
                for(j=w[i];j<=realw;j++)
                {
                    if(bag[j]>bag[j-w[i]]+p[i])
                        bag[j]=bag[j-w[i]]+p[i];
                }
            }
            if(bag[realw]==maxn)
                printf("This is impossible.\n");
            else
                printf("The minimum amount of money in the piggy-bank is %d.\n",bag[realw]);
        }
    }
    return 0;
}
