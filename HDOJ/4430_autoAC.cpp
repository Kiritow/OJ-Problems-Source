#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define ll __int64
ll n;
ll bin(ll s)
{
    ll l = 2,r = n,mid,i;
    while(l<=r)
    {
        mid = (l+r)/2;
        ll sum = 1,ans = 0;;
        for(i = 1; i<=s; i++)
        {
            if(n/sum<mid)
            {
                ans = n+1;
                break;
            }
            sum*=mid;
            ans+=sum;
            if(ans>n)
                break;
        }
        if(ans == n || ans == n-1) return mid;
        else if(ans<n-1) l = mid+1;
        else r = mid-1;
    }
    return -1;
}
int main()
{
    ll s,k,l,r,mid,i;
    while(~scanf("%I64d",&n))
    {
        l = 1,r = n-1;
        for(i = 2; i<=45; i++)
        {
            k = bin(i);
            if(k!=-1 && i*k<l*r)
            {
                l = i,r = k;
            }
        }
        printf("%I64d %I64d\n",l,r);
    }
    return 0;
}
