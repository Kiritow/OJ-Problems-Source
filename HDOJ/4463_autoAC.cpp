#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"math.h"
int pre[100];
struct A
{
    int a,b,len;
}eage[3000];
int k;
int x[100],y[100];
void build(int n)
{
    int i;
    for(i=0;i<n;i++)    pre[i]=i;
}
int find(int k)
{
    if(pre[k]==k)    return k;
    pre[k]=find(pre[k]);
    return pre[k];
}
void Union(int f1,int f2)
{
    pre[f1]=f2;
}
int cmp(const void *a,const void *b)
{
    struct A *c,*d;
    c=(struct A *)a;
    d=(struct A *)b;
    return c->len-d->len;
}
int main()
{
    int n;
    int i,l;
    int d1,d2;
    int f1,f2;
    double ans;
    while(scanf("%d",&n),n)
    {
        build(n);
        scanf("%d%d",&d1,&d2);
        d1--;d2--;
        for(i=0;i<n;i++)    scanf("%d%d",&x[i],&y[i]);
        k=0;
        for(i=1;i<n;i++)
        for(l=0;l<i;l++)
        {
            eage[k].a=i;
            eage[k].b=l;
            eage[k].len=(x[i]-x[l])*(x[i]-x[l])+(y[i]-y[l])*(y[i]-y[l]);
            k++;
        }
        qsort(eage,k,sizeof(eage[0]),cmp);
        ans=sqrt((double)(x[d1]-x[d2])*(x[d1]-x[d2])+(y[d1]-y[d2])*(y[d1]-y[d2]));
        Union(d1,d2);
        for(i=0;i<k;i++)
        {
            f1=find(eage[i].a);
            f2=find(eage[i].b);
            if(f1==f2)    continue;
            Union(f1,f2);
            ans+=sqrt((double)eage[i].len);
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
