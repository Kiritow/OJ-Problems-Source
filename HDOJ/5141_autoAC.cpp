#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ls(p) p<<1
#define rs(p) p<<1|1
using namespace std;
typedef long long LL;
const int N=100010;
int a[N],b[N];
int dp[N];
int sta[N],en[N];
int len,st;
struct node{
    int l,r;
    int len,sta;
}tree[N<<2];
void pushup(int p)
{
    if(tree[ls(p)].len>tree[rs(p)].len)
    {
        tree[p].len=tree[ls(p)].len;
        tree[p].sta=tree[ls(p)].sta;
    }
    else if(tree[rs(p)].len>tree[ls(p)].len)
    {
        tree[p].len=tree[rs(p)].len;
        tree[p].sta=tree[rs(p)].sta;
    }
    else
        tree[p].sta=max(tree[ls(p)].sta,tree[rs(p)].sta);
}
void build(int p,int l,int r)
{
    tree[p].l=l;tree[p].r=r;
    tree[p].len=-1;
    tree[p].sta=-1;
    if(l==r)
        return;
    int m=(l+r)>>1;
    build(ls(p),l,m);
    build(rs(p),m+1,r);
}
void update(int p,int pos,int len,int st)
{
    if(tree[p].l==tree[p].r)
    {
        if(tree[p].len==len&&tree[p].sta<st)
            tree[p].sta=st;
        else if(tree[p].len<len)
        {
            tree[p].len=len;
            tree[p].sta=st;
        }
        return;
    }
    int m=(tree[p].l+tree[p].r)>>1;
    if(pos<=m) update(ls(p),pos,len,st);
    else update(rs(p),pos,len,st);
    pushup(p);
}
void query(int p,int l,int r)
{
    if(l<=tree[p].l&&tree[p].r<=r)
    {
        if(tree[p].len>len)
        {
            len=tree[p].len;
            st=tree[p].sta;
        }
        else if(tree[p].len==len&&st<tree[p].sta)
            st=tree[p].sta;
        return;
    }
    int m=(tree[p].l+tree[p].r)>>1;
    if(l<=m) query(ls(p),l,r);
    if(r>m) query(rs(p),l,r);
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        LL ret=0;
        int cnt;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            b[i]=a[i];
        }
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        sort(b+1,b+1+n);
        cnt=unique(b+1,b+1+n)-(b+1);
        dp[1]=sta[1]=1;
        build(1,1,cnt);
        int mpp;
        int lest=-1;
        for(int i=1;i<=n;i++)
        {
            len=st=-1;
            mpp=lower_bound(b+1,b+1+cnt,a[i])-b;
            if(mpp==1)
            {
                dp[i]=1;
                sta[i]=i;
            }
            else
                query(1,1,mpp-1);
            if(st==-1)
            {
                dp[i]=1;
                sta[i]=i;
            }
            else
            {
                dp[i]=len+1;
                sta[i]=st;
            }
            update(1,mpp,dp[i],sta[i]);
            lest=max(lest,dp[i]);
        }
        int last=n+1;
        for(int i=n;i>=1;i--)
        {
            if(dp[i]==lest)
            {
                en[i]=last-1;
                last=i;
            }
        }
        for (int i=1;i<=n;++i)
        {
            if (dp[i]==lest)
                ret+=(LL)sta[i]*(LL)(en[i]-i+1);
        }
        printf("%I64d\n", ret);
    }
    return 0;
}
