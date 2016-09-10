#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;
#define mod 1000003
int n;
int a[1001];
long long ans[1001];
int sum;
long long c[1001][1001];
int num[33];
inline void init()
{
    memset(c,0,sizeof(c));
    c[0][0]=1;
    for(int i=1;i<=1000;i++) c[i][0]=1,c[i][i]=1;
    for(int i=2;i<=1000;i++)
        for(int j=1;j<i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
}
inline void chuli(int t)
{
    int val=t;
    int s=1;
    while(val)
    {
        if(val%2)
            num[s]++;
        val/=2;
        s++;
    }
}
int main()
{
    init();
    while(~scanf("%d",&n))
    {
        memset(ans,0,sizeof(ans));
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            chuli(a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=32;j++)
            {
                for(int k=1;k<=i;k+=2)
                    ans[i]+=(c[num[j]][k]*(c[n-num[j]][i-k])%mod)*((1*1LL)<<(j-1) %mod),ans[i]%=mod;
            }
        }
        for(int i=1;i<=n;i++)
        {
            printf("%I64d",ans[i]%mod);
            if(i==n)
                printf("\n");
            else
                printf(" ");
        }
    }
}
