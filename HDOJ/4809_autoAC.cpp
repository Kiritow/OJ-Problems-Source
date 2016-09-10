#include <iostream>   
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <string>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):(-(x)))
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define FORD(i,a,b) for(int i = (a);i>=(b);i--)
#define REP(i,n) for(int i = 0;i<(n);i++)
#define rst(x,k) memset(x,k,sizeof(x))
#define lowbit(x) ((x)&(-(x)))
#define h(x) (1<<(x))
#define lson (ind<<1)
#define rson (ind<<1|1)
#define eps 1e-6
#define maxn 480
#define INF 1000000000
#define mod 1000000007LL
#define base 160
#define link fsafsdfas
using namespace std;
typedef long long LL;
struct node{
    int t,nxt;
}edge[maxn<<1];
int headline[maxn],E;
void add(int f,int t){
    edge[E].t = t;
    edge[E].nxt = headline[f];
    headline[f] = E++;
}
LL dp[310][3][480];
LL tt[310][3][480];
int n;
int high[310],low[310];
int up,down;
void dfs(int u,int fa){
    dp[u][0][base] = 2;
    dp[u][1][base] = 1;
    high[u] = low[u] = 0;
    for(int i = headline[u];~i;i = edge[i].nxt){
        int v = edge[i].t; if(v == fa)continue;
        dfs(v,u);rst(tt[u],0);
        FOR(p,low[u],high[u]){                  
            FOR(q,low[v]-1,high[v]+1){
                if((p+q > n) || (p+q < (-n)/2-2))continue;
                tt[u][0][p+q+base] += dp[u][0][p+base]*dp[v][0][q+base] + dp[u][0][p+base]*dp[v][1][q+base-1] + dp[u][0][p+base]*dp[v][2][q+base+1];
                tt[u][1][p+q+base] += dp[u][1][p+base]*dp[v][0][q+base] + dp[u][1][p+base]*dp[v][2][q+base] + dp[u][2][p+base]*dp[v][1][q+base];
                tt[u][2][p+q+base] += dp[u][1][p+base]*dp[v][1][q+base] + dp[u][2][p+base]*dp[v][0][q+base] + dp[u][2][p+base]*dp[v][2][q+base];
                tt[u][0][p+q+base] %= mod; if(tt[u][0][p+q+base] && p+q > high[u]) high[u] = p+q; if(tt[u][0][p+q+base] && p+q < low[u])low[u] = p+q;
                tt[u][1][p+q+base] %= mod; if(tt[u][1][p+q+base] && p+q > high[u]) high[u] = p+q; if(tt[u][1][p+q+base] && p+q < low[u])low[u] = p+q;
                tt[u][2][p+q+base] %= mod; if(tt[u][2][p+q+base] && p+q > high[u]) high[u] = p+q; if(tt[u][2][p+q+base] && p+q < low[u])low[u] = p+q;
            }
        }
        FOR(j,low[u],high[u]){
            dp[u][0][j+base] = tt[u][0][j+base];
            dp[u][1][j+base] = tt[u][1][j+base];
            dp[u][2][j+base] = tt[u][2][j+base];
        }
    }
}
void solve(){
    rst(headline,-1); E = 0;
    rst(dp,0);
    REP(i,n-1){
        int a,b; scanf("%d%d",&a,&b);
        add(a,b); add(b,a);
    }
    up = n; down = -n/2-1;
    dfs(1,0);
    LL ans = 0;
    FOR(i,-1,up){
        ans += dp[1][0][i+base]*(MAX(i,0))%mod;
        ans += dp[1][1][i+base]*(MAX(i+1,0))%mod;
        ans += dp[1][2][i+base]*(MAX(i-1,0))%mod;
        ans %= mod;
    }
    printf("%I64d\n",ans*3%mod);
}
int main(void){
    while(EOF != scanf("%d",&n))solve();
    return 0;
}
