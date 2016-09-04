#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long LL;
const LL MOD = 999983;
vector<LL> p[505];
int T;
LL quick_mod(LL a,LL b,LL m)
{
    LL ans = 1;
    a %= m;
    while(b)
    {
        if(b&1)
        {
            ans = ans*a%m;
            b--;
        }
        b>>=1;
        a=a*a%m;
    }
    return ans;
}
vector<LL> poly_gcd(vector<LL> a,vector<LL> b)
{
    if(b.size() == 0) return a;
    int t = a.size() - b.size();
    vector<LL> c;
    for(LL i=0; i<=t; i++)
    {
        LL tmp = a[i] * quick_mod(b[0],MOD-2,MOD) % MOD;
        for(LL j=0; j<b.size(); j++)
            a[i+j] = (a[i+j] - tmp * b[j] % MOD + MOD) % MOD;
    }
    LL p = -1;
    for(LL i=0; i<a.size(); i++)
    {
        if(a[i] != 0)
        {
            p=i;
            break;
        }
    }
    if(p >= 0)
        for(LL i=p; i<a.size(); i++)
            c.push_back(a[i]);
    return poly_gcd(b,c);
}
bool Import()
{
    LL n,t;
    if(scanf("%d",&T) == 1)
    {
        for(LL i=0;i<T;i++)
        {
            p[i].clear();
            scanf("%I64d",&n);
            for(LL j=0;j<=n;j++)
            {
                scanf("%I64d",&t);
                p[i].push_back(t);
            }
        }
        return true;
    }
    return false;
}
void Work()
{
    if(T==1)
    {
        if(p[0].size() > 1) puts("YES");
        else puts("NO");
        return;
    }
    vector<LL> v = poly_gcd(p[0],p[1]);
    LL i = 2;
    while(i < T && v.size() > 1)
    {
        v = poly_gcd(v,p[i]);
        i++;
    }
    if(v.size() > 1) puts("YES");
    else puts("NO");
}
int main()
{
    while(Import())
        Work();
    return 0;
}
