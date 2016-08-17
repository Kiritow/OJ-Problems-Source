#include<cstdio>
#include<cstring>
bool dp[1010010];
int main()
{
    int i,a[5],t,count,mem;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",a,a+1,a+2,a+3);
        memset(dp,false,sizeof(dp));
        dp[a[0]]=dp[a[1]]=dp[a[2]]=dp[a[3]]=1;
        for(count=0,i=1;i<1000001;i++)
        {
            if(dp[i])
            {
                dp[i+a[0]]=dp[i+a[1]]=dp[i+a[2]]=dp[i+a[3]]=1;
            }
            else count++,mem=i;
        }
        for(;i<1010000;i++)
        {
            if(!dp[i])mem=-1;
            else
            {
                if(i+a[0]<1010000)dp[i+a[0]]=1;
                if(i+a[1]<1010000)dp[i+a[1]]=1;
                if(i+a[2]<1010000)dp[i+a[2]]=1;
                if(i+a[3]<1010000)dp[i+a[3]]=1;
            }
        }
        printf("%d\n%d\n",count,mem);
    }
    return 0;
}
