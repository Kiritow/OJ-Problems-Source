#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1 * 1e5 + 5;
ll S;
int N, M, L[10], X[10], head, rear, ans;
map<ll, int> C;
set<ll> T;
struct State {
    ll s;
    int f, c;
    State(ll s = 0, int f = 0, int c = 0): s(s), f(f), c(c) {}
}Q[maxn], cur;
inline ll idx(int* c) {
    ll ret = 0;
    for (int i = 0; i < 12; i++)
        ret = ret * (N+1) + c[i];
    return ret;
}
inline void reidx(ll s, int* c) {
    for (int i = 11; i >= 0; i--) {
        c[i] = s % (N+1);
        s /= (N+1);
    }
}
void init () {
    C.clear();
    T.clear();
    scanf("%d%d", &N, &M);
    int x, cnt[15];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= N; i++) {
        scanf("%d", &x);
        if (x == 12) x = 0;
        cnt[x]++;
    }
    S = idx(cnt);
    for (int i = 0; i < M; i++)
        scanf("%d%d", &L[i], &X[i]);
}
bool dfs1 (int d, int* c, int* t, int n, int m, int v) {
    if (d > 12 || n > m) return false;
    if (n == 0 && m == 0) {
        ll tmp = idx(t);
        if (tmp == S) {
            ans = cur.c + 1;
            return true;
        }
        if (!C.count(tmp)) {
            C[tmp] = cur.c + 1;
            if (cur.c < 4) Q[rear++] = State(tmp, v, cur.c+1);
        }
        return false;
    }
    for (int i = min(c[d], n); i >= 0; i--) {
        if (n-i > m-c[d]) break;
        t[(d-X[v]+12)%12] += i;
        t[d] += (c[d] - i);
        if (dfs1(d+1, c, t, n-i, m-c[d], v)) return true;
        t[(d-X[v]+12)%12] -= i;
        t[d] -= (c[d] - i);
    }
    return false;
}
bool dfs2 (int d, int* c, int* t, int n, int m, int v) {
    if (d > 12 || n > m) return false;
    if (n == 0 && m == 0) {
        ll tmp = idx(t);
        if (C.count(tmp)) {
            ans = C[tmp] + cur.c + 1;
            return true;
        }
        if (!T.count(tmp) && cur.c < 2) {
            T.insert(tmp);
            Q[rear++] = State(tmp, v, cur.c+1);
        }
        return false;
    }
    for (int i = min(c[d], n); i >= 0; i--) {
        if (n-i > m-c[d]) break;
        t[(d+X[v]+12)%12] += i;
        t[d] += (c[d] - i);
        if (dfs2(d+1, c, t, n-i, m-c[d], v)) return true;
        t[(d+X[v]+12)%12] -= i;
        t[d] -= (c[d] - i);
    }
    return false;
}
int bfs() {
    int cnt[15], pos[15];
    memset(cnt, 0, sizeof(cnt));
    cnt[0] = N;
    ll k = idx(cnt);
    if (S == k) return 0;
    C[k] = 0;
    head = rear = 0;
    for (int i = 0; i < M; i++) {
        int x = (-X[i] + 12) % 12;
        cnt[x] += L[i];
        cnt[0] -= L[i];
        ll tmp = idx(cnt);
        if (!C.count(tmp)) {
            if (tmp == S) return 1;
            Q[rear++] = State(tmp, i, 1);
            C[tmp] = 1;
        }
        cnt[x] -= L[i];
        cnt[0] += L[i];
    }
    while (head < rear) {
        cur = Q[head++];
        reidx(cur.s, cnt);
        for (int i = M-1; i >= cur.f; i--) {
            memset(pos, 0, sizeof(pos));
            if (dfs1(0, cnt, pos, L[i], N, i))
                return ans;
        }
    }
    head = rear = 0;
    Q[rear++] = State(S, 0, 0);
    while (head < rear) {
        cur = Q[head++];
        reidx(cur.s, cnt);
        for (int i = M-1; i >= cur.f; i--) {
            memset(pos, 0, sizeof(pos));
            if (dfs2(0, cnt, pos, L[i], N, i)) return ans;
        }
    }
    return -1;
}
int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        init();
        printf("%d\n", bfs());
    }
    return 0;
}
