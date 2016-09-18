#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10,M=1e6+10,inf=1e9+10,mod=1e9+7;
const ll INF=1e18+10;
bitset<90>dp[11];
int ans[60][60][60];
int a[100],n,m;
int q[5];
int check(int x,int y,int z)
{
    for(int i=0;i<=n;i++)dp[i].reset();
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        if(i!=x&&i!=y&&i!=z)
            for(int t=10;t>=1;t--)
                dp[t]|=dp[t-1]<<a[i];
    }
    if(dp[10][87]==1)
        return 1;
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(ans,0,sizeof(ans));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                for(int k=j;k<=n;k++)
                if(check(i,j,k))ans[i][j][k]=1;
        scanf("%d",&m);
        while(m--)
        {
            for(int i=0;i<3;i++)
                scanf("%d",&q[i]);
            sort(q,q+3);
            if(ans[q[0]][q[1]][q[2]])
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
