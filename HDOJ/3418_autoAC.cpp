#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef __int64 LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
LL a[105];
int judge(LL mid,LL n,LL m){
    LL sum = 0;
    for(int i = 0; i <n; ++i)
        if(a[i] >= mid) sum += mid;
        else sum += a[i];
    if(sum >= m * mid) return 1;
    return 0;
}
int main()
{   LL n,m,sum,minx;
    while(~scanf("%I64d%I64d",&n,&m)){
        sum = 0,minx = INF;
        for(int i = 0; i < n; ++i){
            scanf("%d",&a[i]);
            minx = min(minx,a[i]);
            sum += a[i];
        }
        LL L = minx,R = sum/m,mid,ans;
        while(L <= R){
            mid = (R + L) >> 1;
            if(judge(mid,n,m)){
                ans = mid;
                L = mid + 1;
            }else R = mid - 1;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
