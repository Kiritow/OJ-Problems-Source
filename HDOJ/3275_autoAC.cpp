#include<iostream>
#include<cstring>
using namespace std;
struct node{
    int num;
    int flag;
    int l;
    int r;
    int len;
}p[100005*6];
int n,k,nima,cao;
char a[100005];
void build(int l,int r,int n)
{
    p[n].l=l;
    p[n].r=r;
    p[n].len=r-l+1;
    p[n].flag=0;
    if(l==r)
    {
        if(a[l]=='1')
            p[n].num=0;
        else 
            p[n].num=1;
    }
    else
    {
        int mid=(l+r)/2;
        build(l,mid,n*2);
        build(mid+1,r,n*2+1);
        p[n].num=p[n*2].num+p[n*2+1].num;
    }
}
void pushdown(int n)
{
    p[n].flag=0;
    p[n*2].flag^=1;
    p[n*2+1].flag^=1;
    p[n*2].num=p[n*2].len-p[n*2].num;
    p[n*2+1].num=p[n*2+1].len-p[n*2+1].num;
}
void update(int x,int y,int n)
{     
    if(x==p[n].l&&y==p[n].r)
    {
        p[n].flag^=1;
        p[n].num=p[n].len-p[n].num;
    }
    else
    {
        int mid=(p[n].l+p[n].r)/2;
        if(x>mid)
            update(x,y,n*2+1);
        else if(y<=mid)
            update(x,y,n*2);
        else
        {
            update(x,mid,n*2);
            update(mid+1,y,n*2+1);
        }
    }
}
void insert(int x,int n)
{
    if(nima)
        return ;
    if(p[n].flag==1)
        pushdown(n);
    if(p[n].l==p[n].r)
    {
        if(p[n].num==1)
        {
            nima=p[n].l;
            if(p[n].l+k-1<=cao)
                update(p[n].l,p[n].l+k-1,1);
        }
    }
    else 
    {
        int mid=(p[n].l+p[n].r)/2;
        if(x>mid)
            insert(x,n*2+1);
        else 
        {
            insert(x,n*2);
            insert(mid+1,n*2+1);
        }
    }
}
int main()
{
   int temp,t;
   while(scanf("%d%d",&n,&k)!=EOF&&(n!=0||k!=0))
   {
       cao=n;
       temp=0;
       t=0;
       getchar();
       scanf("%s",a+1);
       build(1,n,1);
       if(p[1].num==0)
       {
           printf("0\n");
           continue;
       }
       if(k==0)
       {
           printf("-1\n");
           continue;
       }
       while(1)
       {
          nima=0;
          insert(temp+1,1);
          temp=nima;
          if(nima==0)
              break;
          if(n-temp+1<k)
              break;
          t++;
       }
       if(nima==0)
           printf("%d\n",t);
       else
           printf("-1\n");
   }
   return 0;
}
