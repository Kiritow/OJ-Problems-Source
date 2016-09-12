#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N = 200007;
typedef unsigned long long ll;
struct SAM {
    int val[MAX_N], fa[MAX_N], c[26][MAX_N];
    int tot, last;
    int which[MAX_N];
    inline int newNode(int step) {
        val[++tot] = step;
        fa[tot] = 0;
        for (int i = 0; i < 26; ++i) c[i][tot] = 0;
        return tot;
    }
    inline void extend(int k) {
        int p = last;
        int np = newNode(val[last] + 1);
        which[np] = k;
        while (p && !c[k][p]) c[k][p] = np, p = fa[p];
        if (!p) fa[np] = 1;
        else {
            int q = c[k][p];
            if (val[q] == val[p] + 1) fa[np] = q;
            else {
                int nq = newNode(val[p] + 1);
                which[nq] = k;
                for (int i = 0; i < 26; ++i) c[i][nq] = c[i][q];
                fa[nq] = fa[q]; 
                fa[q] = fa[np] = nq;
                while (p && c[k][p] == q) c[k][p] = nq, p = fa[p];
            }
        }
        last = np;
    }
    inline int add(int k) {
        extend(k);
    }
    inline void init() {
        tot = 0;
        last = newNode(0);
    }
} suf;
char A[MAX_N>>1], B[MAX_N>>1];
ll dp[26];
int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        suf.init();
        scanf("%s%s", A, B);
        int n = strlen(B);
        reverse(B, B + n);
        for (int i = 0; B[i]; ++i) suf.add(B[i] - 'a');
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= suf.tot; ++i) 
            dp[suf.which[i]] += suf.val[i] - suf.val[suf.fa[i]];
        suf.init(); 
        for (int i = 0; A[i]; ++i) suf.add(A[i] - 'a');
        ll ans = 0;
        for (int i = 1; i <= suf.tot; ++i) {
            for (int j = 0; j < 26; ++j) if (!suf.c[j][i]) {
                ans += dp[j] * (suf.val[i] - suf.val[suf.fa[i]]);
            }
            if (suf.fa[i]) ans += suf.val[i] - suf.val[suf.fa[i]];
        }
        printf("%I64u\n", ans + 1);
    }
    return 0;
}
