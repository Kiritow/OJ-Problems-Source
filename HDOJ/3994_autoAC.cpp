#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MaxN 200
#define eps 1e-8
double dp[MaxN+5][MaxN+5];
double tmp[MaxN+5][MaxN+5];
int n;
int c;
int m;
int lst[MaxN+5];
void floyd(bool flag){
    int i,j,k;
    if (flag){
        for (k=0;k<n;k++){
            for (i=0;i<n;i++){
                for (j=0;j<n;j++){
                    if ((i==j) || (j==k) || (i==k)) continue;
                    if (dp[i][j]<dp[i][k]*dp[k][j]){
                        dp[i][j]=dp[i][k]*dp[k][j];
                    }
                }
            }
        }
        return;
    }
    for (k=0;k<n;k++){
        for (i=0;i<n;i++){
            for (j=0;j<n;j++){
                if ((i==j) || (j==k) || (i==k)) continue;
                if (dp[i][k]>=0 && dp[k][j]>=0 && (dp[i][j]<0 || dp[i][j]>dp[i][k]+dp[k][j])){
                    dp[i][j]=dp[i][k]+dp[k][j];
                }
            }
        }
    }
}
bool iszero(double a)
{
        return a<eps;
}
void init(){
    int i,j;
    scanf("%d",&n);    
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            scanf("%lf",&dp[i][j]);
            dp[i][j]=dp[i][j]/100.0;
        }
    }
    floyd(1);
    scanf("%d",&m);
    for (i=0;i<m;i++){
        scanf("%d",&lst[i]);
    }
    for (i=0;i<m;i++){
        if (lst[i]==1) break;
    }
    if (i==m) lst[m++]=1;
    for (i=0;i<m;i++){
        if (lst[i]==2) break;
    }
    if (i==m) lst[m++]=2;
    sort(lst,lst+m);
    for (i=0;i<m;i++){
        for (j=i+1;j<m;j++){
            tmp[i][j]=dp[lst[i]-1][lst[j]-1];
            tmp[j][i]=dp[lst[j]-1][lst[i]-1];
        }
    }
    for (i=0;i<m;i++){
        for (j=0;j<m;j++){
            if (iszero(tmp[i][j]))dp[i][j]=-1;
            else dp[i][j]=1.0/tmp[i][j];
            if (iszero(tmp[j][i]))dp[j][i]=-1;
            else dp[j][i]=1.0/tmp[j][i];
        }
    }
    n=m;
    scanf("%d",&c);
    floyd(0);
}
void solve(){
    printf("%.6lf\n",dp[0][1]*c);
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--){
        init();
        solve();
    }
    return 0;
}
