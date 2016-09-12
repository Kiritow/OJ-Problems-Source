#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int m=1000000007;
int pow_mod(__int64 a,__int64 n,int m)
{
    if(n==0) return 1;
    __int64 x=pow_mod(a,n/2,m);
    __int64 ans=(x%m)*(x%m);
    ans%=m;
    if(n%2==1) ans=ans*a%m;
    return (int)ans;
}
int main()
{
    int _;
    __int64 n;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%I64d",&n);
        int ans=pow_mod(2,n-1,m);
        printf("%d\n",(ans-1)%m);
    }
    return 0;
}
