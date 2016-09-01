#include<stdio.h>
long long a,b;
long long up(long long a,long long b)
{
    long long t;
    if(a==0) return b;
    while(b!=0)
    {
    t=b;b=a%b;a=t;
    }
return a;
}
int main()
{
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
    if(a==0&&b==0) break;
    printf("%lld\n",a*b/up(a,b)/up(a,b));
}
return 0;
}
