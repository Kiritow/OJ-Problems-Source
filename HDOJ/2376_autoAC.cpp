#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define N 10010
struct note
{
    int v,next,value;
}edge[N*2+10];
int head[N];
double dp[N];
int sum[N];
int n;
int kk;
int ss;
void add(int fa,int son,int value)
{
    edge[kk].v = son;
    edge[kk].value = value;
    edge[kk].next = head[fa];
    head[fa] = kk++;
}
void dfs(int root,int fa)
{
    sum[root] = 1;
    for(int i = head[root];i != -1;i = edge[i].next)
    {
        int son = edge[i].v;
        if(son == fa) continue;
        dfs(son,root);
        sum[root] += sum[son];
        ss += sum[son]*(n-sum[son]);
        dp[root] += dp[son] + (double)sum[son]*(n-sum[son])*edge[i].value;
    }
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        ss = 0;
        memset(head,-1,sizeof(head));
        memset(dp,0,sizeof(dp));
        kk = 1;
        scanf("%d",&n);
        int a,b,v;
        for(int i = 1;i < n;i++)
        {
            scanf("%d%d%d",&a,&b,&v);
            add(a,b,v);
            add(b,a,v);
        }
        dfs(0,-1);
        ss = n*(n-1) / 2;
        printf("%llf\n",(double)dp[0] / ss);
    }
    return 0;
}
