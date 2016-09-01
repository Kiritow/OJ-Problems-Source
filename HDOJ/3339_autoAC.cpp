#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define INF 100000000
#define max 101
using namespace std;
int dp[10001];
int N,g[max][max];
int dis[max];
int pp[max];
int v[max];
void dijk()
{
    int i,j,mindis,mark;
    for(i=0;i<=N;i++)
    {
        dis[i] = INF;
        v[i] = 0;
    }
    dis[0] = 0;
    v[0] = 1;
    for(i=0;i<=N;i++)
    {
        mark = 0;
        mindis = INF;
        for(j=0;j<=N;j++)
        {
            if(!v[j] && dis[j] < mindis)
            {
                mindis = dis[j];
                mark = j;
            }
        }
        v[mark] = 1;
        for(j=0;j<=N;j++)
        {
            if(!v[j] && dis[j] > dis[mark] + g[mark][j])
            {
                dis[j] = dis[mark] + g[mark][j];
            }
        }
    }
}
int main()
{
    int M,a,b,c,i,j,t,sum,MAX,MIN,sumdis;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&N,&M);
        for(i=0;i<=N;i++)
        for(j=0;j<=N;j++)
        {
            if(i==j)g[i][j] = 0;
            else
            g[i][j] = INF;
        }
        while(M--)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(c<g[a][b])
            {
                g[a][b] = c;
                g[b][a] = c;
            }
        }
         for(sum=0,i=1;i<=N;i++)
        {    
            scanf("%d",&c);
            sum+=c;
            pp[i] = c;
        }
        dijk();
        memset(dp,0,sizeof(dp));
        for(sumdis=0,i=0;i<=N;i++)
        {
            if(dis[i]!=INF)
            sumdis += dis[i];
        }
        for(i=1;i<=N;i++)
        {
            for(j=sumdis;j>=dis[i];j--)
            {
                if(dp[j]<dp[j-dis[i]]+pp[i])
                dp[j] = dp[j-dis[i]]+pp[i];
            }
        } 
        for(i=0;i<=sumdis;i++)
        {
            if(dp[i] > sum/2)
            break;
        }
        if(i == sumdis+1)
        printf("impossible\n");
        else
        printf("%d\n",i);
    }
}
