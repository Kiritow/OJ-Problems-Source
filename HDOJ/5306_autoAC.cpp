#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long int LL;
const int maxn=1000030;
int n,m;
int a[maxn];
struct Node
{
    LL ss;
    int mx,tag,cv;
    void toString() {
        printf("ss: %lld mx: %d tag: %d cv: %d\n",ss,mx,tag,cv);
    }
}T[maxn<<2];
#define lrt (rt<<1)
#define rrt (rt<<1|1)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
void push_up(int rt)
{
    T[rt].ss=T[lrt].ss+T[rrt].ss;
    T[rt].mx=max(T[lrt].mx,T[rrt].mx);
    T[rt].cv=T[lrt].cv+T[rrt].cv;
}
void pnc(int t,int l,int r,int rt)
{
    if(T[rt].tag!=0&&T[rt].tag<=t) return ;
    int all=r-l+1;
    if(T[rt].cv!=all)
    {
        T[rt].ss+=(LL)t*(all-T[rt].cv);
        T[rt].tag=T[rt].mx=t;
        T[rt].cv=all;
    }
}
void push_down(int l,int r,int rt)
{
    if(T[rt].tag)
    {
        int m=(l+r)/2;
        pnc(T[rt].tag,lson); pnc(T[rt].tag,rson);
    }
}
void fix(int t,int l,int r,int rt)
{
    if(T[rt].mx<t) return ;
    if(T[rt].tag>=t) T[rt].tag=0;
    if(l==r)
    {
        T[rt].ss=T[rt].mx=T[rt].tag;
        T[rt].cv=T[rt].tag!=0;
    }
    else
    {
        push_down(l,r,rt);
        int m=(l+r)/2;
        fix(t,lson); fix(t,rson);
        push_up(rt);
    }
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        T[rt].ss=T[rt].mx=T[rt].tag=a[l];
        T[rt].cv=1;
        return ;
    }
    T[rt].tag=0;
    int m=(l+r)/2;
    build(lson); build(rson);
    push_up(rt);
}
void update(int L,int R,int t,int l,int r,int rt)
{
    if(T[rt].mx<=t) return ;
    if(L<=l&&r<=R)
    {
        fix(t,l,r,rt);
        if(l==r)
        {
            T[rt].ss=T[rt].mx=T[rt].tag=t; 
            T[rt].cv=1;
        }
        else push_up(rt);
        pnc(t,l,r,rt);
    }
    else 
    {
        push_down(l,r,rt);
        int m=(l+r)/2;
        if(L<=m) update(L,R,t,lson); 
        if(R>m) update(L,R,t,rson);
        push_up(rt);
    }
}
int query_max(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R) return T[rt].mx;
    push_down(l,r,rt);
    int m=(l+r)/2;
    int ret=0;
    if(L<=m) ret=max(ret,query_max(L,R,lson));
    if(R>m) ret=max(ret,query_max(L,R,rson));
    return ret;
}
LL query_sum(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R) return T[rt].ss;
    push_down(l,r,rt);
    int m=(l+r)/2;
    LL ret=0;
    if(L<=m) ret+=query_sum(L,R,lson);
    if(R>m) ret+=query_sum(L,R,rson);
    return ret;
}
void show(int l,int r,int rt)
{
    printf("rt: %d %d <---> %d\n   ",rt,l,r);
    T[rt].toString();
    if(l==r) return ;
    int m=(l+r)/2;
    show(lson); show(rson);
}
char *ch,buf[40*1024000+5];
void nextInt(int& x)
{
    x=0;
    for(++ch;*ch<=32;++ch);
    for(x=0;'0'<=*ch;ch++) x=x*10+*ch-'0';
}
int main()
{
    ch=buf-1;
    fread(buf,1,1000*35*1024,stdin);
    int T_T;
    nextInt(T_T);
    while(T_T--)
    {
        nextInt(n); nextInt(m);
        for(int i=1;i<=n;i++) nextInt(a[i]);
        build(1,n,1);
        int k,l,r,t;
        while(m--)
        {
            nextInt(k);
            if(k==0)
            {
                nextInt(l); nextInt(r); nextInt(t);
                update(l,r,t,1,n,1);
            }
            else if(k==1)
            {
                nextInt(l); nextInt(r);
                printf("%d\n",query_max(l,r,1,n,1));
            }
            else if(k==2)
            {
                nextInt(l); nextInt(r);
                printf("%I64d\n",query_sum(l,r,1,n,1));
            }
        }
    }
    return 0;
}
