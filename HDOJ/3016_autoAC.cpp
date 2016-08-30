#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100010
#define lch(i) ((i)<<1)
#define rch(i) ((i)<<1|1)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int n;
int dp[N];
struct seg 
{
    int h,l,r,v;
    int ln,rn; 
}s[N];
struct node 
{
    int mark,l,r,n;
    int mid(){
        return (l+r)>>1;
    }
}t[4*N];
int cmp_h(struct seg x ,struct seg y)
{
    return x.h < y.h;
}
void build(int l , int r , int rt)
{
    t[rt].l = l;   t[rt].r = r;
    t[rt].mark = 0; 
    t[rt].n = -1; 
    if(l == r) return ;
    int mid = t[rt].mid();
    int ll = lch(rt);
    int rr = rch(rt);
    build(l , mid , ll);
    build(mid+1 , r , rr);
}
int query(int x ,int rt)
{
    if(t[rt].l == t[rt].r)
        return t[rt].n;
    int mid = t[rt].mid();
    int ll = lch(rt);
    int rr = rch(rt);
    if(t[rt].mark != -1) 
    {
        t[ll].mark = t[rr].mark = t[rt].mark; 
        t[ll].n = t[rr].n = t[rt].n; 
        return t[rt].n;
    }
    if(x<=mid) return query(x , ll);
    else       return query(x , rr);
}
void updata(int l , int r ,int m , int rt)
{
    if(t[rt].l == l && t[rt].r == r)
    {
        t[rt].mark = 1;
        t[rt].n = m;
        return ;
    }
    int mid = t[rt].mid();
    int ll = lch(rt);
    int rr = rch(rt);
    if(t[rt].mark != -1)
    {
        t[ll].mark = t[rr].mark = t[rt].mark;
        t[ll].n = t[rr].n = t[rt].n;
        t[rt].mark = -1;
    }
    if(r<=mid)     updata(l,r,m,ll);
    else if(l>mid) updata(l,r,m,rr);
    else
    {
        updata(l,mid,m,ll);
        updata(mid+1,r,m,rr);
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        n++; s[0].h = 0;  s[0].l = 1;  s[0].r = 100000;  s[0].v = 0;
        for(int i=1; i<n; i++)
            scanf("%d%d%d%d",&s[i].h, &s[i].l, &s[i].r, &s[i].v);
        sort(s,s+n,cmp_h); 
        build(1,100000,1); 
        for(int i=0; i<n; i++)
        {
            s[i].ln = query(s[i].l , 1); 
            s[i].rn = query(s[i].r , 1);
            updata(s[i].l , s[i].r , i , 1);
        }
        memset(dp,0,sizeof(dp));
        dp[n-1] = 100 + s[n-1].v;
        for(int i=n-1; i>=0; i--)
        {
            int ln = s[i].ln;
            int rn = s[i].rn;
            dp[ln] = max(dp[ln] , dp[i] + s[ln].v);
            dp[rn] = max(dp[rn] , dp[i] + s[rn].v);
        }
        printf("%d\n",dp[0] = (dp[0]>0?dp[0]:-1) );
    }
    return 0;
}
