#include<iostream>
#include<string.h>
using namespace std;
__int64 a[100005],c[100005],d[100005],n;
int lowbit(int x)
{
    return x&(-x);
}
__int64 sumc(int x)
{
    __int64 s=0;
    while(x>0)
    {
        s+=c[x];
        x-=lowbit(x);
    }
    return s;
}
__int64 sumd(int x)
{
    __int64 s=0;
    while(x>0)
    {
        s+=d[x];
        x-=lowbit(x);
    }
    return s;
}
void updata(int i,int j)
{
    while(i<=n)
    {
        c[i]+=1;
        d[i]+=j;
        i+=lowbit(i);
    }
}
int main()
{
    while(scanf("%I64d",&n)>0)
    {
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        __int64 s=0,count=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            updata(a[i],a[i]);
            count+=a[i];
            s+=(i-sumc(a[i]))*a[i];
            s+=count-sumd(a[i]);
        }
        printf("%I64d\n",s);
    }
    return 0;
}
