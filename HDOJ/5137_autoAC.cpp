#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 40;
const int inf = 1000000000;
int n, m, f[N][N], dp[N][N];
int solve(int x){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==x || j==x)    dp[i][j] = inf;
            else    dp[i][j] = f[i][j];
        }
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++)    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
        }
    }
    return dp[1][n];
}
int main(){
    while(~scanf("%d %d", &n, &m) && (n||m)){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++)    f[i][j] = i==j?0:inf;
        }
        int a, b, c;
        while(m--){
            scanf("%d %d %d", &a, &b, &c);
            f[a][b] = min(f[a][b], c);
            f[b][a] = f[a][b];
        }
        int ans = 0;
        for(int i=2; i<n; i++){
            ans = max(ans, solve(i));
        }
        if(ans==inf)    puts("Inf");
        else    printf("%d\n", ans);
    }
    return 0;
}
