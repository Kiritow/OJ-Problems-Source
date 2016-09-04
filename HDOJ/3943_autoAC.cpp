#include"cstdlib"
#include"cstdio"
#include"cstring"
#include"cmath"
#include"queue"
#include"algorithm"
#include"iostream"
using namespace std;
__int64 dp[22][22][22];  
int num[22];
__int64 dfs(int site,int a,int b,int f,int x,int y)
{
    if(site==0)
    {
        if(a==x&&b==y) return 1;
        return 0;
    }
    if(!f&&dp[site][a][b]!=-1) return dp[site][a][b];
    int len=f?num[site]:9;
    __int64 ans=0;
    for(int i=0;i<=len;i++)
    {
        if(i==4) ans+=dfs(site-1,a+1,b,f&&i==len,x,y);
        else if(i==7) ans+=dfs(site-1,a,b+1,f&&i==len,x,y);
        else ans+=dfs(site-1,a,b,f&&i==len,x,y);
    }
    if(!f) dp[site][a][b]=ans;
    return ans;
}
__int64 solve(__int64 a,int x,int y)
{
    int cnt=0;
    while(a)
    {
        num[++cnt]=a%10;
        a/=10;
    }
    return dfs(cnt,0,0,1,x,y);
}
int main()
{
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        __int64 p,q;
        int x,y;
        scanf("%I64d%I64d%d%d",&p,&q,&x,&y);
        memset(dp,-1,sizeof(dp));
        int n;
        scanf("%d",&n);
        printf("Case #%d:\n",cas++);
        while(n--)
        {
            __int64 k,s;
            __int64 ans=-1;
            s=solve(p,x,y);
            scanf("%I64d",&k);
            s+=k;
            __int64 l=p+1,r=q;
            while(l<=r)          
            {
                __int64 mid=(l+r)/2;
                if(solve(mid,x,y)>=s)
                {
                    ans=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            if(ans!=-1) printf("%I64d\n",ans);
            else puts("Nya!");
        }
    }
    return 0;
}
