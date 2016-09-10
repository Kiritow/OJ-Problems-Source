#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define inf 0x0f0f0f0f
#define in freopen("data.txt", "r", stdin);
#define  pb push_back
using namespace std;
typedef long long LL;
const int maxnode = 44;
const int sigma_size = 26;
int prime[maxnode], vis[1111];
void getPrime() {
    int cnt = 0;
    for(int i = 2; i < 1111 && cnt <= 40; i++) {
        if(!vis[i]) prime[++cnt] = i;
        for(int j = i*i; j < 1111; j += i)
            vis[j] = 1;
    }
}
struct Node {
    int len, n;
    Node(int len, int n): len(len), n(n) {}
};
int ch[maxnode][sigma_size], sz, f[maxnode];
vector<Node> vec[maxnode];
struct Matrix {
    int a[44][44];
} xx[200], E0;;
void maMul(Matrix x, Matrix y, Matrix &res, int mod) {
    for(int i = 0; i < sz; i++)
        for(int j = 0; j < sz; j++) {
            res.a[i][j] = 0;
            for(int k = 0; k < sz; k++) {
                res.a[i][j] += x.a[i][k]*y.a[k][j]%mod;
                if(res.a[i][j] >= mod)
                    res.a[i][j] -= mod;
            }
        }
}
struct AC {
    void init() {
        sz = 1;
        memset(ch[0], 0, sizeof ch[0]);
        vec[0].clear();
    }
    int idx(char ch) {
        return ch - 'A';
    }
    void insert(char *s, int x) {
        int u = 0, len = 0;
        for(int i = 0; s[i]; i++, len++) {
            int c = idx(s[i]);
            if(!ch[u][c]) {
                memset(ch[sz], 0, sizeof ch[sz]);
                vec[sz].clear();
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        vec[u].pb(Node(len, prime[x]));
    }
    void getFail() {
        queue<int> q;
        f[0] = 0;
        for(int c = 0; c < sigma_size; c++) {
            int u = ch[0][c];
            if(u) {
                f[u] = 0;
                q.push(u);
            }
        }
        while(!q.empty()) {
            int r = q.front();
            q.pop();
            for(int c = 0; c < sigma_size; c++) {
                int u = ch[r][c];
                if(!u) {
                    ch[r][c] = ch[f[r]][c];
                    continue;
                }
                q.push(u);
                int v = f[r];
                while(v && !ch[v][c]) v = f[v];
                f[u] = ch[v][c];
            }
        }
    }
    void getMat(int x, int mod) {
        for(int i = 0; i < sz; i++) for(int j = 0; j < sz; j++) xx[x].a[i][j] = 0;
        for(int u = 0; u < sz; u ++)
            for(int c = 0; c < sigma_size; c++) {
                int v = ch[u][c];
                int tv = v;
                int res = 1;
                while(tv) {
                    for(int i = 0; i < (int)vec[tv].size(); i++) {
                        (res *= ((LL)(vec[tv][i].len+x)*vec[tv][i].n%mod))%=mod;
                    }
                    tv = f[tv];
                }
                xx[x].a[v][u] += res;
                if(xx[x].a[v][u] >= mod) xx[x].a[v][u] -= mod;
            }
    }
} solver;
int N;
LL L;
int M[] = {163, 173, 179};
int ans[3], a[3];
int exgcd(int a, int b, int &x, int &y) {
    if(!b) {
        x = 1, y = 0;
        return a;
    } else {
        int tmp = exgcd(b, a%b, y, x);
        y -= (a/b)*x;
        return tmp;
    }
}
void powmod(Matrix x, LL n, Matrix &res, int mod) {
    res = E0;
    while(n) {
        if(n&1) maMul(res, x, res, mod);
        maMul(x, x, x, mod);
        n >>= 1;
    }
}
int solve() {
    solver.getFail();
    int mul = 1, res = 0;
    for(int i = 0; i < 3; i++) mul *= M[i];
    for(int i = 0; i < 3; i++) {
        a[i] = mul/M[i];
        Matrix tmp1, tmp2;
        tmp1 = tmp2 = E0;
        LL lv = L%M[i];
        for(int k = M[i]; k >= 1; k--) {
            solver.getMat(k, M[i]);
            maMul(tmp1, xx[k], tmp1, M[i]);
            if(k <= lv)
                maMul(tmp2, xx[k], tmp2, M[i]);
        }
        powmod(tmp1, L/M[i], tmp1, M[i]);
        maMul(tmp2, tmp1, tmp1, M[i]);
        ans[i] = 0;
        for(int k = 0; k < sz; k++) {
            ans[i] += tmp1.a[k][0];
            if(ans[i] >= M[i]) ans[i] -= M[i];
        }
        int xx, yy;
        exgcd(a[i], M[i], xx, yy);
        res += a[i]*ans[i]%mul*(xx%M[i])%mul;
        if(res >= mul)
            res -= mul;
    }
    return (res+mul)%mul;
}
int main() {
    getPrime();
    int kase = 0;
    for(int i = 0; i < 44; i++) for(int j = 0; j < 44; j++) E0.a[i][j] = i == j;
    while(scanf("%d%I64d", &N, &L) == 2) {
        solver.init();
        for(int i = 1; i <= N; i++) {
            char s[44];
            scanf("%s", s);
            solver.insert(s, i);
        }
        printf("Case #%d: %d\n", ++kase, solve());
    }
    return 0;
}
