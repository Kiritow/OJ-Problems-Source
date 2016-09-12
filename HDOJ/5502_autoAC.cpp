#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
double dp[1550];
double power[1550];
double ans[1550];
double pre[1550];
int main(){
    int T,n;
    double p,q;
    scanf("%d",&T);
    while(T--){
        scanf("%d%lf%lf",&n,&p,&q);
        power[0]=1;
        double pro0=q/p;
        double pro1=(p-q)/p;
        for(int i=1;i<=n+1;i++){
            power[i]=power[i-1]*pro0;
        }
        ans[0]=0;
        n++;
        for(int i=1;i<=n;i++){
            dp[0]=pre[0]=1;
            for(int j=1;j<=n;j++){
                double now=pre[j-1];
                if(j-1-i>=0) now-=pre[j-1-i]*power[i];
                dp[j]=now*pro1;
                pre[j]=pre[j-1]*pro0+dp[j];
            }
            ans[i]=dp[n];
        }
        double e=0;
        for(int i=n;i>=1;i--){
            e+=(ans[i]-ans[i-1])*i;
        }
        e/=pro1;
        printf("%.3lf\n",e);
    }
    return 0;
}
