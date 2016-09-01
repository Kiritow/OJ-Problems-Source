#include <stdio.h>
#define MOD 20100501
typedef struct
{
    __int64 val,num;
}Pri;
__int64 prime[2000005];
Pri a[200000];
__int64 up;
void Isprime()
{
    __int64 k,i,j;
    up=0;
    for (i=0;i<2000003;i++)
    {
        prime[i]=true;
    }
    for (i=2;i<2000003;i++)
    {
        if (prime[i]==false) continue;
        k=i;
        while(i*k<=2000000)
        {
            prime[i*k]=false;
            k++;
        }
        a[up++].val=i;
    }
}
void Cplus(__int64 t)
{
    __int64 i,s;
    __int64 k;
    for (i=0;i<up;i++)
    {
        s=0;
        k=a[i].val;
        while(t>=k)
        {
            s=s+t/k;
            k=k*a[i].val;
        }
        a[i].num=a[i].num+s;
    } 
}
void Cminus(__int64 t)
{
    __int64 i,s;
    __int64 k;
    for (i=0;i<up;i++)
    {
        s=0;
        k=a[i].val;
        while(t>=k)
        {
            s=s+t/k;
            k=k*a[i].val;
        }
        a[i].num=a[i].num-s;
    }    
}
__int64 Count(__int64 n,__int64 p)
{
    __int64 i,j,s;
    s=1;
    while(n!=0)
    {
        if (n%2==1)
        {
            s=s*p%MOD;
        }
        p=p*p%MOD;
        n=n/2;
    }
    return s;
}
int main()
{
    __int64 i,t,j,n,T,m;
    __int64 ans;
    scanf("%I64d",&T);
    Isprime();
    while(T--)
    {
        scanf("%I64d%I64d",&n,&m);
        for (i=0;i<up;i++)
        {
            a[i].num=0;
        }
        Cplus(m+n);
        Cminus(m);
        Cminus(n+1);
        t=n+1-m;
        for (i=0;i<up;i++)
        {
            while(t%a[i].val==0)
            {
                a[i].num++;
                t=t/a[i].val;
            }
            if (t==1) break;
        }
        ans=1;
        for (i=0;i<up;i++)
        {
            ans=ans*Count(a[i].num,a[i].val)%MOD;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
