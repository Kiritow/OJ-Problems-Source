#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define w(x) while(x)
#define ll __int64
ll n,x,y,z,t,dp[1505][1505],ss,cas=1,i,j,k,r,ans;
int main()
{
    scanf("%I64d",&ss);
    w(ss--)
    {
        scanf("%I64d%I64d%I64d%I64d%I64d",&n,&x,&y,&z,&t);
        mem(dp,0);
        ans=n*t*x;
        up(i,1,n)
        up(j,0,i)
        {
            if(!j)
                dp[i][j]=dp[i-1][j]+t*(i-j-1)*y;
            else
                dp[i][j]=max(dp[i-1][j]+(j*z+t)*max(0LL,(i-1-j))*y,dp[i-1][j-1]+((j-1)*z+t)*(i-j)*y);
            ans=max(ans,dp[i][j]+(n-i)*(j*z+t)*(x+(i-j)*y));
        }
        printf("Case #%I64d: %I64d\n",cas++,ans);
    }
    return 0;
}
