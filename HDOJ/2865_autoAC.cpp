#include<cstdio>
#include<cstring>
#include<vector>
#define P 1000000007
#define MAXM 2
#define MAXN 32000
typedef long long LL;
using namespace std;
bool p[MAXN];
vector<int> factor;
vector<int> prime;
struct Matrix {
    LL mat[MAXM][MAXM];
    void Zero() {
        memset(mat, 0, sizeof(mat));
    }
    void Unit() {
        Zero();
        mat[0][0] = mat[1][1] = 1;
    }
    void Build(int k) {
        Zero();
        mat[0][1] = 1;
        mat[0][0] = k - 2;
        mat[1][0] = k - 1;
    }
};
Matrix operator *(Matrix &a, Matrix &b) {
    int i, j, k;
    Matrix tmp;
    tmp.Zero();
    for (i = 0; i < MAXM; i++) {
        for (j = 0; j < MAXM; j++) {
            for (k = 0; k < MAXM; k++)
                tmp.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            tmp.mat[i][j] %= P;
        }
    }
    return tmp;
}
Matrix operator ^(Matrix a, int k) {
    Matrix tmp;
    for (tmp.Unit(); k; k >>= 1) {
        if (k & 1)
            tmp = tmp * a;
        a = a * a;
    }
    return tmp;
}
void Factor(int n) {
    int i;
    factor.clear();
    for (i = 1; i * i < n; i++) {
        if (n % i == 0) {
            factor.push_back(i);
            factor.push_back(n / i);
        }
    }
    if (i * i == n)
        factor.push_back(i);
}
LL ExtGcd(LL a, LL b, LL &x, LL &y) {
    LL t, d;
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    d = ExtGcd(b, a % b, x, y);
    t = x;
    x = y;
    y = t - a / b * y;
    return d;
}
LL InvMod(LL a, LL n) {
    LL x, y;
    ExtGcd(a, n, x, y);
    return (x % n + n) % n;
}
int Count(int x) {
    int res, i;
    res = x;
    for (i = 0; prime[i] * prime[i] <= x; i++) {
        if (x % prime[i] == 0) {
            res -= res / prime[i];
            while (x % prime[i] == 0)
                x /= prime[i];
        }
    }
    if (x > 1)
        res -= res / x;
    return res;
}
LL F(int n, int k) {
    LL res;
    if (n == 1)
        res = 0;
    else if (n == 2)
        res = (LL) k * (k - 1);
    else if (n == 3)
        res = (LL) k * (k - 1) % P * (k - 2);
    else {
        Matrix g;
        g.Build(k);
        g = g ^ (n - 3);
        res = g.mat[0][0] * k % P * (k - 1) % P * (k - 2);
        res += g.mat[1][0] * k % P * (k - 1);
    }
    return res % P;
}
LL Burnside(int n, int k) {
    LL ans;
    int i;
    Factor(n);
    for (i = ans = 0; i < (int) factor.size(); i++) {
        ans += F(factor[i], k) * Count(n / factor[i]) % P;
        if (ans >= P)
            ans -= P;
    }
    return ans * InvMod(n, P) % P;
}
void Init() {
    int i, j;
    memset(p, true, sizeof(p));
    for (i = 2; i < 180; i++) {
        if (p[i]) {
            for (j = i * i; j < MAXN; j += i)
                p[j] = false;
        }
    }
    prime.clear();
    for (i = 2; i < MAXN; i++) {
        if (p[i])
            prime.push_back(i);
    }
}
int main() {
    int n, k;
    Init();
    while (~scanf("%d%d", &n, &k))
        printf("%I64d\n", Burnside(n, k - 1) * k % P);
    return 0;
}
