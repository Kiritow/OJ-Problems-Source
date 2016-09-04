#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
const int MAX = 1000000 + 1;
int prime[MAX];
bool isPrime[2 * MAX];
int getPrime(int*prime, bool*isPrime, int n, int m)
{
    int p,i,j;
    memset(isPrime, 1, m);        
    p=isPrime[0]=isPrime[1]=0;
    for(i=2;i<=n;i++)
        if(isPrime[i])
            for(prime[p++]=i,j=2*i;j<=m;j+=i)
                isPrime[j] = false;
    return p;
}
int resolve(int x, int *arr) 
{
    int len = 0;
    for(int i = 0; x != 1; i ++) 
    {
        if(isPrime[x])
        {
            arr[len ++] = x;
            break;
        }
        while(x % prime[i] == 0)
        {
            arr[len ++] = prime[i];
            x /= prime[i];
        }
    }
    return len;
}
int mod_pow(__int64 a, __int64 k, __int64 m) 
{
    static __int64 r;
    for(r=1; k; k>>=1, a=a*a%m)
        if(k&1)    r = r*a%m;
    return (int)r;
}
int oula_judge(int a, int n)
{
    if(a % n == 0)
        return 0;
    int t = (n - 1) / 2;
    int temp = mod_pow(a, t, n);
    if(temp == 1)
        return 1;
    else
        return -1;
}
int main(void)
{
    getPrime(prime, isPrime, 1000000, 2 * 1000000);
    int a, n;
    while(scanf("%d %d", &a, &n) == 2)
    {
        if(isPrime[n] == 1)
        {
            cout << oula_judge(a, n) << endl;
        }
        else
        {
            int ans = 1;
            int factor[100000];
            int len = resolve(n, factor);
            for(int i = 0; i < len; i++)
            {
                ans *= oula_judge(a, factor[i]);
            }
            cout << ans << endl;
        }
    }
    return 0;
}
