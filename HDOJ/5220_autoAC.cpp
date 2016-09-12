#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
#pragma comment(linker, "/STACK:102400000,102400000") 
#define pb push_back
#define mp make_pair
#define F first
#define S second
const int N = 33;
int f[N], c[N], m[N], d[N], w[N];
vector<int> a[N], b[N];
typedef pair<int, int> pii;
map<pii, LL> g[2];
map<pii, LL>:: iterator it;
int main() {
	int n, T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= 32; ++i)	a[i].clear(), b[i].clear();
		memset(w, 0, sizeof(w));
		memset(d, 0, sizeof(d));
		g[0].clear(), g[1].clear();
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d", &f[i], &c[i], &m[i]);
			a[f[i]].pb(i), b[c[i]].pb(i);
		}
		bool ok = 1;
		int mask = 0, cnt = 0;
		for (int i = 1; i <= 32; ++i) {
			if (b[i].size() == 1) {
				if (d[f[b[i][0]]])	ok = 0;
				mask ^= m[b[i][0]];
				d[f[b[i][0]]] = 1;
			}
			else if (b[i].size() > 1) w[i] = cnt++; 
		}	
		if (!ok) {
			puts("0");
			continue;
		}
		int now = 0;
		g[now].insert(mp(mp(0, 0), 1));
		for (int i = 1; i <= 32; ++i) {
			if (!a[i].size() || d[i])	continue;
			g[now ^ 1] = g[now];
			for (it = g[now].begin(); it != g[now].end(); it++) {
				pii st = it -> F;
				LL d = it -> S;
				for (int j = 0; j < a[i].size(); ++j) {
					int t = a[i][j];
					pii tmp = mp(st.F ^ m[t], st.S | (1 << w[c[t]]));
					g[now ^ 1][tmp] += d;
				}
			}
			now ^= 1;
		}
		printf("%I64d\n", g[now][mp(mask, (1 << cnt) - 1)]);
	}
	return 0;
}
