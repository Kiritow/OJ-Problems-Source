#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
 
const int N = 4;
 
struct mat {
    LL c[N][N];
    mat() { memset(c, 0, sizeof(c)); }
};
 
int T;
LL n, y, x, s, mod;
 
mat operator *(mat a, mat b) {
    mat c;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++) {
                c.c[i][j] += a.c[i][k]*b.c[k][j];
                if(c.c[i][j] >= mod) (c.c[i][j] %= mod) += mod;
            }
    return c;
}
 
mat operator ^(mat x, LL a) {
    mat res;
    for(int i = 0; i < N; i++) res.c[i][i] = 1;
    while(a) {
        if(a & 1) res = res * x;
        x = x * x;
        a >>= 1;
    }
    return res;
}
 
LL quick_mi(LL x, LL a) {
    LL res = 1;
    while(a) {
        if(a & 1) res = res * x % mod;
        x = x * x % mod;
        a >>= 1;
    }
    return res;
}
 
LL phi(LL n) {
    LL res = n;
    for(LL i = 2, mx = sqrt(n+0.5); i <= mx; i++) {
        if(n % i) continue;
        res = res - res / i;
        while(n % i == 0) n /= i;
    }
    if(n > 1) res = res - res / n;
    return res;
}
 
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    mat bb;
    bb.c[0][0] = 1; bb.c[0][1] = 4; bb.c[0][2] = 1; bb.c[0][3] = 4;
    bb.c[1][0] = 0; bb.c[1][1] = 4; bb.c[1][2] = 1; bb.c[1][3] = 4;
    bb.c[2][0] = 0; bb.c[2][1] = 1; bb.c[2][2] = 0; bb.c[2][3] = 0;
    bb.c[3][0] = 0; bb.c[3][1] = 2; bb.c[3][2] = 0; bb.c[3][3] = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%lld%lld%lld%lld", &n, &y, &x, &s);
        if(n == 0 || y == 0) {
            puts("1");
            continue;
        }
        mod = phi(s+1);
        mat aa;
        aa.c[0][0] = 1; aa.c[1][0] = 1; aa.c[2][0] = 0; aa.c[3][0] = 0;
        aa = (bb^(n*y-1))*aa;
        mod = s+1;
        printf("%lld\n", quick_mi(x, aa.c[0][0]));
    }
    return 0;
}
