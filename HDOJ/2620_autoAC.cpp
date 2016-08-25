#include <cstdio>
using namespace std;
typedef long long LL;
int main()
{
    LL n,k;
    while(~scanf("%I64d%I64d",&n,&k)){
        LL ans=n*k;
        if(n>k) n=k;
        for(LL i=1;i<=n;){
            LL d=k/i;
            LL j=k/d;
            if(j>n) j=n;
            ans-=d*(i+j)*(j-i+1)/2;
            i=j+1;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
