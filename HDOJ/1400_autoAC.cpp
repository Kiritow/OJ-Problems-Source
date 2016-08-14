#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n,m;
long long add;
long long dp[2][1<<12];
void dfs(int i,int s,int cur)
{
    if(cur==m) {dp[i][s]+=add;return;}
    dfs(i,s,cur+1);
    if(cur<m-1&&!(s&1<<cur)&&!(s&1<<(cur+1)))
        dfs(i,s|1<<cur|1<<(cur+1),cur+2);
}
int main()
{
    while(scanf("%d%d",&n,&m),n+m)
    {
        if(n*m%2) {printf("0\n");continue;}
        int rt=(1<<m)-1;
        add=1;
        memset(dp,0,sizeof(dp));
        dfs(0,0,0);
        for(int i=1;i<n;i++)
        {
            memset(dp[i%2],0,sizeof(dp[1]));
            for(int j=0;j<=rt;j++) if(dp[(i-1)%2][j])
            {
                add=dp[(i-1)%2][j];
                dfs(i%2,~j&rt,0);
            }
        }
        printf("%I64d\n",dp[(n-1)%2][rt]);
    }
    return 0;
}
