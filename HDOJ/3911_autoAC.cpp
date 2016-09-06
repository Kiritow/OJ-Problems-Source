#include<iostream>
using namespace std;
struct node{
   int lone,lzero;
   int rone,rzero;
   int tmax0,tmax1;
   int flag;
   int l,r;
   int mlen;
}p[100001*4];
int a[100001];
int max(int x,int y)
{
    return x>y?x:y;
}
int min(int x,int y)
{
    return x<y?x:y;
}
void update_info(int n)
{
    p[n].lone=p[n*2].lone;
    if(p[n*2].lone==p[n*2].mlen)
        p[n].lone+=p[n*2+1].lone;
    p[n].lzero=p[n*2].lzero;
    if(p[n*2].lzero==p[n*2].mlen)
        p[n].lzero+=p[n*2+1].lzero;
    p[n].rone=p[n*2+1].rone;
    if(p[n*2+1].rone==p[n*2+1].mlen)
        p[n].rone+=p[n*2].rone;
    p[n].rzero=p[n*2+1].rzero;
    if(p[n*2+1].rzero==p[n*2+1].mlen)
        p[n].rzero+=p[n*2].rzero;
    p[n].tmax0=max(p[n*2].tmax0,p[n*2+1].tmax0);
    p[n].tmax0=max(p[n].tmax0,p[n*2].rzero+p[n*2+1].lzero);
    p[n].tmax1=max(p[n*2].tmax1,p[n*2+1].tmax1);
    p[n].tmax1=max(p[n].tmax1,p[n*2].rone+p[n*2+1].lone);
}
void build(int l,int r,int n)
{
    p[n].l=l;
    p[n].r=r;
    p[n].flag=0;
    p[n].mlen=(r-l+1);
    if(l==r)
    {
        if(a[l]==1)
        {
            p[n].lone=1;
            p[n].lzero=0;
            p[n].rone=1;
            p[n].rzero=0;
            p[n].tmax0=0;
            p[n].tmax1=1;
        }
        else
        {
            p[n].lone=0;
            p[n].lzero=1;
            p[n].rone=0;
            p[n].rzero=1;
            p[n].tmax0=1;
            p[n].tmax1=0;
        }
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,n*2);
    build(mid+1,r,n*2+1);
    update_info(n);
}
void pushdown(int n)
{
   p[n*2].flag=p[n*2].flag^1;
   p[n*2+1].flag=p[n*2+1].flag^1;
   swap(p[n*2].lone,p[n*2].lzero);
   swap(p[n*2].rone,p[n*2].rzero);
   swap(p[n*2].tmax1,p[n*2].tmax0);
   swap(p[n*2+1].lone,p[n*2+1].lzero);
   swap(p[n*2+1].rone,p[n*2+1].rzero);
   swap(p[n*2+1].tmax1,p[n*2+1].tmax0);
   p[n].flag=0;
}
void insert(int x,int y,int n)
{
    if(x==p[n].l&&y==p[n].r)
    {
        swap(p[n].lone,p[n].lzero);
        swap(p[n].rzero,p[n].rone);
        swap(p[n].tmax1,p[n].tmax0);
        p[n].flag=p[n].flag^1;
        return ;
    }
    if(p[n].flag==1)
        pushdown(n);
    int mid=(p[n].l+p[n].r)/2;
    if(y<=mid)
        insert(x,y,n*2);
    else if(x>mid)
        insert(x,y,n*2+1);
    else
    {
        insert(x,mid,n*2);
        insert(mid+1,y,n*2+1);
    }
    update_info(n);
}
int sum(int x,int y,int n)
{
    if(x==p[n].l&&y==p[n].r)
       return p[n].tmax1;
    int mid=(p[n].l+p[n].r)/2;
    if(p[n].flag==1)
        pushdown(n);
    if(y<=mid)
        return sum(x,y,n*2);
    else if(x>mid)
        return sum(x,y,n*2+1);
    else
    {
        int left=0,right=0,midden=0;
        midden=min(mid-x+1,p[n*2].rone)+min(y-mid,p[n*2+1].lone);
        left=sum(x,mid,n*2);
        right=sum(mid+1,y,n*2+1);
        return max(midden,max(left,right));
    }
}
int main()
{
    int n,m,i,nima,x,y;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        build(1,n,1);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d",&nima,&x,&y);
            if(nima==1)
                insert(x,y,1);
            else
                printf("%d\n",sum(x,y,1));
        }
    }
    return 0;
}
