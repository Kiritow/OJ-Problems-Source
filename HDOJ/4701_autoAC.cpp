#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
long long s[1000500];
int main ()
{
    int n,a,b;
    while(scanf("%d%d%d",&n,&a,&b)!=EOF)
    {
        for(int i=1;i<=n;++i)
            scanf("%I64d",&s[i]);
        for(int i=n-1;i>=1;--i)
            s[i]+=s[i+1];
        long long pre_min=0,now_min;
        for(int i=n;i>=1;--i)
        {
            now_min=pre_min+s[i];
            pre_min=min(pre_min,max(-s[i],a+b-s[1]+1-now_min));
        }
        if(a>=now_min)
            printf("ALICE\n");
        else printf("BOB\n");
    }
    return 0;
}
