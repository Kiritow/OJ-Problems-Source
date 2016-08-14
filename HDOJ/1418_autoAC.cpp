#include<iostream>
#include<cstdio>
int main()
{
    __int64 n,m,r;
    while(scanf("%I64d%I64d",&n,&r)&&(n||r))
        printf("%I64d\n",r+n-2);
    return 0;
}
