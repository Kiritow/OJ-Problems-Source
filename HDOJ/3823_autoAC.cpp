#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 21000000
bool isprime[maxn];
long long prime[maxn],nprime;
void getprime()
{
    memset(isprime,1,sizeof(isprime));
    nprime=0;
    long long i,j;
    for(i=2; i<maxn; i++)
        if(isprime[i])
        {
            prime[nprime++]=i;
            for(j=i*i; j<maxn; j+=i)
                isprime[j]=0;
        }
}
bool isd[150];
int main()
{
    getprime();
    int t,ca=0;
    long long a,b;
    for(int i=1; i<nprime; i++)
        if(prime[i]-prime[i-1]<150)
            isd[prime[i]-prime[i-1]]=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d",&a,&b);
        if(a>b)
            swap(a,b);
        long long ans=-1,d=b-a;
        printf("Case %d: ",++ca);
        if(!isd[d]||a==b)
        {
            puts("-1");
            continue;
        }
        for(int i=1; i<nprime; i++)
            if(prime[i]-prime[i-1]==d&&a<=prime[i-1])
            {
                ans=prime[i-1]-a;
                break;
            }
        printf("%I64d\n",ans);
    }
    return 0;
}
