#include <iostream>
#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;
#define LL long long
#define Bool bitset<maxn>
const int maxn=60;
int a[maxn];
Bool to[maxn];
LL num[maxn];
LL ans;
bool gcd(int a,int b)
{
    return b==0?a!=1:gcd(b,a%b);
}
LL DFS(int n,Bool p)
{
    if(n==-1)
        return 1;
    LL res=DFS(n-1,p);
    if(p.test(n))
        return res;
    if((p|to[n])==p)
        return res*num[n];
    else
        return res+DFS(n-1,(p|to[n]))*(num[n]-1);
}
int main()
{
    int n;
    while(~scanf("%d",&n) && n)
    {
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        sort(a,a+n);
        int m=0;
        num[0]=2;
        for(int i=1;i<n;i++)
        {
            if(a[i]==a[m])
                num[m]++;
            else
            {
                a[++m]=a[i];
                num[m]=2;
            }
        }
        for(int i=0;i<=m;i++)
        {
            to[i].reset();
            for(int j=0;j<i;j++)
                if(gcd(a[j],a[i]))
                    to[i].set(j);
        }
        ans=0;
        Bool p;
        printf("%I64d\n",DFS(m,p));
    }
}
