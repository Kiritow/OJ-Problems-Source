#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll __int64
#define L 20005
ll a[L],b[L],c[L],l,r,n;
ll solve(ll mid)
{
    ll k,sum = 0;
    int i;
    for(i = 0; i<n; i++)
    {
        k = min(mid,b[i]);
        if(k>=a[i])
            sum+=(k-a[i])/c[i]+1;
    }
    return sum;
}
int main()
{
    int i,j;
    while(~scanf("%d",&n))
    {
        for(i = 0; i<n; i++)
            scanf("%I64d%I64d%I64d",&a[i],&b[i],&c[i]);
        l = 0,r = 1LL<<31;
        ll mid;
        while(l<r)
        {
            mid = (l+r)/2;
            if(solve(mid)%2) r = mid;
            else l = mid+1;
        }
        if(l == 1LL<<31)
            printf("DC Qiang is unhappy.\n");
        else
        {
            while(solve(l)%2==0)l--;
            printf("%I64d %I64d\n",l,solve(l)-solve(l-1));
        }
    }
    return 0;
}
