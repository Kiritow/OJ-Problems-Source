#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <tr1/unordered_map>
#define clr(x, y) memset(x, y, sizeof x)
using namespace std;
typedef long long LL;
const double eps=1e-8;
const int maxn=1000100;
const int mod=258280327;
int valid[maxn];
LL G[maxn],T[maxn],F[maxn],S[maxn];
void init()
{
    for(int i=0;i<maxn;i++)
    {
        G[i]=valid[i]=1;
        T[i]=0;
    }
    G[0]=0;
    for(int i=2;i<maxn;i++)
    {
        if(valid[i])
        {
            for(int j=i;j<maxn;j+=i)
            {
                G[j]=G[j]*2%mod;
                valid[j]=0;
            }
        }
    }
    for(int i=1;i<maxn;i++)
    {
        for(int j=i;j<maxn;j+=i)
        {
            T[j]=(T[j]+G[j/i-1])%mod;
        }
    }
    F[1]=S[1]=1;
    for(int i=2;i<maxn;i++)
    {
        F[i]=(((F[i-1]+2*i-1)%mod-T[i-1])%mod+mod)%mod;
        S[i]=(S[i-1]+F[i])%mod;
    }
}
int main()
{
    init();
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%I64d\n",S[n]);
    }
    return 0;
}
