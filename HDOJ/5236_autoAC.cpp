#include <cstdio>
#include <limits>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
const int MAXS = 30;  
int N, X, S;
double P, F[MAXS];
void CalcF(){
    int i;
    double a = 1, b = 1. / (P - 1.);
    S = numeric_limits<int>::max();
    F[0] = 0.;
    F[1] = - b / a;
    for(i = 2; i <= N && i <= S; i ++){
        a = (a - P) / (1 - P);
        b = (b - 1) / (1 - P);
        F[i] = - b / a;
        if(F[i] > F[i >> 1] + F[i - (i >> 1)] + X){
            F[i] = F[i >> 1] + F[i - (i >> 1)] + X;
            S = i;
        }
    }
}
double BFSolve(){
    static double dp[MAXN];
    int i, j;
    dp[0] = 0;
    for(i = 1; i <= N; i ++){
        if(i <= S){
            dp[i] = F[i] + X;
        }else{
            dp[i] = numeric_limits<double>::max();
        }
        for(j = 1; j <= S && j < i; j ++){
            dp[i] = min(dp[i], dp[i - j] + dp[j]);
        }
    }
    return dp[N];
}
double Solve(){
    int i, a, b;
    double ans = numeric_limits<double>::max();
    if(N < S)
        return F[N] + X;
    for(i = 1; i <= S; i ++){
        a = N / i;
        b = N % i;
        if(a >= b && i < S){
            ans = min(ans, (a - b) * F[i] + b * F[i + 1] + a * X);
        }
        if(a + b + 1 >= i){
            ans = min(ans, (a + 1 - i + b) * F[i] + (i - b) * F[i - 1] + (a + 1) * X);
        }
    }
    return ans;
}
int main(){
    int T, i;
    scanf("%d", &T);
    for(i = 1; i <= T; i ++){
        scanf("%d%lf%d", &N, &P, &X);
        CalcF();
        printf("Case #%d: %.6lf\n", i, Solve());
    }
    return 0;
}
