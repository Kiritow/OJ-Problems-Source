#include <map>
#include <stack>
#include <queue>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define N 4005
#define M
#define E
#define INF 0x3f3f3f3f
#define eps 1e-8
#define LL long long
#define D(a) ((a)*(a))
using namespace std;
int dp[N],n,a[N],b[N];
void re(void)
{
    scanf("%d",&n);
}
void run(void)
{
    memset(dp,-1,sizeof(dp));
    dp[2000]=0;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        int v;
        scanf("%d",&v);
        if(v==0)flag++;
        memset(a,-1,sizeof(a));
        memset(b,-1,sizeof(b));
        for(int i=0;i<=4000;i++)
            if(~dp[i])
                a[i-v]=max(dp[i-v],dp[i]+v),
                b[i+v]=max(dp[i+v],dp[i]+v);
        for(int i=0;i<=4000;i++)
            dp[i]=max(dp[i],max(a[i],b[i]));
    }
    if(dp[2000]==0&&flag<1)printf("-1\n");
    else printf("%d\n",dp[2000]/2);
}
int main()
{
    int ncase;
    scanf("%d",&ncase);
    for(int i=1;i<=ncase;i++)
    {
        re();
        printf("Case %d: ",i);
        run();
    }
    return 0;
}
