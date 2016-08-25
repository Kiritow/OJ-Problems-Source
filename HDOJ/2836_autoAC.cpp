#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=100111;
const int Limit=9901;
int n,h;
int high[N],index[N],lowbit[N];
int C[N];
struct node{
    int index,high;
}E[N];
int cmp(const void *a,const void *b)
{
    node *c,*d;
    c=(node *)a;
    d=(node *)b;
    return c->high-d->high;
}
void update(int k,int dir)
{
    while(0<k && k<=n)
    {
        C[k]+=dir;
        C[k]%=Limit;
        k+=lowbit[k];
    }
}
int sum(int k)
{
    int p=0;
    while(0<k && k<=n)
    {
        p+=C[k];
        p%=Limit;
        k-=lowbit[k];
    }
    return p;
}
int solve()
{
    int i;
    int low,mid,up;
    int a,b,c,temp,x,z;
    int ans;
    memset(C,0,sizeof(C));
    E[0].high=-1111;
    qsort(E,n+1,sizeof(node),cmp);
    for(i=1;i<=n;i++)    index[E[i].index]=i;
    for(i=1;i<=n;i++)
    {
        temp=high[i]-h;
        low=1;up=n;
        while(low<=up)
        {
            mid=(low+up)>>1;
            if(E[mid].high<temp)    low=mid+1;
            else                    up=mid-1;
        }
        a=low;
        b=index[i];
        temp=high[i]+h;
        low=1;up=n;
        while(low<=up)
        {
            mid=(low+up)>>1;
            if(E[mid].high<=temp)    low=mid+1;
            else                    up=mid-1;
        }
        c=low-1;
        if(a-1<=0)    x=0;
        else        x=sum(a-1);
        z=sum(c);
        update(b,z-x+1);
    }
    ans=sum(n)-n;
    while(ans<0)    ans+=9901;
    return ans;
}
int main()
{ 
    int i;
    for(i=1;i<=100000;i++)    lowbit[i]=i&(-i);
    while(scanf("%d%d",&n,&h)!=-1)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&high[i]);
            E[i].index=i;
            E[i].high=high[i];
        }
        printf("%d\n",solve());
    }
    return 0;
}
