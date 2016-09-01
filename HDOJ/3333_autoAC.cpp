#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;
typedef __int64 ll;
#define N 300010
#define M 100010
struct 
{
    int l,r;
    ll num;
}root[N*4];
struct Q
{
    int s,t,ind;
}q[M];
bool cmp(Q i,Q j)
{
    return i.t<j.t;
}
inline void build(int t,int x,int y)
{
    root[t].l=x;
    root[t].r=y;
    root[t].num=0;
    if(x==y) return;
    int m=(x+y)>>1;
    build(t*2,x,m);
    build(t*2+1,m+1,y);
}
inline void Modefiy(int t,int x,ll val)
{
    int l=root[t].l;
    int r=root[t].r;
    if(l==r)
    {
        root[t].num+=val;return;
    }
    int m=(l+r)>>1;
    if(x<=m) Modefiy(t*2,x,val);
    else Modefiy(t*2+1,x,val);
    root[t].num=root[t*2].num+root[t*2+1].num;
}
inline ll query(int t,int x,int y)
{
    int l=root[t].l;
    int r=root[t].r;
    if(l==x&&r==y)
    {
        return root[t].num;
    }
    int m=(l+r)>>1;
    ll ans=0;
    if(x<=m) ans+=query(t*2,x,min(m,y));
    if(y>m) ans+=query(t*2+1,max(m+1,x),y);
    return ans;
}
int t,n,qn;
ll a[N];
map<ll,int>m;
ll ans[M];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        m.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
        build(1,1,n);
        scanf("%d",&qn);
        for(int i=0;i<qn;i++)
        {
            scanf("%d%d",&q[i].s,&q[i].t);
            q[i].ind=i;
        }
        sort(q,q+qn,cmp);
        int k=1;
        for(int i=0;i<qn;i++)
        {
            for(;k<=q[i].t;k++)
            {
                if(m[a[k]]!=0) Modefiy(1,m[a[k]],-a[k]);
                m[a[k]]=k;
                Modefiy(1,k,a[k]);
            }
            ans[q[i].ind]=query(1,q[i].s,q[i].t);
        }
        for(int i=0;i<qn;i++) printf("%I64d\n",ans[i]);
    }
    return 0;
}
