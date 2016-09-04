#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int dp[110][16000+50];

struct person
{
    int l,p,s;
}P[110];
int cmp(person p1,person p2)
{
    return p1.s<p2.s;
}

int Q[16000+50];
int main()
{
    int N,K;
    while(scanf("%d%d",&N,&K)!=EOF)
    {
        for(int i=1;i<=K;i++)
            scanf("%d%d%d",&P[i].l,&P[i].p,&P[i].s);
        sort(P+1,P+K+1,cmp);

        int front,rear;
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=1;i<=K;i++)
        {
            front=0;rear=1;
            Q[0]=max(P[i].s-P[i].l,0);
            for(int j=1;j<=N;j++)
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                if(j>=P[i].s+P[i].l)//这些木块涂不了
                    continue;
                while(front<rear&&Q[front]+P[i].l<j)//队中的k过小，出队
                    front++;
                if(j<P[i].s)//符合k的取值范围即可以考虑入队
                {
                    int temp=dp[i-1][j]-j*P[i].p;
                    while(front<rear&&dp[i-1][Q[rear-1]]-Q[rear-1]*P[i].p<temp)//更优的k出现，队尾出队
                        rear--;
                    Q[rear++]=j;
                    continue;//第i个人无法涂这些木块
                }
                dp[i][j]=max(dp[i][j],dp[i-1][Q[front]]+P[i].p*(j-Q[front]));
            }
        }
        printf("%d\n",dp[K][N]);
    }
    return 0;
}
