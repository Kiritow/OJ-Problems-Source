#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
    __int64 n;
    scanf("%I64d",&n);
    if(n==2)
    {
        printf("1\n");
        continue;
    }
    if(n&1)
        printf("%I64d\n",(n/2)*(n/2+1));
    else
    {
        n/=2;
        if(n&1)
        printf("%I64d\n",(n-2)*(n+2));
        else
        printf("%I64d\n",(n-1)*(n+1));
    }
    }
    return 0;
}
