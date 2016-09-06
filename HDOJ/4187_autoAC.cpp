#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define MOD 100000007
#define PRIME_SIZE 500005
#define _int64 long long
using namespace std;
int prime[PRIME_SIZE], phi[PRIME_SIZE];
bool primes[PRIME_SIZE];
void Euler_primes_phi_mu()
{
    phi[1]=1;
    for (int i=2; i<PRIME_SIZE; i++)
    {
        if (primes[i]==0)
            phi[i]=i-1, prime[++prime[0]]=i;
        for (int j=1; j<=prime[0] && prime[j]*i<PRIME_SIZE; j++)
        {
            primes[prime[j]*i]=true;
            if (i%prime[j]==0) { phi[i*prime[j]] = phi[i]*prime[j]; break; }
            phi[i*prime[j]] = phi[i]*(prime[j]-1);
        }
    }
}
_int64 GCD(_int64 a, _int64 b) { for (_int64 t; a%b; t=a%b, a=b, b=t) ; return b; }
_int64 pow_mod(_int64 a, _int64 n)
{
    _int64 ans=1;
    for (; n; n>>=1, a=(a*a)%MOD) if (n&1) ans=(ans*a)%MOD;
    return ans;
}
_int64 polay(int n, int base)
{
    _int64 ans=0;
    for (int i=1; i*i<=n; i++)
        if (n%i==0)
        {
            ans=(ans+pow_mod(base, i)*phi[n/i])%MOD;
            if (i*i!=n)
                ans=(ans+pow_mod(base, n/i)*phi[i])%MOD;
        }
    ans=(ans*pow_mod(n, MOD-2))%MOD;
    return ans;
}
int ne[PRIME_SIZE], N[PRIME_SIZE], d[PRIME_SIZE];
void Pre_next(int *s, int len)
{
    int i, j=0;
    for (ne[0]=-1, i=2; i<=len; i++)
    {
        while (j>-1 && s[i-1]!=s[j]) j=ne[j];
        ne[i]=++j;
    }
}
int main()
{
    Euler_primes_phi_mu();
    int n, m, i;
    while (scanf("%d %d", &m, &n), ~m)
    {
        for (i=1; i<=n; i++) scanf("%d", &N[i]);
        sort(N+1, N+n+1); N[n+1]=N[1]+360000;
        for (i=1; i<=n; i++) d[i-1]=N[i+1]-N[i];
        Pre_next(d, n);
        int dif=n-ne[n];
        _int64 gcd;
        if (n%dif==0) gcd=GCD(n, dif);
        else gcd=n;
        _int64 ans=polay(n/gcd, pow_mod(m, gcd));
        printf("%I64d\n", ans);
    }
    return 0;
}
