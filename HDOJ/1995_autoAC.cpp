#include <stdio.h>
int main()
{
    int t,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        printf("%I64d\n",1LL<<n-k);
    }
    return 0;
}
