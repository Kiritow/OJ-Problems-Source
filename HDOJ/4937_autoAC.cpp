#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL __int64
const int maxn=1e5+10;
int main()
{
    int T;
    scanf("%d",&T);
    int tt=0;
    while(T--)
    {
        LL n,t,ans=0;
        LL i,j,k;
        LL a,b,c,d,x;
        scanf("%I64d",&n);
        if(n>=3&&n<=6){printf("Case #%d: -1\n",++tt);continue;}
        for(i=3;i<=6;i++)
        {
            for(j=3;j<=6;j++)
            {
                if((n-i)%j==0&&(n-i)/j>max(i,j))
                {
                    //printf("   %I64d+%I64d*%I64d\n",i,j,(n-i)/j);
                    ans++;
                }
            }
        }
        for(i=3;i<=6;i++)
        {
            for(j=3;j<=6;j++)
            {
                for(k=3;k<=6;k++)
                {
                    a=i;b=j;c=k-n;
                    d=(LL)sqrt(b*b-a*c*4+0.5);
                    if(d*d!=b*b-a*c*4)continue;
                    if((d-b)%(a*2))continue;
                    x=(d-b)/(a*2);
                    if(x>max(max(i,j),k))
                    {
                          ans++;
                    }
                }
            }
        }
        for(i=2;i*i*i<=n;i++)
        {
            t=n;
            while(t)
            {
                if(t%i<3||t%i>6)break;
                t=t/i;
            }
            if(!t)
            {
                ans++;
            }
        }
        printf("Case #%d: %I64d\n",++tt,ans);
    }
    return 0;
}
