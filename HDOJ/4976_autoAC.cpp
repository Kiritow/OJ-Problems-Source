#include <iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define LL long long
#define lcm(a,b) (a*b/gcd(a,b))
#define N 1500001
int a[1100];
int b[1100];
int c[1100];
int dp[1100];
int main()
{
    int T;
    int cas=0;
    cin>>T;
    int n;
    while(T--)
    {
        cas++;
        scanf("%d",&n);
        int m=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            m=max(a[i],m);
        }
        sort(a+1,a+n+1);
        memset(c,0,sizeof(c));
        for(int i=1; i<=n; i++)
        {
            int j=a[i];
            while(c[j]&&j>0)j--;
            if(j!=0)b[j]=a[i]-j;
            c[j]=1;
        }
        memset(dp,0,sizeof(dp));
        int maxx=-1;
        for(int i=1; i<=m; i++)
        {
            for(int j=i;j>=1;j--)dp[j]=dp[j-1];
            for(int j=0;j<=i;j++)
            {
                if(j>b[i]&&c[i])dp[j-b[i]-1]=max(dp[j-b[i]-1],dp[j]+1);
            }
        }
        for(int j=0;j<=m;j++)maxx=max(maxx,dp[j]);
        printf("Case #%d: %d\n",cas,maxx);
    }
    return 0;
}
