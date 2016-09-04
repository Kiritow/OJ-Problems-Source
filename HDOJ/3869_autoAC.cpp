#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <functional>
#include <numeric>
#include <sstream>
#include <stack>
#include <map>
#include <queue>
#define CL(arr, val)    memset(arr, val, sizeof(arr))
#define REP(i, n)       for((i) = 0; (i) < (n); ++(i))
#define FOR(i, l, h)    for((i) = (l); (i) <= (h); ++(i))
#define FORD(i, h, l)   for((i) = (h); (i) >= (l); --(i))
#define L(x)    (x) << 1
#define R(x)    (x) << 1 | 1
#define MID(l, r)   (l + r) >> 1
#define Min(x, y)   (x) < (y) ? (x) : (y)
#define Max(x, y)   (x) < (y) ? (y) : (x)
#define E(x)        (1 << (x))
#define iabs(x)     (x) < 0 ? -(x) : (x)
#define OUT(x)  printf("%lld\n", x)
typedef long long LL;
const double eps = 1e-6;
const double PI = acos(-1.0);
const int inf = 0x1F1F1F1F;
using namespace std;
const int N = 100010;
const int MOD = 1000000007;
int n;
int pre[N];
bool vis[2][N];
int v[N], e[N];
int vv[N<<1], ee[N<<1];
void get_next(int P[]) {
    int i, j = -1;
    pre[0] = -1;
    for(i = 1; i < n; ++i) {
        while(j > -1 && P[j+1] != P[i]) j = pre[j];
        if(P[j + 1] == P[i])    ++j;
        pre[i] = j;
    }
}
void kmp(int T[], int P[], int f) {
    get_next(P);
    int i, k;
    for(k = -1, i = 0; i < (n<<1); ++i) {
        while(k > -1 && P[k+1] != T[i]) k = pre[k];
        if(P[k+1] == T[i])  ++k;
        if(k == n - 1)  {
            vis[f][i - n + 1] = true;
            k = pre[k];
        }
    }
}
LL Pow(LL a, int b) {
    LL res = 1;
    while(b) {
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return res;
}
int exp_gcd(int a, int b, int& x, int& y) {
    if(b == 0) {
        x = 1; y = 0;
        return a;
    }
    int d = exp_gcd(b, a%b, y, x);  
    y -= a/b*x;                 
    return d;
}
int Inv(int c) {
    int x, y;
    exp_gcd(c, MOD, x, y);
    return x < 0 ? x + MOD : x;
}
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}
int main() {
    int T, c, cnt, i;
    LL ans;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &c);
        for(i = 0; i < n; ++i)  {scanf("%d", &v[i]); vv[i] = vv[i+n] = v[i];}
        for(i = 0; i < n; ++i)  {scanf("%d", &e[i]); ee[i] = ee[i+n] = e[i];}
        CL(vis, false);
        kmp(vv, v, 0);
        kmp(ee, e, 1);
        ans = cnt = 0;
        for(i = 1; i <= n; ++i) {
            if(vis[0][i] && vis[1][i]) {
                ans += Pow(c, gcd(i, n));
                ans %= MOD;
                cnt++;
            }
        }
        ans = ans*Inv(cnt)%MOD;
        cout << ans << endl;
    }
    return 0;
}
