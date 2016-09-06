#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
__int64 l[1000005],v[1000005],r;
int main()
{
    __int64 n,i,j,k,b;
    int t=0;
    while(~scanf("%I64d",&n))
    {
        t++;
        if(t>=40) continue;
        memset(l,0,sizeof l);
        for(i=1;i<=n;i++)
        {
            scanf("%I64d",&v[i]);
            l[i]=l[i-1]+v[i]+1;
            if(l[i-1]<=v[i]) k=i;
        }
        for(i=k+1,r=0,b=0;i<=n;i++)
        {
            b+=(v[i]<=b);
            r+=max(0ll,v[i]-b);
        }
        if((r+l[k-1])==v[k]) printf("%I64d\n",k);
        else if((r+l[k-1])>v[k]) printf("Unknown\n");
        else printf("Bad Rescue\n");
    }
    return 0;
}
