#include<cstdio>
#include<cstring>
#include<climits>
#include<string>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<stdlib.h>
using namespace std;
typedef long long ll;
const int MAXN = 20007;
vector<int> divisor[MAXN];
int f[MAXN], a[MAXN], L[MAXN], R[MAXN], cnt[MAXN], qid[MAXN], M;
ll ans[MAXN];
void getdivisor() {
    int i, j;
    for(i = 1; i < MAXN; i++) for(j = i; j < MAXN; j += i) divisor[j].push_back(i);
}
void getf() {
    for(int i = 1; i < MAXN; i++) {
        int t = i;
        int j, sz = divisor[i].size();
        for(j = 0; j < sz; j++) t -= f[divisor[i][j]];
        f[i] = t;
    }
}
int qcmp(int x, int y) {
    int px = L[x] / M; 
    int py = L[y] / M;
    if(px != py) return px < py;
    return R[x] < R[y];
}
ll erase(int x) {
    int i, y, sz = divisor[x].size();
    ll ret = 0;
    for(i = 0; i < sz; i++) {
        y = divisor[x][i];
        ret += 1LL*f[y]*(--cnt[y]);
    }
    return ret;
}
ll insert(int x) {
    int i, y, sz = divisor[x].size();
    ll ret = 0;
    for(i = 0; i < sz; i++) {
        y = divisor[x][i];
        ret += 1LL*f[y]*(cnt[y]++);
    }
    return ret;
}
void solve(int n, int q) {
    int i;
    for(i = 1; i <= q; i++) qid[i] = i;
    M = (int)sqrt(n*1.0);
    sort(qid+1, qid+1+q, qcmp);
    memset(cnt, 0, sizeof(cnt));
    int l = 0, r = 0;
    ll now = 0;
    for(i = 1; i <= q; i++) {
        int id = qid[i];
        int nl = L[id], nr = R[id];
        while(l < nl) {
            now -= erase(a[l]);
            l++;
        }
        while(l > nl) {
            l--;
            now += insert(a[l]);
        }
        while(r < nr) {
            r++;
            now += insert(a[r]);
        }
        while(r > nr) {
            now -= erase(a[r]);
            r--;
        }
        ans[id] = now;
    }
}
int main() {
    getdivisor();
    getf();
    int T, id = 0;
    scanf("%d", &T);
    while(T--) {
        int i, n, q;
        scanf("%d", &n);
        for(i = 1; i <= n; i++) scanf("%d", a+i);
        scanf("%d", &q);
        for(i = 1; i <= q; i++) scanf("%d%d", L+i, R+i);
        solve(n, q);
        printf("Case #%d:\n", ++id);
        for(i = 1; i <= q; i++) printf("%I64d\n", ans[i]);
    }
    return 0;
}
