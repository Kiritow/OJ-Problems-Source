#include <cstdio>
#define LL __int64
int main()
{
    LL x,k;
    while(scanf("%I64d",&x)&&x){
        k=1;
        while(k<x)k=k*10+1;
        k/=10;
        while(x%k!=0)k/=10;
        printf("%I64d\n",x/k);
    }
    return 0;
}
