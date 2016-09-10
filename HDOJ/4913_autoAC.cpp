#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<vector>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn=100000+10;
const int mod=1000000000+7;
ll pow_mod(ll x,ll n)
{
    ll res = 1;
    while(n)
    {
        if(n & 1) res = res*x%mod;
        n>>=1;
        x= x*x%mod;
    }
    return res;
}
struct Node
{
    int a,b,id;
    Node(int a = 0,int b = 0,int id = 0):a(a),b(b),id(id){}
}node[maxn];
bool cmp1(Node x,Node y)
{
    if(x.a == y.a) return x.id < y.id;
    return x.a < y.a;
}
bool cmp2(Node x,Node y)
{
    if(x.b == y.b) return x.a < y.a;
    return x.b < y.b;
}
ll sum[maxn<<2],size[maxn<<2];
void PushUp(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1]*(size[rt<<1] + 1)%mod;
    sum[rt] %= mod;
    size[rt] = size[rt<<1] + size[rt<<1|1] + size[rt<<1]*size[rt<<1|1]%mod;
    size[rt] %= mod;
}
void build(int l,int r,int rt)
{
    sum[rt] = size[rt] = 0;
    if(l == r) return ;
    int m=(l+r)>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
}
void Update(int p,int l,int r,int rt,ll v)
{
    if(l == r)
    {
        sum[rt] = v;
        size[rt] = 1;
        return ;
    }
    int m = (l+r)>>1;
    if(m >= p) Update(p,l,m,rt<<1,v);
    else Update(p,m+1,r,rt<<1|1,v);
    PushUp(rt);
}
ll Query(int L,int R,int l,int r,int rt,ll & sz)
{
    if(l >= L && r <= R)
    {
        sz = size[rt];
        return sum[rt];
    }
    int m = (l+r)>>1;
    if(m >= R) return Query(L,R,l,m,rt<<1,sz);
    else if(m < L) return Query(L,R,m+1,r,rt<<1|1,sz);
    else
    {
        ll res1,res2,sz1,sz2;
        res1 = Query(L,R,l,m,rt<<1,sz1);
        res2 = Query(L,R,m+1,r,rt<<1|1,sz2);
        sz = (sz1 + sz2 + sz1*sz2%mod)%mod;
        return (res1 + res2*(sz1+1))%mod;
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i = 1;i <= n;++i)
            scanf("%d%d",&node[i].a,&node[i].b);
        sort(node + 1,node + n +1,cmp2);
        for(int i = 1;i <= n;++i)
            node[i].id = i;
        sort(node + 1,node + n +1,cmp1);
        build(1,n,1);
        ll ans = 0,lsize,rval,tmp,p2,p3;
        int pos;
        for(int i = 1;i <= n;++i)
        {
            pos = node[i].id;
            p2 = pow_mod(2,node[i].a);
            p3 = pow_mod(3,node[i].b);
            Query(1,pos,1,n,1,lsize);
            ans += p2*p3%mod*(lsize + 1)%mod;
            rval = Query(pos,n,1,n,1,tmp);
            ans += p2*rval%mod;
            ans += p2*lsize%mod*rval%mod;
            ans %= mod;
            Update(pos,1,n,1,p3);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
