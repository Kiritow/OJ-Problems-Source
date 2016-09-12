#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1024 + 5;
const int mod = 1e9 + 7;
struct Rectangle {
    int x1, y1, x2, y2, c;
    Rectangle (int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int c = 0): x1(x1), y1(y1), x2(x2), y2(y2), c(c) {}
    void read() { scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c); }
    int size() { return (x2-x1+1)*(y2-y1+1); }
    bool in(const Rectangle& u) const {
        return x1 <= u.x1 && u.x2 <= x2 && y1 <= u.y1 && u.y2 <= y2;
    }
}R[15];
int N, M, H, W, cc, all, ct[15][maxn], sz[15][maxn];
vector<int> X, Y, C, G[15];
int bitcount(int x) { return x == 0 ? 0 : bitcount(x>>1) + (x&1); }
void init () {
    scanf("%d%d%d%d", &H, &W, &M, &N);
    X.clear(), Y.clear(), C.clear();
    for (int i = 0; i < N; i++) {
        R[i].read();
        X.push_back(R[i].x1-1);
        X.push_back(R[i].x2);
        Y.push_back(R[i].y1-1);
        Y.push_back(R[i].y2);
        C.push_back(R[i].c);
    }
    X.push_back(0);
    X.push_back(H);
    Y.push_back(0);
    Y.push_back(W);
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(C.begin(), C.end());
    int cx = unique(X.begin(), X.end()) - X.begin();
    int cy = unique(Y.begin(), Y.end()) - Y.begin();
    cc = unique(C.begin(), C.end()) - C.begin();
    int id[15], rk[15];
    for (int i = 0; i < cc; i++) G[i].clear();
    for (int i = 0; i < N; i++) {
        id[i] = lower_bound(C.begin(), C.begin()+cc, R[i].c) - C.begin();
        rk[i] = G[id[i]].size();
        G[id[i]].push_back(i);
    }
    all = 0;
    memset(ct, 0, sizeof(ct));
    memset(sz, 0, sizeof(sz));
    for (int x = 1; x < cx; x++) {
        for (int y = 1; y < cy; y++) {
            int t = cc, s = 0;
            Rectangle tmp = Rectangle(X[x-1]+1, Y[y-1]+1, X[x], Y[y]);
            for (int i = 0; i < N; i++) {
                if (R[i].in(tmp)) {
                    if (id[i] < t)
                        s = 0, t = id[i];
                    if (t == id[i])
                        s |= (1<<rk[i]);
                }
            }
            if (t == cc) all += tmp.size();
            else {
                int add = tmp.size();
                for (int j = s; j; j = (j-1)&s)
                    ct[t][j] += add;
            }
        }
    }
    for (int c = 0; c < cc; c++) {
        int s = (1<<G[c].size());
        for (int i = 0; i < s; i++) {
            for (int j = i; j; j = (j-1)&i)
                sz[c][i] += ct[c][j] * (bitcount(j)&1 ? 1 : -1);
        }
    }
}
ll pow_mod(ll x, ll n) {
    ll ret = 1;
    while (n) {
        if (n&1) ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}
int solve () {
    ll ret = pow_mod(M, all);
    for (int i = 0; i < cc; i++) {
        int t = 0, n = (1<<G[i].size());
        for (int s = 0; s < n; s++) {
            int si = bitcount(s)&1 ? -1 : 1;
            t = ((t + si * pow_mod(C[i]-1, sz[i][s]) * pow_mod(C[i], sz[i][n-1]-sz[i][s])) % mod + mod) % mod;
        }
        ret = ret * t % mod;
    }
    return ret;
}
int main () {
    int cas;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        init();
        printf("Case #%d: %d\n", kcas, solve());
    }
    return 0;
}
