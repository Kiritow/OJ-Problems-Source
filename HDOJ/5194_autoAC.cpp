#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define MID(x,y) ((x+y)>>1)
#define eps 1e-8
#define fre(i,a,b)  for(i = a; i <b; i++)
#define free(i,b,a) for(i = b; i >= a;i--)
#define mem(t, v)   memset ((t) , v, sizeof(t))
#define ssf(n)      scanf("%s", n)
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pf          printf
#define bug         pf("Hi\n")
using namespace std;
typedef __int64 ll;
#define INF 0x3f3f3f3f
#define N 10005
ll C(ll a,ll b)
{
    ll x=1,y=1;
    ll i;
    b=min(b,a-b);
    if(b==0) return 1;
    fre(i,1,b+1)
     {
          x=x*a;
          y=y*i;
          a--;
     }
   return x/y;
}
ll fdd(ll x,ll y)
{
    if(y==0) return x;
    return fdd(y,x%y);
}
int main()
{
    ll i,j;
    ll n,m;
    while(~scanf("%I64d%I64d",&n,&m))
    {
        j=min(n,m);
       ll ans=0;
        fre(i,1,j+1)
          ans=ans+i*C(n,i)*C(m,i);
        ll y=C(n+m,n);
        ll x=fdd(ans,y);
        pf("%I64d/%I64d\n",ans/x,y/x);
    }
    return 0;
}
