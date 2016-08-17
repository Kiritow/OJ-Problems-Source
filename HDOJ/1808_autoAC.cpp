#include<stdio.h>
#include<string.h>
int yushu[100010],d[100010];
int main()
{
    int m,i,j,ans,c,n,sum;
    while(scanf("%d%d",&c,&n)!=EOF)
    {
        if(c==0&&n==0)
            break;
            memset(yushu,0,sizeof(yushu));
        for(i=1;i<=n;i++)
            scanf("%d",&d[i]);
        int st,ed;
        sum=0;
        for(i=1;i<=n;i++)
        {
            sum=(sum+d[i])%c;
            if(sum==0)
            {
                st=1;
                ed=i;
                break;
            }
            else if(yushu[sum])
            {
                st=yushu[sum]+1;
                ed=i;
                break;
            }
            else
                yushu[sum]=i;
        }
        for(i=st;i<=ed;i++)
        printf(i==ed?"%d\n":"%d ",i);
    }
    return 0;
}
