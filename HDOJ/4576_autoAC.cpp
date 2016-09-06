#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=220;
int n,m,l,r;
double dp[2][N];
int main(){
    while(~scanf("%d%d%d%d",&n,&m,&l,&r)){
        if(n==0 && m==0 && l==0 && r==0)
            break;
        for(int i=0;i<=n;i++)
            dp[0][i]=0;
        dp[0][0]=1;
        int x,cur=0;
        while(m--){
            scanf("%d",&x);
            for(int i=0;i<n;i++)
                dp[cur^1][i]=0;
            for(int i=0;i<n;i++){
                if(dp[cur][i]==0)
                    continue;
                dp[cur^1][((i-x)%n+n)%n]+=0.5*dp[cur][i];
                dp[cur^1][(i+x)%n]+=0.5*dp[cur][i];
            }
            cur^=1;
        }
        double ans=0;
        for(int i=l-1;i<r;i++)  
            ans+=dp[cur][i];
        printf("%.4lf\n",ans);
    }
    return 0;
}
