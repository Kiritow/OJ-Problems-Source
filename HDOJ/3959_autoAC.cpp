#include<stdio.h>
long long gcd(long long a,long long b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    int s,m,n,i,j,count=1;
    long long sum,t;
    scanf("%d",&s);
    while(s--)
    {
        sum=1;
        scanf("%d %d",&n,&m);
        for(i=1;i<=110;i++)
        {
            sum=sum*m;
            if(sum>=n) break;
        }
        sum=sum*i;
        t=gcd(sum,n);
        sum=sum/t;n=n/t;
        printf("Case %d: %lld/%d\n",count++,sum,n);
    }
    return 0;
}
