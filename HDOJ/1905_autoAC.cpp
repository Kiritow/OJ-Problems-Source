#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
bool prime(__int64 a)
{
    __int64 i;
    for(i=2;i*i<=a;i++)
    {
        if(a%i == 0)return false;
    }
    return true;
}
bool q_pow(__int64 a,__int64 b)
{
    __int64 res=1,mod=b,carry=a;
    while(b)
    {
        if(b%2)
        {
            res=res*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    if(res == carry)return true;
    else return false;
}
int main()
{
    __int64 p,a;
    while(~scanf("%I64d %I64d",&p,&a),p+a)
    {
        if(!prime(p) && q_pow(a,p))puts("yes");
        else puts("no");
    }
    return 0;
}
