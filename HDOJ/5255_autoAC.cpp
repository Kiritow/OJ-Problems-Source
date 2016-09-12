#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
#include<vector>
#include<cmath>
#include<string>
#define N 2000010
#define M 1000
using namespace std;
double n;
long long a,b,z,pp,qq,ans[N],P,p,q,o,k,tot,i,j,l;
long long gcd(long long a,long long b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
int check(long long p,long long q)
{
    if (p==0) return 0;
    if (p>=P) return 0;
    long long a,b,c=1,pp;
    a=p%10;
    pp=p;
    while (pp)
    {
        b=pp%10;
        pp=pp/10;
        c=c*10;
    }
    c=c/10;
    p=p-a+b-b*c+a*c;
    if (p==q) return 1;return 0;
}
int main()
{
    int test,ii;
    P=1000000;
    P=P*10000;
    scanf("%d",&test);
    for (ii=1;ii<=test;ii++)
    {
    tot=0;
    scanf("%lf",&n);
    p=(n+0.0000005)*1000000;
    q=p/gcd(p,1000000);
    p=1000000/gcd(p,1000000);
    o=abs(p-q);
    b=10;a=0;
    for (k=0;k<=8;k++)
    {
    for (i=0;i<=9;i++)
    for (j=0;j<=9;j++)
    {
        z=b*i+a*10+j;
        if (z%o==0) 
        {
            z=z/o;
            pp=p*z;qq=q*z;
            if (check(pp,qq))
            {
                tot++;
                ans[tot]=pp;
            }
        }
    }
    a=a*10+9;
    b=b*10;
    }
    sort(ans+1,ans+1+tot);
    j=0;ans[0]=-1;
    for (i=1;i<=tot;i++)
    if (ans[i]!=ans[i-1])
    {
        j++;ans[j]=ans[i];
    }
    tot=j;
    printf("Case #%d:\n",ii);
    printf("%I64d\n",tot);
    for (i=1;i<=tot-1;i++)
    printf("%I64d ",ans[i]);
    if (tot)
    printf("%I64d\n",ans[tot]);
    }
}
