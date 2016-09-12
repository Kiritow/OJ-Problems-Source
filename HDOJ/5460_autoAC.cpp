#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = (1<<8)+5;
const int limit = 32 * 13 * 13;
typedef long long ll;
typedef map<int,ll>::iterator iter;
int N, Q, X[20], multi[maxn], ct[maxn];
map<int, ll> G[maxn];
int bitcount(int s) { return s == 0 ? 0 : bitcount(s>>1) + (s&1); }
void add (int u, int s, ll k) {
    if (s < 0) return;
    G[u][s] += k;
}
void merge(int u, int p, int q) {
    for (iter i = G[p].begin(); i != G[p].end(); i++) {
        for (iter j = G[q].begin(); j != G[q].end(); j++) {
            ll k = 1LL * i->second * j->second;
            add(u, i->first + j->first, k * 2);
            add(u, i->first * j->first, k * 2);
            add(u, i->first - j->first, k);
            add(u, j->first - i->first, k);
            if (i->first && j->first % i->first == 0)
                add(u, j->first / i->first, k);
            if (j->first && i->first % j->first == 0)
                add(u, i->first / j->first, k);
        }
    }
}
ll solve () {
    ll ret = 0;
    for (int i = 1; i < (1<<N); i++) {
        int cbit = bitcount(i);
        for (int u = i; u; u = (u-1)&i) {
            int v = u^i;
            if (u < v) break;
            merge(i, u, v);
        }
        if (G[i].count(Q))
            ret += G[i][Q] * cbit * cbit;
    }
    return ret;
}
int main () {
    int cas;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        scanf("%d%d", &N, &Q);
        for (int i = 0; i < (1<<N); i++) G[i].clear();
        for (int i = 0; i < N; i++) {
            scanf("%d", &X[i]);
            G[1<<i][X[i]] = 1;
        }
        printf("Case #%d: %lld\n", kcas, solve());
    }
    return 0;
}
