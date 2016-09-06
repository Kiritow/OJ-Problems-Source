#include"stdio.h"
int main()
{
    int n;
    int t1[10];
    int ans;
    int i,j;
    int a,b,t;
    int num[10],k;
    int hash[10];
    int fac[10];
    fac[0]=1;
    for(i=1;i<10;i++)    fac[i]=fac[i-1]*i;
    t1[0]=1;
    for(i=1;i<10;i++)    t1[i]=9*fac[9]/fac[9-(i-1)];
    while(scanf("%d",&n)!=-1)
    {
        if(n<=0)    {printf("0\n");continue;}
        if(n<10)    {printf("%d\n",n-1);continue;}
        k=0;
        while(n)
        {
            num[k++]=n%10;
            n/=10;
        }
        a=0;
        b=k-1;
        while(a<b)
        {
            t=num[a];
            num[a]=num[b];
            num[b]=t;
            a++;
            b--;
        }
        ans=0;
        for(i=0;i<10;i++)    hash[i]=1;
        for(i=1;i<k;i++)    ans+=t1[i];
        ans+=(num[0]-1)*fac[9]/fac[10-k];
        hash[num[0]]=0;
        for(i=1;i<k;i++)
        {
            for(j=0;j<num[i];j++)
            {
                if(hash[j])    ans+=fac[9-i]/fac[10-k];
            }
            if(hash[num[i]]==0)    break;
            hash[num[i]]=0;
        }
        printf("%d\n",ans);
    }
    return 0;
}
