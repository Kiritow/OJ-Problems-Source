#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int a[30],b[30];
int sum1[30];
int sum2[30];
int dp[30][30][30][30];
int solve(int l1,int r1,int l2,int r2)
{
    if(dp[l1][r1][l2][r2] != -1)return dp[l1][r1][l2][r2];
    if(l1 > r1 && l2 > r2)
        return dp[l1][r1][l2][r2] = 0;
    int ans = 0;
    int sum = 0;
    if(l1 <= r1)
        sum += sum1[r1] - sum1[l1-1];
    if(l2 <= r2)
        sum += sum2[r2] - sum2[l2-1];
    if(l1 <= r1)
    {
        ans = max(ans,sum - solve(l1+1,r1,l2,r2));
        ans = max(ans,sum - solve(l1,r1-1,l2,r2));
    }
    if(l2 <= r2)
    {
        ans = max(ans,sum - solve(l1,r1,l2+1,r2));
        ans = max(ans,sum - solve(l1,r1,l2,r2-1));
    }
    return dp[l1][r1][l2][r2] = ans;
}
int main()
{
    int n;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        sum1[0] = sum2[0] = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i]);
            sum1[i] = sum1[i-1] + a[i];
        }
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&b[i]);
            sum2[i] = sum2[i-1] + b[i]; 
        }
        memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(1,n,1,n));
    }
    return 0;
}
