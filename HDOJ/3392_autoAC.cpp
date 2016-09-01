#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
const int maxn=11000;
using namespace std;
double a[maxn],b[maxn];
double dp[2][maxn];
int main()
{
 int n,m;
 while(cin>>n>>m)
 {
        if(n==0&&m==0)break;
        for(int i=1;i<=n;i++)scanf("%lf",&a[i]);
        for(int i=1;i<=m;i++)scanf("%lf",&b[i]);
        double *A=a,*B=b;
        if(n>m){swap(n,m);swap(A,B);}
        sort(A+1,A+1+n);
        sort(B+1,B+1+m);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
         for(int j=i;j<=i+m-n;j++)
         {
          if(i==j)
          {
              dp[i&1][j]=dp[(i-1)&1][j-1]+fabs(A[i]-B[j]);
          }
          else
          {
              dp[i&1][j]=min(dp[(i-1)&1][j-1]+fabs(A[i]-B[j]),dp[i&1][j-1]);
          }
         }
       printf("%.6lf\n",dp[n&1][m]);
 }
 return 0;
}
