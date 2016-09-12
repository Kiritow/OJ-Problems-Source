#include<iostream>
#include<string>
#include<stdio.h>
#include<memory.h>
using namespace std;
#define inf 0xfffffff
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

int dp[2][101];
int n,c;
int q[101];
int head,tail,cur;

int main()
{
    int i,j,x,nowf;
    //freopen("D:\\in.txt","r",stdin);
    while(scanf("%d%d",&n,&c)==2)
    {
        scanf("%d",&x);
        cur=0;
        for(i=0;i<x;i++)
            dp[cur][i]=inf;
        for(i=x;i<=100;i++)
            dp[cur][i]=(x-i)*(x-i);
        for(i=1;i<n;i++)
        {
            scanf("%d",&x);
            cur=1-cur;
            //比前一个人高
            head=tail=0;
            for(j=0;j<=100;j++) //当身高为j时候，队列里便已经保存了0~j-1的信息，注意，是第i-1个人的信息
            {
                nowf=dp[1-cur][j]-j*c;
                while(head<tail && q[tail-1]>nowf)
                    tail--;
                q[tail++]=nowf;
                if(j<x)
                    dp[cur][j]=inf;
                else
                    dp[cur][j]=q[head]+j*c+(x-j)*(x-j);
            }
            //比前一个人矮
            head=tail=0;
            for(j=100;j>=0;j--) //当身高为j时候，队列里便已经保存了100~j+1的信息，正写反写是有技巧的
            {
                nowf=dp[1-cur][j]+j*c;
                while(head<tail && q[tail-1]>nowf)
                    tail--;
                q[tail++]=nowf;
                if(j>=x)
                    dp[cur][j]=min(dp[cur][j],q[head]-j*c+(x-j)*(x-j));
            }
        }
        int ans=inf;
        for(i=0;i<=100;i++)
            ans=min(ans,dp[cur][i]);
        printf("%d\n",ans);
    }
    return 0;
}
