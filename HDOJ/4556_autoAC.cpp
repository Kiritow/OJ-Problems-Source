#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1000011;
int n;
long long ans[maxn],phi[maxn];
void Phi(int n)
{
    phi[1]=1;
    for(int i=2;i<=n;i++)
    if(!phi[i])
        for(int j=i;j<=n;j+=i)
        {
        if(!phi[j])
            phi[j]=j;
        phi[j]=phi[j]/i*(i-1);
        }
}
int main()
{
    Phi(maxn-1);
    ans[1]=2;
    ans[2]=3;
    for(int i=3;i<maxn;i++)
    ans[i]=ans[i-1]+phi[i];
    while(scanf("%d",&n)!=EOF)
    {
    long long s=(ans[n]-2)*2+3;
    printf("%I64d\n",s);
    }
    return 0;
}
