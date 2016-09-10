#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
#define ll __int64
#define up(i,x,y) for(i=x;i<=y;i++)
#define up2(i,x,y) for(i=x;y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define down2(i,x,y) for(i=x;y;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define s(a) scanf("%d",&a)
#define s64(a) scanf("%I64d",&a)
#define w(a) while(a)
int n,a[100005],i,has[100005];
int main()
{
    w(~s(n))
    {
        up(i,0,n)
        s(a[i]);
        printf("%I64d\n",(ll)n*n+n);
        mem(has,-1);
        down(i,n,0)
        {
            if(has[i]>=0) continue;
            int num=0,s=1,t=i;
            w(t)
            {
                int tem=((t&1)^1);
                num=num+s*tem;
                s*=2;
                t=t/2;
            }
            has[num]=i;
            has[i]=num;
        }
        printf("%d",has[a[0]]);
        up(i,1,n)
        printf(" %d",has[a[i]]);
        printf("\n");
    }
    return 0;
}
