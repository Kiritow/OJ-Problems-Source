#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <time.h>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <set>
#include <math.h>
#include <map>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,b,a) for(int i = (b); i >= (a); --i)
#define clr(a,x) memset(a,(x),sizeof(a))
#define LL long long
#define eps 1e-10
#define zero(x) -eps < (x) && (x) < eps
using namespace std;
short dp[2][1<<22];
int q[2][1<<15];
bool inq[2][1<<22];
const int inf = 1<<14;
char A[33][33];
int N,M;
inline int min(int a,int b) { return a < b ? a : b; }
inline int max(int a,int b) { return a > b ? a : b; }
inline int getBit(int s,int p)
{
    return (s & (3 << (p << 1))) >> (p << 1);
}
inline void setBit(int & s,int p,int x)
{
    s = (s ^ (s & (3 << (p<<1)))) | (x << (p<<1));
}
int cur;
int rear[2];
inline void update(int r,int c,int t,int cost)
{
    if (dp[cur^1][t] > cost) dp[cur^1][t] = cost;
    if (!inq[cur^1][t]) inq[cur^1][t] = true, q[cur^1][rear[cur^1]++] = t;
}
inline void dp_block(int r,int c,int s)
{
    int t, c1 = getBit(s,M), c2 = getBit(s,c);
    if (c1 || c2) return;
    if (A[r][c] == '#') {
        t = s;
        update(r,c,t,dp[cur][s]);
        return;
    }
    int side = 0;
    rep(j,0,c)
    if (getBit(s,j)) side ^= 1;
    if (side == 0 && A[r][c] == 'L') return;
    if (side == 1 && A[r][c] == 'W') return;
    t = s;
    update(r,c,t,dp[cur][s]);
}
inline void dp_digit(int r,int c,int s)
{
    int t;
    int c1 = getBit(s,M);
    int c2 = getBit(s,c);
    if (c1 == 0 && c2 == 0) {
        t = s;
        update(r,c,t,dp[cur][s]);
        setBit(t,M,2); setBit(t,c,1);
        if (c < M-1) update(r,c,t,dp[cur][s] + A[r][c] - '0');
    } else if (c1 == 0 || c2 == 0) {
        int x = (c1 == 0 ? c2 : c1);
        t = s;
        setBit(t,M,x); setBit(t,c,0);
        if (c < M-1) update(r,c,t,dp[cur][s] + A[r][c] - '0');
        t = s;
        setBit(t,c,x); setBit(t,M,0);
        update(r,c,t,dp[cur][s] + A[r][c] - '0');
    } else if (c1 == c2) {
        int z = (c1 == 1 ? c : c-1);
        for(; 0 <= z && z < M; z += (c1 == 1 ? 1 : -1))
        if (getBit(s,z) == (c1 ^ 3)) break;
        if (0 <= z && z < M) {
            t = s;
            setBit(t,z,c1);
            setBit(t,M,0); setBit(t,c,0);
            update(r,c,t,dp[cur][s] + A[r][c] - '0');
        }
    } else if (c1 == 2 && c2 == 1) {
        t = s; setBit(t,M,0); setBit(t,c,0);
        update(r,c,t,dp[cur][s] + A[r][c] - '0');
    } else if (c1 == 3 && c2 == 1) {
        int z = c;
        for(; z < M; ++z)
        if (getBit(s,z) == 2) break;
        if (z < M) {
            t = s;
            setBit(t,c,0); setBit(t,M,0);
            setBit(t,z,3);
            update(r,c,t,dp[cur][s] + A[r][c] - '0');
        }
    } else if (c1 == 2 && c2 == 3) {
        int z = c-1;
        for(; z >= 0; --z)
        if (getBit(s,z) == 1) break;
        if (z >= 0) {
            t = s;
            setBit(t,c,0); setBit(t,M,0);
            setBit(t,z,3);
            update(r,c,t,dp[cur][s] + A[r][c] - '0');
        }
    }
}
void solve()
{
    cur = 0;
    rear[0] = rear[1] = 0;
    rep(i,0,(1<<((M+1)<<1))) dp[0][i] = dp[1][i] = inf;
    clr(inq,0);
    rep(i,0,M) {
        int s = 0;
        setBit(s,i,3);
        dp[cur][s] = 0;
        q[cur][rear[cur]++] = s;
    }
    rep(i,0,N) rep(j,0,M) {
        rep(k,0,rear[cur]) {
            int s = q[cur][k];
            if (isdigit(A[i][j])) dp_digit(i,j,s);
            else dp_block(i,j,s);
            inq[cur][s] = false;
            dp[cur][s] = inf;
        }
        rear[cur] = 0;
        cur ^= 1;
    }
    int ans = inf;
    int c = 0;
    rep(j,0,M) {
        int s = 0;
        setBit(s,j,3);
        ans = min(ans,dp[cur][s]);
    }
    if (ans == inf) ans = -1;
    printf("%d\n",ans);
}
int main()
{
    while (scanf("%d%d",&N,&M)==2) {
        rep(i,0,N) scanf("%s",A[i]);
        int W = 0, L = 0;
        rep(i,0,N) rep(j,0,M)
        if (A[i][j] == 'W') ++W;
        else if (A[i][j] == 'L') ++L;
        solve();
    }
}
