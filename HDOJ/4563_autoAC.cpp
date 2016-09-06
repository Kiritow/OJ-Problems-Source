#include <algorithm>
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>
using namespace std;
#define N  100010
#define E  100010
#define ll long long
const int INF   =0x3fffffff;
const int PRIME =999983;
const int MOD   =1000000007;
const int MULTI =1000000007;
const double EPS=1e-8;
#define CUBE(x) ((x)*(x)*(x))
#define SQ(x)     ((x)*(x))
#define ALL(x)     x.begin(),x.end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define maxAry(a,n) max_element(a,a+(n))
#define minAry(a,n) min_element(a,a+(n))
inline bool isodd(int x){return x&1;}
inline bool isodd(ll x) {return x&1;}
double dp[110];
int vx[110],vy[110];
int n,L;
double gao(int x)
{
    fill(dp,dp+L+1,-1);
    dp[0]=0;
    for(int i=0;i<n;i++){
        if(i==x) continue;
        for(int j=L;j>=0;j--){
            for(int k=0;k<=100;k++){
                if(j-vx[i]*k<0 || dp[j-vx[i]*k]==-1) continue;
                if(dp[j]==-1) dp[j]=dp[j-vx[i]*k]+vy[i]*k-0.5*9.8*SQ(k);
                else dp[j]=max(dp[j],dp[j-vx[i]*k]+vy[i]*k-0.5*9.8*SQ(k));
            }
        }
    }
    double ans=-INF;
    for(int i=0;i<=L;i++){
        if(dp[i]==-1) continue;
        double t=1.0*(L-i)/vx[x];
        ans=max(ans,dp[i]+vy[x]*t-0.5*9.8*SQ(t));
    }
    return ans;
}
int main()
{
    int re,Case=1;
    double ans;
    scanf("%d",&re);
    while(re--){
        scanf("%d%d",&n,&L);
        for(int i=0;i<n;i++)
            scanf("%d%d",&vx[i],&vy[i]);
        ans=-INF;
        for(int i=0;i<n;i++)
            ans=max(ans,gao(i));
        printf("Case %d: %.3lf\n",Case++,ans);
    }
    return 0;
}
