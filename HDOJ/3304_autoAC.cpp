#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
const int mod=10000;
int main()
{
    int p,n,tt=0;
    while(scanf("%d%d",&p,&n)!=EOF)
    {
        if(p==0&&n==0)
            break;
        int ans=1;
        while(n)
        {
            ans*=(n%p+1);
            n/=p;
            if(ans>=mod)
                ans%=mod;
        }
        printf("Case %d: %04d\n",++tt,ans);
    }
    return 0;
}
