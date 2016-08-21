#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#define maxn 5000
#define MAXN 2005
#define MAXM 20000005
#define INF  100000000000000
#define oo 1000000007
using namespace  std;
typedef long long LL;
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            LL n,x,y;
            LL min_n=INF;
            scanf("%I64d",&n);
            n=(n+4)/5;
            LL tem=(LL)sqrt(double(n));
            for(LL i=1; i<=tem; i++)
            {
                LL j=(n+(i-1))/i;
                LL xx=i*40+(i+1)*4;
                LL yy=j*8+(j+1)*2;
                if(xx*yy<min_n)
                {
                    x=xx;
                    y=yy;
                    min_n=xx*yy;
                }
                else if(xx*yy==min_n)
                {
                    if(abs(x-y)>abs(xx-yy))
                    {
                        x=xx;
                        y=yy;
                    }
                }
            }
            printf("%I64d X %I64d = %I64d\n",max(x,y),min(x,y),min_n);
        }
    }
    return 0;
}
