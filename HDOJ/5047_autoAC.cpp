#include <cstdio>
using namespace std ;
typedef __int64 ll ;
const ll mod=1000000 ;
int main()
{
    int T ;
    scanf("%d",&T) ;
    for(int cas=1 ;cas<=T ;cas++)
    {
        ll n ;
        scanf("%I64d",&n) ;
        ll t=8*n-7 ;
        ll lt=t/mod ;
        ll rt=t%mod ;
        lt*=n ;
        rt=rt*n+1 ;
        lt=lt+rt/mod ;
        rt%=mod ;
        printf("Case #%d: ",cas) ;
        if(lt)printf("%I64d%06I64d\n",lt,rt) ;
        else printf("%I64d\n",rt) ;
    }
    return 0 ;
}
