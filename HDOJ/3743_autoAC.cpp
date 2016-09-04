#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int n;
int C[1000111];
int num[1000111];
struct A
{
    int index,num;
}T[1000111];
int cmp(const void *a,const void *b)
{
    struct A *c,*d;
    c=(struct A *)a;
    d=(struct A *)b;
    return c->num-d->num;
}
int sum(int k)
{
    int t=0;
    while(k>0)
    {
        t+=C[k];
        k-=k&(-k);
    }
    return t;
}
void update(int k,int dir)
{
    while(k>0 && k<=n)
    {
        C[k]+=dir;
        k+=k&(-k);
    }
}
int main()
{
    int i;
    __int64 ans;
    while(scanf("%d",&n)!=-1)
    {
        for(i=1;i<=n;i++)    {scanf("%d",&num[i]);T[i].num=num[i];T[i].index=i;}
        T[0].num=-1;
        qsort(T,n+1,sizeof(T[0]),cmp);
        for(i=1;i<=n;i++)    num[T[i].index]=i;
        ans=0;
        memset(C,0,sizeof(C));
        for(i=1;i<=n;i++)
        {
            update(num[i],1);
            ans+=i-sum(num[i]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
