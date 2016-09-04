#include<stdio.h> 
#include<string.h> 
#include<algorithm> 
#define MAXD 210 
int N, g[MAXD][MAXD], f[MAXD][MAXD], a[MAXD]; 
void init() 
{ 
    int i, j; 
    scanf("%d", &N); 
    for(i = 1; i <= N; i ++) 
        scanf("%d", &a[i]); 
    for(i = 1; i <= N; i ++) 
        for(j = 1; j <= N; j ++) 
            scanf("%d", &g[i][j]); } 
    int can(int i, int j, int k) 
    { 
        if(!f[i][k] || !f[k][j]) 
            return 0; 
        return g[i][k] || g[j][k]; 
    } 
void solve() 
{ 
    int i, j, k, d, ans = 0; 
    for(i = 1; i <= N; i ++) 
        g[i][0] = g[i][N + 1] = 1, g[0][i] = g[N + 1][i] = 0; 
    for(i = 0; i < N + 1; i ++) 
        f[i][i + 1] = 1; 
    for(d = 2; d <= N; d ++) 
        for(i = 0; (j = i + d) <= N + 1; i ++) 
        { 
            for(k = i + 1; k < j; k ++) 
            if(can(i, j, k)) 
            { 
                f[i][j] = 1; 
                break; 
            } 
            if(k == j) f[i][j] = 0; 
        } 
    for(i = 1; i <= N; i ++) 
        if(f[0][i] && f[i][N + 1]) 
            ans = std::max(ans, a[i]); 
    printf("%d\n", ans); 
} 
int main() { 
    int t, tt; 
    scanf("%d", &t); 
    for(tt = 1; tt <= t; tt ++) 
    { 
        init();
         printf("Case %d: ", tt); 
        solve(); 
    } 
    return 0;
}
