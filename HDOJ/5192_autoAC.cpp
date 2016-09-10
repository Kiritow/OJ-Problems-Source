#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<ctype.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<string.h>
#include<string>
#include<sstream>
#include<bitset>
using namespace std;
#define ll __int64
#define ull unsigned long long
#define eps 1e-8
#define NMAX 1000000000
#define MOD 1000000
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1)
template<class T>
inline void scan_d(T &ret)
{
    char c;
    int flag = 0;
    ret=0;
    while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c == '-')
    {
        flag = 1;
        c = getchar();
    }
    while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
    if(flag) ret = -ret;
}
const int maxn = 50000+10;
ll a[maxn*3], t1[maxn], t2[maxn];
inline int lowbit(int x)
{
    return x&(-x);
}
void add(int x, ll k, int flag)
{
    while(x <= maxn)
    {
        if(flag) t1[x] += k;
        else t2[x] += k;
        x += lowbit(x);
    }
}
ll sum(int x, int flag)
{
    ll ret = 0;
    while(x)
    {
        if(flag) ret += t1[x];
        else ret += t2[x];
        x -= lowbit(x);
    }
    return ret;
}
inline void update(ll *a, ll b, ll h)
{
    if(a[0] < 0 || a[0] > b || (a[0] == b && a[1] < h))
    {
        a[0] = b;
        a[1] = h;
    }
}
int main()
{
    int n,h;
    ll w;
    while(~scanf("%d%I64d%d",&n,&w,&h))
    {
        memset(t1,0,sizeof(t1));
        memset(t2,0,sizeof(t2));
        ll all = 0;
        for(int i = 1; i <= w; i++)
            a[i] = a[i+w+n] = 0;
        for(int i = w+1; i <= w+n; i++)
        {
            scanf("%I64d",&a[i]);
            all += a[i];
        }
        for(int i = 1; i < w; i++)
            add(1,1,0);
        ll suma = 0,ans[2];
        ans[0] = -1;
        for(int i = w; i <= n+w+w; i++)
        {
            int p = (a[i] == 0) ? 1 : a[i];
            add(p,1,0);
            if(i > w)
            {
                if(i <= n+w) add(p,p,1);
                p = (a[i-w] == 0) ? 1 : a[i-w];
                add(p,-1,0);
                if(i-w > w) add(p,-p,1);
            }
            suma += a[i]-a[i-w];
            ll th = suma/w;
            ll tmp[2];
            tmp[0] = -1;
            if(th >= h)
            {
                if(th*w <= all)
                {
                    ll ge = sum(th,0),he = sum(th,1);
                    update(tmp, max(ge*th-he,suma-he-(w-ge)*th),th);
                }
            }
            if(th+1 >= h)
            {
                if((th+1)*w <= all)
                {
                    ll ge = sum(th+1,0),he = sum(th+1,1);
                    update(tmp, max(ge*(th+1)-he,suma-he-(w-ge)*(th+1)),th+1);
                }
            }
            if(tmp[0] == -1)
            {
                if(h*w <= all)
                {
                    ll ge = sum(h,0),he = sum(h,1);
                    update(tmp, max(ge*h-he,suma-he-(w-ge)*h),h);
                }
            }
            update(ans,tmp[0],tmp[1]);
        }
        if(ans[0] == -1) printf("-1\n");
        else printf("%I64d %I64d\n",ans[1],ans[0]);
    }
    return 0;
}
