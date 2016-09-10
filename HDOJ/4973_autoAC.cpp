#include<cstdio>
#include<ctype.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<stack>
#include<cmath>
#include<queue>
#include<set>
#include<ctime>
#include<string.h>
#include<string>
using namespace std;
#define ll __int64
#define eps 1e-8
template<class T>
inline void scan_d(T &ret) {
    char c; ret=0;
    while((c=getchar())<'0'||c>'9');
    while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
}
struct Tree
{
    ll zuo;
    ll flag;
    bool isleaf;
    ll maxnum,num;
};
Tree T[50000*4];
ll ans;
void build(ll l, ll r, ll rt)
{
    T[rt].flag = 1;
    if(l == r)
    {
        T[rt].isleaf = 1;
        T[rt].zuo = 0;
        T[rt].maxnum = T[rt].num = 1;
        return;
    }
    ll m = (l+r)>>1;
    T[rt].isleaf = 0;
    T[rt].zuo = m-l+1;
    T[rt].maxnum = 1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    T[rt].num=T[rt<<1].num+T[rt<<1|1].num;
}
void pushup(ll rt)
{
    T[rt].maxnum = max(T[rt<<1].maxnum,T[rt<<1|1].maxnum);
    T[rt].num = T[rt<<1].num+T[rt<<1|1].num;
    T[rt].zuo = T[rt<<1].num;
}
void pushdown(ll rt)
{
    if(T[rt].flag != 1)
    {
        T[rt<<1].maxnum *= T[rt].flag;
        if(!T[rt<<1].isleaf) T[rt<<1].zuo *= T[rt].flag;
        T[rt<<1].num *= T[rt].flag;
        T[rt<<1|1].maxnum *= T[rt].flag;
        if(!T[rt<<1|1].isleaf) T[rt<<1|1].zuo *= T[rt].flag;
        T[rt<<1|1].num *= T[rt].flag;
        T[rt<<1].flag *= T[rt].flag;
        T[rt<<1|1].flag *= T[rt].flag;
        T[rt].flag = 1;
    }
}
void update(ll L, ll R, ll l, ll r, ll rt)
{
    if(T[rt].isleaf == 1)
    {
        if(L >= l && R <= r)
        {
            T[rt].num+=R-L+(ll)1;
            T[rt].maxnum = T[rt].num;
        }
        else if(L >= l && L <= r && R >= r)
        {
            T[rt].num+=r-L+(ll)1;
            T[rt].maxnum = T[rt].num;
        }
        else if(L <= l && R >= r)
        {
            T[rt].num+=r-l+(ll)1;
            T[rt].maxnum = T[rt].num;
        }
        else if(L <= l && R >= l && R <= r)
        {
            T[rt].num+=R-l+(ll)1;
            T[rt].maxnum = T[rt].num;
        }
        return;
    }
    if(L <= l && R >= r)
    {
        T[rt].flag *= (ll)2;
        T[rt].num *= (ll)2;
        T[rt].maxnum *= (ll)2;
        T[rt].zuo *= (ll)2;
        return;
    }
    pushdown(rt);
    ll m = l+T[rt].zuo-(ll)1;
    if(L <= m) update(L,R,l,m,rt<<1);
    if(R > m) update(L,R,m+1,r,rt<<1|1);
    pushup(rt);
}
void query(ll L, ll R, ll l, ll r, ll rt)
{
    if(T[rt].isleaf == 1)
    {
        if(L >= l && R <= r)
            ans = max(ans,(ll)(R-L+1));
        else if(L >= l && L <= r && R >= r)
            ans = max(ans,(ll)(r-L+1));
        else if(L <= l && R >= r)
            ans = max(ans,(ll)(r-l+1));
        else if(L <= l && R >= l && R <= r)
            ans = max(ans,(ll)(R-l+1));
        return;
    }
    if(L <= l && R >= r)
    {
        ans = max(ans,T[rt].maxnum);
        return;
    }
    pushdown(rt);
    ll m = l+T[rt].zuo-(ll)1;
    if(L <= m) query(L,R,l,m,rt<<1);
    if(R > m) query(L,R,m+1,r,rt<<1|1);
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case #%d:\n",cas++);
        ll n,m;
        scan_d(n); scan_d(m);
        build(1,n,1);
        while(m--)
        {
            char temp;
            ll l,r;
            scanf("%c",&temp); scan_d(l); scan_d(r);
            if(temp == 'D')
            {
                update(l,r,1,n,1);
                n+=(ll)(r-l+1);
            }
            else
            {
                ans = 0;
                query(l,r,1,n,1);
                printf("%I64d\n",ans);
            }
        }
    }
    return 0;
}
