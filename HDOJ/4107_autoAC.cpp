#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define N  200005
struct cam
{
    int x;
    int y;
    int min;
    int max;
    int v;
}list[N*4];
int n,m,p;
int Min(int x,int y)
{
    return x<y?x:y;
}
int Max(int x,int y)
{
    return x>y?x:y;
}
void build(int k,int x,int y)
{
    list[k].x=x;
    list[k].y=y;
    list[k].min=list[k].max=list[k].v=0;
    if(x==y)
    return;
    int mid=(x+y)/2;
    build(k<<1,x,mid);
    build(k<<1|1,mid+1,y);
}
void lazy(int k)
{
    int v=list[k].v;
    if(v>0)
    {
        list[k<<1].v+=v;
        list[k<<1].min+=v;
        list[k<<1].max+=v;
        list[k<<1|1].v+=v;
        list[k<<1|1].min+=v;
        list[k<<1|1].max+=v;
        list[k].v=0;
    }
}
void update(int k,int a,int b,int c)
{
    if(list[k].x==a&&list[k].y==b&&(list[k].min>=p||list[k].max<p))
    {
        if(list[k].max<p)
        {
            list[k].v+=c;
            list[k].max+=c;
            list[k].min+=c;
        }
        else
        {
            list[k].v+=c*2;
            list[k].max+=c*2;
            list[k].min+=c*2;
        }
        return;
    }
    if(list[k].v>0)
    lazy(k);
    int mid=(list[k].x+list[k].y)/2;
    if(a>mid)
    update(k<<1|1,a,b,c);
    else if(b<=mid)
    update(k<<1,a,b,c);
    else
    {
        update(k<<1,a,mid,c);
        update(k<<1|1,mid+1,b,c);
    }
    list[k].max=Max(list[k<<1].max,list[k<<1|1].max);
    list[k].min=Min(list[k<<1].min,list[k<<1|1].min);
}
int query(int k,int id)
{
    if(list[k].x==id&&list[k].y==id) 
    return list[k].v;
    if(list[k].v>0)
    lazy(k);
    int mid=(list[k].x+list[k].y)/2;
    if(id<=mid)
    return query(k<<1,id);
    else
    return query(k<<1|1,id);
}
int main()
{
    int i,a,b,c;
    while(scanf("%d%d%d",&n,&m,&p)!=EOF)
    {
        build(1,1,n);
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            update(1,a,b,c);
        }
        for(i=1;i<=n;i++)
        {
            if(i==n)
            printf("%d\n",query(1,i));
            else
            printf("%d ",query(1,i));
        }
    }
    return 0;
}
