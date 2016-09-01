#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1100;
struct route{
    double p,q;
    friend  bool operator < (route a,route b){
        return a.p/a.q>b.p/b.q;
    }
}r[maxn];
int n,m;
double dp[maxn][20];
void input(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lf%lf",&r[i].p,&r[i].q);
    }
    sort(r,r+n);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=0;
        }
    }
}
double solve(){
    double ans=0;
    dp[0][m]=1;
    for(int i=0;i<n;i++){
        for(int j=m;j>=0;j--){
            ans+=dp[i][j]*r[i].p;
            if(j-1>=0) dp[i+1][j-1]+=dp[i][j]*r[i].q;
            dp[i+1][j]+=dp[i][j]*(1.0-r[i].p-r[i].q);
        }
    }
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        input();
        printf("Case %d: %.5lf\n",i,solve());
    }
    return 0;
}
