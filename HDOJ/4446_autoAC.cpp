#include <iostream>
#include <queue>
#include <cstring>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int ma=1000010;
const int inf=1<<25;
int n;
int c[ma<<2];
int rc[ma];
int add[ma<<2];
int rrt;
void pushup(int rt)
{
     c[rt]=min(c[rt<<1],c[rt<<1|1]);
}
void pushdown(int rt,int m)
{
     if(add[rt])
     {
         add[rt<<1]+=add[rt];
         add[rt<<1|1]+=add[rt];
         c[rt<<1]+=add[rt];
         c[rt<<1|1]+=add[rt];
         add[rt]=0;
     }
}
void build(int l,int r,int rt)
{
     add[rt]=0;
     if(l==r)
     {
           scanf("%d",&c[rt]);
           return ;
     }
     int m=(l+r)>>1;
     build (lson);
     build (rson);
     pushup(rt);
} 
int query(int l,int r,int rt)
{
    if(l==r){rrt=rt;return l;}
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(c[rt<<1]<=c[rt<<1|1])
    return query(lson);
    else return query(rson);
}
void update(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        add[rt]--;
        c[rt]--;
        return ;
    }
    pushdown(rt,r-1+1);
    int m=(l+r)>>1;
    if(L<=m) update(L,R,lson);
    if(m<R)update(L,R,rson); 
    pushup(rt);
}
void update2(int p,int l,int r,int rt)
{
     if(l==r)
     {
         c[rt]=inf;
         return ;
     }
     int m=(l+r)>>1;
     if(p<=m)update2(p,lson);
     else update2(p,rson);
     pushup(rt);
}
int main()
{
    while(scanf("%d",&n),n)
    {
        int id=0;
        int flag=0;
        build(1,n,1);
        queue <int> a;
        queue <int> b;
        while(a.size()+b.size()!=2*n)
        {
            int qq=query(1,n,1);
            if(c[rrt]<0)
            {
                    flag=1;break;
            } 
            if(c[rrt]==0)
            {
                 a.push(qq);
                 b.push(-qq);
                 if(qq!=1)
                 update(1,qq-1,1,n,1);                
                 update2(qq,1,n,1);
            }
            else
            {
                if(b.size()==0){flag=1;break;}
                int t=b.front();
                if(-t<n)
                update(-t+1,n,1,n,1);
                b.pop();
                a.push(t);
            }
        }
        if(flag)
        {
                printf("Impossible\n");
                }else{
                      int d[200010];
                      int i=0; 
        while(a.size()!=0)
        {d[i++]=a.front();a.pop();} 
        while(b.size()!=0)
        {d[i++]=b.front();b.pop();} 
        for(i=2*n-1;i>=0;i--)
        printf("%d ",d[i]);
        puts("");
        }
    }
    return 0; 
}
