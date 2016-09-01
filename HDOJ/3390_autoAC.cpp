#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define mod 100003
typedef long long LL;
LL a[106][3],b[106][3],c[106][3];
int main()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    c[0][0]=1;
    for (int i=1;i<=100;i++)
    {
        a[i][0]=(a[i-1][0]*90%mod+c[i-1][0]*44%mod+a[i-1][1]*80%mod+c[i-1][1]*41%mod)%mod;
        a[i][1]=(a[i-1][0]*10%mod+c[i-1][0]+a[i-1][1]*10%mod+c[i-1][1])%mod;
        a[i][2]=(a[i-1][1]*10%mod+c[i-1][1]*3%mod+a[i-1][2]*100%mod+c[i-1][2]*45%mod)%mod;
        b[i][0]=(b[i-1][0]*900%mod+a[i-1][0]*880+c[i-1][0]*284+b[i-1][1]*800%mod+
            a[i-1][1]*820%mod+c[i-1][1]*275%mod)%mod;
        b[i][1]=(b[i-1][0]*100%mod+a[i-1][0]*20%mod+c[i-1][0]+b[i-1][1]*100%mod
            +a[i-1][1]*20%mod+c[i-1][1])%mod;
        b[i][2]=(b[i-1][1]*100%mod+a[i-1][1]*60%mod+c[i-1][1]*9%mod+
            b[i-1][2]*1000%mod+a[i-1][2]*900%mod+c[i-1][2]*285%mod)%mod;
        c[i][0]=(c[i-1][0]*9%mod+c[i-1][1]*8%mod)%mod;
        c[i][1]=(c[i-1][0]+c[i-1][1])%mod;
        c[i][2]=(c[i-1][1]+c[i-1][2]*10%mod)%mod;
    }
    int test;
    scanf("%d",&test);
    for (int ii=1;ii<=test;ii++)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %I64d\n",ii,b[n][2]);
    }
    return 0;
}
