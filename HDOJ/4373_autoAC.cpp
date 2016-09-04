#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<cstring>
#include<iomanip>
using namespace std;
#define i64 __int64
#define MM(name,what)   memset(name,what,sizeof(name))
const int inf = 0x3f3f3f3f;
const i64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const double oo = 10e9;
const double eps = 10e-9;
const double pi = acos(-1.0);
const int maxn = 100111;
const i64 mod = 364875103;
const i64 mod1 = 97;
const i64 mod2 = 3761599;
const int maxc = 111;
i64 gcd(i64 _a, i64 _b)  
{  
    if (!_a || !_b)  
    {  
        return max(_a, _b);  
    }  
    i64 _t;  
    while ((_t = _a % _b))  
    {  
        _a = _b;  
        _b = _t;  
    }  
    return _b;  
}  
i64 ext_gcd (i64 _a, i64 _b, i64 &_x, i64 &_y)  
{  
    if (!_b)  
    {  
        _x = 1;  
        _y = 0;  
        return _a;  
    }  
    i64 _d = ext_gcd (_b, _a % _b, _x, _y);  
    i64 _t = _x;  
    _x = _y;  
    _y = _t - _a / _b * _y;  
    return _d;  
}  
i64 invmod (i64 _a, i64 _p)  
{  
    i64 _ans, _y;  
    ext_gcd (_a, _p, _ans, _y);  
    _ans < 0 ? _ans += _p : 0;  
    return _ans;  
}  
i64 dp[maxn];
i64 inv[maxn];
i64 c[maxc][maxc];
i64 n,m;
i64 ans;
i64 a[21];
i64 cx;
void init()
{
    for(int i=1;i<maxn;i++)
    {
        inv[i]=invmod(i,mod2);
    }
    MM(c,0);
    for(int i=0;i<maxc;i++)    
    {
        c[i][i]=1;
        c[i][0]=1;
    }
    for(int i=1;i<maxc;i++)
    {
        for(int j=1;j<maxc;j++)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
            c[i][j]%=mod1;
        }    
    }
    cx = invmod(mod1,mod2);
    return ;
}
i64 lucas(i64 x,i64 y,i64 p=mod1)
{
    if(y>x) return 0;
    i64 re=1;
    i64 dx = x%p;
    i64 dy = y%p;
    re*=c[dx][dy];
    dx = x/p;
    dy = y/p;
    if(dx || dy)
    {
        re*=lucas(dx,dy);
    }
    re%=p;
    return re;
}
i64 find(int x)
{
    i64 t1 = lucas(n+x-1,x);
    i64 t2 = dp[x]; 
    i64 temp = cx;
    temp *= t2-t1;
    temp %= mod2;
    temp = (temp+mod2)%mod2;
    temp *= mod1;
    temp += t1;
    temp %= mod;
    return temp;
}
void start()
{    
    dp[0]=1;
    i64 now,temp;
    for(int i=1;i<=m;i++)
    {
        now = n+i-1;
        dp[i]=dp[i-1]*now;
        dp[i]%=mod2;
        dp[i]*=inv[i];
        dp[i]%=mod2; 
    }    
    return ;
}
int main()
{
    init();
    int k,T;    
    cin>>T;
    for(int tt=1;tt<=T;tt++)
    {
        cin>>n>>m;
        start();
        cin>>k;
        for(int i=1;i<=k;i++)    
        {
            cin>>a[i];
            a[i]++;
        }
        ans=1;
        i64 pre = m;
        i64 now;
        for(int i=k;i>=1;i--)
        {
            now = pre - a[i]+1;
            ans *= find(now);
            ans %= mod;
            pre = a[i]-1;
        }
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
