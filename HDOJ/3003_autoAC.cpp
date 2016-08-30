#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
#include<set>
using namespace std;
__int64 cal(__int64 n)
{
    __int64 t=1;
    __int64 ans=2;
    __int64 m=n+1;
    while(n!=1)
    {
        if(n&1)
        {
            t=t*ans;
            n--;
            t%=m;
        }
        else
        {
            ans*=ans;            
            n=n/2;
            ans%=m;
        }
    }
    return t*ans%m;
}
int main()
{
    __int64 n;
    while(scanf("%I64d",&n) && n)
    {
        if(n==1)
        {
            printf("0\n");
            continue;
        }
        __int64 ans;
        ans=cal(n-1);
        printf("%I64d\n",(ans+1)%n);
    }
    return 0;
}
