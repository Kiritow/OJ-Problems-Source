#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
#define N 10000000
#define M 3000
int a[N],dp[M][M],s[M],num[M];
int n,m;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int tot=0;
        int x=1;
        a[n]=-1;
        for(int i=0;i<n;i++)
        if(a[i]!=a[i+1]){
            num[tot]=a[i];
            s[tot++]=x;
            x=1;
        }
        else x++;
        int ans=0;
        for(int i=0;i<tot;i++)
        {
            dp[i][i]=s[i];
            int k=i;
            int ma=0;
            ans=max(dp[i][i],ans);
            for(int j=i+1;j<tot;j++)
            {
                while((num[j]-num[i])>=(num[i]-num[k])&&k>=0)
                {
                    ma=max(ma,dp[k][i]);
                    k--;
                }
                dp[i][j]=ma+1;
                ans=max(ans,dp[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
