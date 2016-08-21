#include<stdio.h>
__int64 prime[100000];
bool flag[1000001];
__int64 sum[1000001];
void init()
{
    __int64 i,j,num=0;
    for(i=2;i<=1000000;i++)
    {
        if(!flag[i])
        {
            prime[num++]=i;
            for(j=i*i;j<=1000000;j=j+i)
                flag[j]=true;
        }
    }
}
__int64 solve(__int64 n)
{
    __int64 i,k,ret=0;
    for(i=0;prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            n=n/prime[i];
            while(n%prime[i]==0)
                n=n/prime[i];
            k=prime[i];
            ret=ret+1;
        }
        if(ret>=2)
            return 1;
    }
    if(n>1)
    {
        ret=ret+1;
        k=n;
    }
    if(ret>=2)
        return 1;
    else
        return k;
}
int main()
{
    __int64 n,i;
    init();
    for(i=3;i<=1000000;i++)
    {
        if(flag[i])
            sum[i]=sum[i-1]+solve(i);
        else
            sum[i]=sum[i-1]+i;
    }
    while(scanf("%d",&n)!=EOF)
        printf("%I64d\n",sum[n]);
    return 0;
}
