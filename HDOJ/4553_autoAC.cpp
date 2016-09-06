#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int L = 100000+10;
struct node
{
    int d,n,s;
    int ls,rs,ms;
    int nsl,nsr,nsm;
} a[L<<2];
void diaosi(int l,int r,int i)
{
    a[i].d = 1;
    a[i].ls = a[i].rs = a[i].ms = 0;
}
void nvshen(int l,int r,int i)
{
    a[i].n = 1;
    a[i].d = 0;
    a[i].ls = a[i].rs = a[i].ms = 0;
    a[i].nsl = a[i].nsr = a[i].nsm = 0;
}
void xuexi(int l,int r,int i)
{
    a[i].s = 1;
    a[i].d = a[i].n = 0;
    a[i].ls = a[i].rs = a[i].ms = r-l+1;
    a[i].nsl = a[i].nsr = a[i].nsm = r-l+1;
}
void pushup(int l,int r,int i)
{
    int mid = (l+r)>>1;
    a[i].ms = max(a[2*i].ms,a[2*i+1].ms);
    a[i].ms = max(a[i].ms,a[2*i].rs+a[2*i+1].ls);
    a[i].ls = a[2*i].ls;
    a[i].rs = a[2*i+1].rs;
    if(a[2*i].ls == mid-l+1)
        a[i].ls+=a[2*i+1].ls;
    if(a[2*i+1].rs == r-mid)
        a[i].rs+= a[2*i].rs;
    a[i].nsm = max(a[2*i].nsm,a[2*i+1].nsm);
    a[i].nsm = max(a[i].nsm,a[2*i].nsr+a[2*i+1].nsl);
    a[i].nsl = a[2*i].nsl;
    a[i].nsr = a[2*i+1].nsr;
    if(a[2*i].nsl == mid-l+1)
        a[i].nsl+=a[2*i+1].nsl;
    if(a[2*i+1].nsr == r-mid)
        a[i].nsr+= a[2*i].nsr;
}
void pushdown(int l,int r,int i)
{
    int mid = (l+r)>>1;
    if(a[i].s)
    {
        xuexi(l,mid,2*i);
        xuexi(mid+1,r,2*i+1);
        a[i].s = 0;
    }
    if(a[i].d)
    {
        diaosi(l,mid,2*i);
        diaosi(mid+1,r,2*i+1);
        a[i].d = 0;
    }
    if(a[i].n)
    {
        nvshen(l,mid,2*i);
        nvshen(mid+1,r,2*i+1);
        a[i].n = 0;
    }
}
void study(int L,int R,int l,int r,int i)
{
    if(L == l && R == r)
    {
        xuexi(l,r,i);
        return ;
    }
    int mid  = (l+r)>>1;
    pushdown(l,r,i);
    if(R<=mid)
        study(L,R,l,mid,2*i);
    else if(L>mid)
        study(L,R,mid+1,r,2*i+1);
    else
    {
        study(L,mid,l,mid,2*i);
        study(mid+1,R,mid+1,r,2*i+1);
    }
    pushup(l,r,i);
}
void insert(int flag,int L,int R,int l,int r,int i)
{
    if(l == L && r == R)
    {
        if(!flag)
            diaosi(l,r,i);
        else
            nvshen(l,r,i);
        return ;
    }
    int mid  = (l+r)>>1;
    pushdown(l,r,i);
    if(R<=mid)
        insert(flag,L,R,l,mid,2*i);
    else if(L>mid)
        insert(flag,L,R,mid+1,r,2*i+1);
    else
    {
        insert(flag,L,mid,l,mid,2*i);
        insert(flag,mid+1,R,mid+1,r,2*i+1);
    }
    pushup(l,r,i);
}
int query(int flag,int t,int l,int r,int i)
{
    if(l==r)
        return l;
    int mid = (l+r)>>1;
    pushdown(l,r,i);
    if(!flag)
    {
        if(a[2*i].ms>=t)
            return query(flag,t,l,mid,2*i);
        else if(a[2*i].rs+a[2*i+1].ls>=t)
            return mid-a[2*i].rs+1;
        else
            return query(flag,t,mid+1,r,2*i+1);
    }
    else
    {
        if(a[2*i].nsm>=t)
            return query(flag,t,l,mid,2*i);
        else if(a[2*i].nsr+a[2*i+1].nsl>=t)
            return mid-a[2*i].nsr+1;
        else
            return query(flag,t,mid+1,r,2*i+1);
    }
}
int main()
{
    int t,i,x,y,ans,cas = 1,n,m;
    char str[20];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        printf("Case %d:\n",cas++);
        study(1,n,1,n,1);
        while(m--)
        {
            scanf("%s",str);
            if(str[0] == 'D')
            {
                scanf("%d",&x);
                if(a[1].ms<x)
                    printf("fly with yourself\n");
                else
                {
                    ans = query(0,x,1,n,1);
                    insert(0,ans,ans+x-1,1,n,1);
                    printf("%d,let's fly\n",ans);
                }
            }
            else if(str[0] == 'N')
            {
                scanf("%d",&x);
                if(a[1].ms<x)
                {
                    if(a[1].nsm<x)
                        printf("wait for me\n");
                    else
                    {
                        ans = query(1,x,1,n,1);
                        insert(1,ans,ans+x-1,1,n,1);
                        printf("%d,don't put my gezi\n",ans);
                    }
                }
                else
                {
                    ans = query(0,x,1,n,1);
                    insert(1,ans,ans+x-1,1,n,1);
                    printf("%d,don't put my gezi\n",ans);
                }
            }
            else
            {
                scanf("%d%d",&x,&y);
                study(x,y,1,n,1);
                printf("I am the hope of chinese chengxuyuan!!\n");
            }
        }
    }
    return 0;
}
