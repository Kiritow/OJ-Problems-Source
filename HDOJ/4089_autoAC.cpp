#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define eps 1e-10
#define N (1<<7)+5
#define inf 1<<20
#define zero(a) (fabs(a)<eps)
#define lson (step<<1)
#define rson (step<<1|1)
using namespace std;
double p1,p2,p3,p4,p21,p31,p41;
double dp[2005][2005],c[2005];
int n,m,k;
int main(){
    while(scanf("%d%d%d%lf%lf%lf%lf",&n,&m,&k,&p1,&p2,&p3,&p4)!=EOF){
        if(zero(p4)) {puts("0.00000");continue;}
        p21=p2/(1-p1);
        p31=p3/(1-p1);
        p41=p4/(1-p1);
        dp[1][1]=p4/(1-p1-p2);
        for(int i=2;i<=n;i++){
            for(int j=2;j<=(i<k?i:k);j++)
               c[j]=dp[i-1][j-1]*p31+p41;
            for(int j=k+1;j<=i;j++)
               c[j]=dp[i-1][j-1]*p31;
            double p=1,tmp=0;
            for(int j=i;j>1;j--){
                tmp+=p*c[j];
                p*=p21;
            }
            dp[i][i]=(tmp+p*p41)/(1-p*p21);
            dp[i][1]=p21*dp[i][i]+p41;
            for(int j=2;j<i;j++)
               dp[i][j]=p21*dp[i][j-1]+c[j];
        }
        printf("%.5f\n",dp[n][m]);
    }
    return 0;
}
