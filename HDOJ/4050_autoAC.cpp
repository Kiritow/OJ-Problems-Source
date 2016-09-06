#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
#define maxn 200005
#define eps 1e-8
#define inf 2000000000
#define LL long long
#define zero(a) fabs(a)<eps
#define MOD 19901014
#define N 1000005
#define pi acos(-1.0)
using namespace std;
double dp[4004][4];
double p[4004][4];
int main(){
    int t,a,b,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&a,&b);
        for(int i=1;i<=n;i++)
            for(int j=0;j<4;j++)
                scanf("%lf",&p[i][j]);
        for(int i=n+1;i<=n+a;i++)
            for(int j=0;j<4;j++)
                p[i][j]=(j==3);
        memset(dp,0,sizeof(dp));
        dp[0][3]=1;
        for(int i=0;i<=n;i++){
            double p1=1,p2=1,p3=1;
            for(int j=a;j<=b;j++){
                dp[i+j][2]+=dp[i][1]*p1*p[i+j][2];
                dp[i+j][3]+=dp[i][1]*p1*p[i+j][3];
                p1*=(p[i+j][0]+p[i+j][1]);
                dp[i+j][1]+=dp[i][2]*p2*p[i+j][1];
                dp[i+j][3]+=dp[i][2]*p2*p[i+j][3];
                p2*=(p[i+j][0]+p[i+j][2]);
                dp[i+j][1]+=dp[i][3]*p3*p[i+j][1];
                dp[i+j][2]+=dp[i][3]*p3*p[i+j][2];
                dp[i+j][3]+=dp[i][3]*p3*p[i+j][3];
                p3*=p[i+j][0];
            }
        }
        double ans=0;
        for(int i=1;i<=n+a;i++)
            for(int j=1;j<4;j++)
                ans+=dp[i][j];
        printf("%.8f\n",ans);
    }
    return 0;
}
