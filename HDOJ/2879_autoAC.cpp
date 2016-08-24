#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
typedef long long LL;
const int N = 10000005;
const int M = 1000005;
bool prime[N];
int p[N];
int k;
void isprime()
{
    k = 0;
    memset(prime,true,sizeof(prime));
    for(int i=2;i<N;i++)
    {
        if(prime[i])
        {
            p[k++] = i;
            for(int j=i+i;j<N;j+=i)
                prime[j] = false;
        }
    }
}
LL quick_mod(LL a,LL b,LL m)
{
    LL ans = 1;
    a %= m;
    while(b)
    {
        if(b&1)
        {
            ans = ans * a % m;
            b--;
        }
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}
int main()
{
    int n,m,t;
    isprime();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        LL cnt = 0;
        for(int i=0;i < k;i++)
        {
            if(p[i] > n) break;
            cnt += n / p[i];
        }
        LL ans = quick_mod(2,cnt,m);
        printf("%I64d\n",ans);
    }
    return 0;
}
