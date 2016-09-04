#include<stdio.h>
#include<algorithm>
#define N 200009
typedef long long LL;
using namespace std;
int n,m,a[N],b[N],c[N],L[N],R[N];
LL d[N],s1[N],s2[N],sum[N];
LL max(LL aa, LL bb)
{
    if(aa > bb)return aa;
    return bb;
}
void make()
{
    int i,j,k,l;
    for(i=1;i<=n;i++)
    {
        k = i-1;
        while(k > 0 && a[k] <= a[i])k = b[k];
        b[i] = k;
    }
    for(i=n;i>0;i--)
    {
        k = i+1;
        while(k <= n && a[k] <= a[i])k = c[k];
        c[i] = k;
    }
}
int main()
{
    int i,j,k,l,cas=0;
    while(scanf("%d %d",&n,&m) != EOF)
    {
        if(n == 0 && m == 0)break;
        sum[0] = 0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i] = sum[i-1] + a[i];
        }
        make();
        L[1] = a[1]; for(i=2;i<=n;i++) { L[i] = a[i]; if(L[i] < L[i-1])L[i] = L[i-1]; }
        R[n] = a[n]; for(i=n-1;i>0;i--) { R[i] = a[i]; if(R[i] < R[i+1])R[i] = R[i+1]; }
        s1[1] = 0;
        for(i=2;i<=n;i++)
        {
            s1[i] = s1[i-1] + max(L[i-1] - a[i], 0);
        }
        s2[n] = 0;
        for(i=n-1;i>0;i--)
        {
            s2[i] = s2[i+1] + max(R[i+1] - a[i], 0);
        }
        for(i=1;i<=n;i++)
        {
            d[i] = 0;
            k = b[i];
            if(k < 1)d[i] += s1[i];
            else
            {
                l = i-k-1; d[i] += (LL)l*a[i] - (sum[i-1]-sum[k]); 
            }
            k = c[i];
            if(k > n)d[i] += s2[i];
            else
            {
                l = k-i-1; d[i] += (LL)l*a[i] - (sum[k-1]-sum[i]);
            }
        }
        sort(d+1, d+1+n);
        printf("Case %d: %I64d\n",++cas,d[n-m+1]);
    }
    return 0;
}
