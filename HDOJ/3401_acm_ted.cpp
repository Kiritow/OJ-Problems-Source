#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 2005
#define inf 0xfffff
#define max(a,b) ((a)>(b)?(a):(b))
int T,MaxP,W;
int APi[MAX],BPi[MAX],ASi[MAX],BSi[MAX];
int dp[MAX][MAX];//dp[i][j]第i天持有j股的最大值
//dp[i][j]=max{dp[i-1][j],max{dp[r][k]-APi[i]*(j-k)}(0<r<i-w,k<j),max{dp[r][k]+BPi[i]*(k-j)}(0<r<i-w,k>j)}
struct node
{
    int x;//存dp[i-w-1][k]+APi[i]*k或dp[i-w-1][k]+BPi[i]*k
    int p;//当前持股数
} q[2005],temp;
int front,back;
int main()
{
    int cas;
    scanf("%d",&cas);
    for(; cas--;)
    {
        scanf("%d%d%d",&T,&MaxP,&W);
        for(int i=1; i<=T; ++i)
            scanf("%d%d%d%d",APi+i,BPi+i,ASi+i,BSi+i);
        for(int i=0; i<=T; ++i)
            for(int j=0; j<=MaxP; ++j)
                dp[i][j]=-inf;
        for(int i=1; i<=W+1; ++i)
            for(int j=0; j<=ASi[i]; ++j)
                dp[i][j]=(-APi[i]*j);
        for(int i=2; i<=T; ++i)
        {
            for(int j=0; j<=MaxP; ++j)
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(i<=W+1) continue;
            //买入
            front=back=1;
            for(int j=0; j<=MaxP; ++j)
            {
                temp.p=j;
                temp.x=dp[i-W-1][j]+APi[i]*j;
                for(;front<back&&q[back-1].x<temp.x;--back);
                q[back++]=temp;
                for(;front<back&&q[front].p+ASi[i]<j;++front);
                dp[i][j]=max(dp[i][j],q[front].x-APi[i]*j);
            }
            //卖出
            front=back=1;
            for(int j=MaxP; j>=0; --j)
            {
                temp.p=j;
                temp.x=dp[i-W-1][j]+BPi[i]*j;
                for(;front<back&&q[back-1].x<temp.x;--back);
                q[back++]=temp;
                for(;front<back&&q[front].p-BSi[i]>j;++front);
                dp[i][j]=max(dp[i][j],q[front].x-BPi[i]*j);
            }
        }
        int ans=0;
        for(int i=0;i<=MaxP;++i)
            ans=max(ans,dp[T][i]);
        printf("%d\n",ans);
    }
    return 0;
}
