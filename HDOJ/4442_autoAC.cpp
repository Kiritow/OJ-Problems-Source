#include"stdio.h"
#include"string.h"
#include"stdlib.h"
struct A
{
    __int64 a,b;
}E[100011];
int cmp(const void *a,const void *b)
{
    struct A *c,*d;
    c=(struct A *)a;
    d=(struct A *)b;
    __int64 t1,t2;
    t1=(c->a)*(d->b);
    t2=(d->a)*(c->b);
    if(t1>t2)   return 1;
    else        return -1;
}
int main()
{
    int n;
    int i,l;
    int temp;
    __int64 ans;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)    scanf("%I64d%I64d",&E[i].a,&E[i].b);
        qsort(E,n,sizeof(E[0]),cmp);
        ans=0;
        temp=365*24*60*60;
        for(i=0;i<n;i++)    {ans+=E[i].a+ans*E[i].b;ans%=temp;}
        printf("%I64d\n",ans);
    }
    return 0;
}
