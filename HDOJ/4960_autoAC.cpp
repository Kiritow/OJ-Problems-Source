#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define w(x) while(x)
#define inf 99999999
#define l 5005
#define s(a) scanf("%d",&a)
int dp[l],a[l],cost[l],lnum,rnum,lsum,rsum,len,i,j,ll[l],rr[l],ans,n;
int main()
{
    w((s(n),n))
    {
        up(i,1,n)
        s(a[i]);
        up(i,1,n)
        s(cost[i]);
        len=0;
        for(i=1,j=n; i<j; i++,j--)
        {
            lsum=a[i],rsum=a[j];
            lnum=rnum=1;
            w(lsum!=rsum)
            {
                if(i>=j)
                    break;
                if(lsum<rsum)
                {
                    lsum+=a[++i];
                    lnum++;
                }
                else
                {
                    rsum+=a[--j];
                    rnum++;
                }
            }
            if(lsum==rsum)
            {
                len++;
                ll[len]=lnum;
                rr[len]=rnum;
            }
        }
        up(i,1,len)
        {
            int t1=0,t2=0;
            dp[i]=inf;
            down(j,i,1)
            {
                t1+=ll[j];
                t2+=rr[j];
                dp[i]=min(dp[i],dp[j-1]+cost[t1]+cost[t2]);
            }
        }
        ans=cost[n];
        up(i,1,len)
        {
            n-=ll[i]+rr[i];
            ans=min(ans,dp[i]+cost[n]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
