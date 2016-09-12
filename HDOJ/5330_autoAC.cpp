#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int pow3[20];
int dp[2][200000][24];
char w[12];
long long ans[100];
int num[200000];
int main(){
    pow3[0] = 1;
    for(int i = 1;i <= 11; i++)
        pow3[i] = pow3[i-1]*3;
    int t,m,n;
    scanf("%d",&t);
    for(int tt = 1; tt <= t; tt++){
        memset(dp,0,sizeof(dp));
        memset(num,0,sizeof(num));
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n; i++){
            scanf("%s",w);
            int u = 0;
            for(int j = 0;j < m; j++){
                u = u*3+w[j]-'0';
            }
            dp[0][u][0]++;
            num[u]++;
        }
        int p = 0, q = 1,s0,s1,s2;
        for(int mm=1;mm<=m;mm++){
            memset(dp[q],0,sizeof(dp[q]));
            for(int i = 0;i < pow3[mm-1];i++){
                for(int j = 0;j < pow3[m-mm];j++){
                    for(int d = 0; d <= 2*m;d++){
                        s0 = i+j*pow3[mm];
                        s1 = s0 + pow3[mm-1];
                        s2 = s1 + pow3[mm-1];
                        dp[q][s0][d] += dp[p][s0][d];
                        dp[q][s1][d] += dp[p][s1][d];
                        dp[q][s2][d] += dp[p][s2][d];
                        if(d > 0){
                            dp[q][s0][d] += dp[p][s1][d-1];
                            dp[q][s1][d] += dp[p][s0][d-1];
                            dp[q][s1][d] += dp[p][s2][d-1];
                            dp[q][s2][d] += dp[p][s1][d-1];
                        }
                        if(d > 1){
                            dp[q][s0][d] += dp[p][s2][d-2];
                            dp[q][s2][d] += dp[p][s0][d-2];
                        }
                    }
                }
            }
            swap(p,q);
        }
        memset(ans,0,sizeof(ans));
        for(int i = 0;i < pow3[m]; i++){
            ans[0] += 1ll*num[i]*(num[i]-1);
            for(int j = 1 ;j <= 2*m; j++)
                ans[j] += 1ll*num[i]*dp[p][i][j];
        }
        for(int i = 0;i <= 2*m; i++)
            printf("%I64d\n",ans[i]/2);
    }
    return 0;
}
