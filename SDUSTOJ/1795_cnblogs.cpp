/* ***********************************************
Author        :devil
Created Time  :2016/4/26 16:10:39
************************************************ */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
using namespace std;
typedef long long LL;
const int N=2e6+7;
int a[N],b[N];
long long sum[N];
int main()
{
    //freopen("in.txt","r",stdin);
    int n,x;
    while(~scanf("%d",&n))
    {
        int ma=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(sum,0,sizeof(sum));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            ma=max(ma,x);
            a[x]++;
        }
        for(int i=1;i<=ma*2+1;i++)
        {
            sum[i]=sum[i-1]+a[i]*i;
            b[i]=b[i-1]+a[i];
        }
        LL ans=1e12+10;
        for(int i=1;i<=ma;i++)
        {
            LL now=sum[i-1];
            for(int j=1;i*j<=ma;j++)
                now=now+(b[i*(j+1)-1]-b[i*j-1])*j+sum[i*(j+1)-1]-sum[i*j]-(b[i*(j+1)-1]-b[i*j])*j*i;
            ans=min(ans,now);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
