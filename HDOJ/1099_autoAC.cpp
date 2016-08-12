#include<stdio.h>
#include<string.h>
typedef __int64 ll;
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}
ll numlen(ll n)
{
    ll l=0;
    while(n)
    {
        n=n/10;
        l++;
    }
    return l;
}
int main()
{
    ll n,son,mother,g,d,i;
    while(scanf("%I64d",&n)!=EOF)
    {
        mother=1,son=0;
        for(i=1;i<=n;i++)
            mother=lcm(mother,i);
        for(i=1;i<=n;i++)
            son=son+mother/i;
        son=son*n;
        g=gcd(mother,son);
        son=son/g;
        mother=mother/g;
        d=son/mother;
        son=son%mother;
        if(son==0)
        {
            printf("%d\n",d);
            continue;
        }
        ll l1=numlen(d);
        ll l2=numlen(mother);
        for(i=0;i<=l1;i++)
            printf(" ");
        printf("%I64d\n",son);
        printf("%I64d ",d);
        for(i=1;i<=l2;i++)
            printf("-");
        printf("\n");
        for(i=0;i<=l1;i++)
            printf(" ");
        printf("%I64d\n",mother);
    }
    return 0;
}
