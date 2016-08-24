#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int mod = 20090717;
const int maxn = 103;
const int max_num = 26;
int idx[256];
int n, m, x;
int dp[26][103][1026];
bool vis[26][103][1026];
int cnt[1025];
struct node {
    int v, p, zt;
    node(){}
    node(int v, int p, int zt) : v(v), p(p), zt(zt){}
}Q[1000006];
struct AcAuto {
    int val[maxn], f[maxn];
    int ch[maxn][max_num], tot;
    void init() {
        tot = 0;
        new_node();
        int i;
        for(i = 0; i < 26; i++)
            idx['a'+i] = i;
    }
    inline int new_node() {
        memset(ch[tot], 0, sizeof(ch[tot]));
        val[tot] = 0;
        f[tot] = 0;
        return tot++;
    }
    void insert(char *s, int id) {
        int i, j, p = 0;
        for(;*s; s++) {
            int k = idx[*s];
            if(!ch[p][k]) ch[p][k] = new_node();
            p = ch[p][k];
        }
        val[p] |= 1<<id;
    }
    void getfail() {
        int i, j, p = 0;
        int q[maxn];
        int *s = q, *e = q;
        for(i = 0; i < max_num; i++) if(ch[0][i]) *e++ = ch[0][i];
        while(s != e) {
            int u = *s++;
            for(i = 0; i < max_num; i++) {
                int &v = ch[u][i];
                if(!v) { v = ch[f[u]][i]; continue; }
                *e++ = v;
                j = f[u];
                while(j && !ch[j][i]) j = f[j];
                f[v] = ch[j][i];
                val[v] |= val[f[v]];
            }
        }
    }
    void solve() {
        int i, j, k, u;
        int M = (1<<m);
        for(i = 0; i <= n; i++)
            for(k = 0; k < tot; k++)
                for(j = 0; j < M; j++)
                    dp[i][k][j] = 0;
        dp[0][0][0] = 1;
        node *s = Q, *e = Q;
        *e++ = node(0, 0, 0);
        vis[0][0][0] = 1;
        while(s != e) {
            node u = *s++;
            vis[u.v][u.p][u.zt] = 0;
            if(u.v >= n) continue;
            for(i = 0; i < max_num; i++) {
                int p = ch[u.p][i];
                node v = node(u.v+1, p, u.zt|val[p]);
                dp[v.v][v.p][v.zt] += dp[u.v][u.p][u.zt];
                if(dp[v.v][v.p][v.zt] >= mod) dp[v.v][v.p][v.zt] -= mod;
                if(!vis[v.v][v.p][v.zt]) {
                    vis[v.v][v.p][v.zt] = 1;
                    *e++ = v;
                }
            }
        }
        int ans = 0;
        for(i = 0; i < M; i++) {
            if(cnt[i] >= x)
            for(j = 0; j < tot; j++) {
                ans += dp[n][j][i];
                if(ans >= mod) ans -= mod;
            }
        }
        printf("%d\n", ans);
    }
}AC;
char str[13];
int main() {
    int i, j;
    for(i = 0; i < 1024; i++) {
        int c = 0;
        for(j = i; j; j -= (j&-j)) c++;
        cnt[i] = c;
    }
    while( ~scanf("%d%d%d", &n, &m, &x) && (n || m || x)) {
        AC.init();
        for(i = 0; i < m; i++) {
            scanf("%s", str);
            AC.insert(str, i);
        }
        AC.getfail();
        AC.solve();
    }
    return 0;
}
